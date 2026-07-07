#include "ElunaCompat.h"
#include "ElunaConfig.h"
#include "ElunaLoader.h"
#include "ElunaMgr.h"
#include "ElunaUtility.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#ifdef ELUNA_WINDOWS
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#endif

ElunaLoader::ElunaLoader() : m_cacheState(SCRIPT_CACHE_NONE) { }
ElunaLoader::~ElunaLoader() { }

ElunaLoader* ElunaLoader::instance()
{
    static ElunaLoader instance;
    return &instance;
}

void ElunaLoader::LoadScripts()
{
    // Initialize Eluna config
    sElunaConfig->Initialize();

    if (!sElunaConfig->IsElunaEnabled())
    {
        ELUNA_LOG_INFO("[Eluna]: Eluna is disabled. Skipping script loading.");
        m_cacheState = SCRIPT_CACHE_READY;
        return;
    }

    ELUNA_LOG_INFO("[Eluna]: Loading Eluna scripts...");
    uint32 oldMSTime = ElunaUtil::GetCurrTime();

    m_cacheState = SCRIPT_CACHE_LOADING;

    // Clear previous scripts
    m_scripts.clear();
    m_extensions.clear();
    m_scriptCache.clear();

    // Create temporary Lua state for compilation
    lua_State* L = luaL_newstate();
    if (!L)
    {
        ELUNA_LOG_ERROR("[Eluna]: Failed to create Lua state for script compilation.");
        m_cacheState = SCRIPT_CACHE_NONE;
        return;
    }
    luaL_openlibs(L);

    // Set up require paths
    std::string scriptPath = sElunaConfig->GetConfig(CONFIG_ELUNA_SCRIPT_PATH);
    m_requirePath = scriptPath + "/?.lua";
    std::string extraPath = sElunaConfig->GetConfig(CONFIG_ELUNA_REQUIRE_PATH_EXTRA);
    if (!extraPath.empty())
        m_requirePath = m_requirePath + ";" + extraPath;

    m_requirecPath = "/?.dll";
    std::string extraCPath = sElunaConfig->GetConfig(CONFIG_ELUNA_REQUIRE_CPATH_EXTRA);
    if (!extraCPath.empty())
        m_requirecPath = m_requirecPath + ";" + extraCPath;

    // Read scripts from directory
    ReadFiles(L, scriptPath);

    // Combine lists into script cache
    CombineLists();

    // Close temporary Lua state
    lua_close(L);

    m_cacheState = SCRIPT_CACHE_READY;

    // Create global Eluna instance to load scripts into Lua VM
    ElunaInfo globalInfo(ElunaInfoKey::MakeGlobalKey(0));
    sElunaMgr->Create(nullptr, globalInfo);

    ELUNA_LOG_INFO("[Eluna]: Loaded %zu Eluna scripts in %u ms", m_scriptCache.size(), ElunaUtil::GetTimeDiff(oldMSTime));
}

void ElunaLoader::ReloadElunaForMap(int /*mapId*/)
{
    ReloadScriptCache();
}

void ElunaLoader::ReloadScriptCache()
{
    m_cacheState = SCRIPT_CACHE_REINIT;
    m_cacheState = SCRIPT_CACHE_READY;
}

void ElunaLoader::ReadFiles(lua_State* L, std::string path)
{
    std::vector<std::string> files;
    std::vector<std::string> dirs;

#ifdef ELUNA_WINDOWS
    std::string searchPath = path + "/*.lua";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                files.push_back(findData.cFileName);
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }

    // Find subdirectories
    searchPath = path + "/*";
    hFind = FindFirstFileA(searchPath.c_str(), &findData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
                strcmp(findData.cFileName, ".") != 0 &&
                strcmp(findData.cFileName, "..") != 0)
            {
                dirs.push_back(findData.cFileName);
            }
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
#else
    DIR* dir = opendir(path.c_str());
    if (!dir)
    {
        ELUNA_LOG_ERROR("[Eluna]: Could not open scripts directory: %s", path.c_str());
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL)
    {
        std::string name = entry->d_name;
        if (name == "." || name == "..")
            continue;

        std::string fullPath = path + "/" + name;
        struct stat statBuf;
        if (stat(fullPath.c_str(), &statBuf) != 0)
            continue;

        if (S_ISDIR(statBuf.st_mode))
        {
            dirs.push_back(name);
        }
        else if (name.size() > 4 && name.substr(name.size() - 4) == ".lua")
        {
            files.push_back(name);
        }
    }
    closedir(dir);
#endif

    // Process .lua files
    for (auto const& file : files)
    {
        std::string fullPath = path + "/" + file;
        std::ifstream inFile(fullPath, std::ios::binary | std::ios::ate);
        if (!inFile)
        {
            ELUNA_LOG_ERROR("[Eluna]: Could not open script file: %s", fullPath.c_str());
            continue;
        }

        size_t fileSize = static_cast<size_t>(inFile.tellg());
        if (fileSize == 0)
        {
            ELUNA_LOG_DEBUG("[Eluna]: Skipping empty script: %s", fullPath.c_str());
            continue;
        }

        ProcessScript(L, file, fileSize, fullPath, -1);
    }

    // Recurse into subdirectories
    for (auto const& dir : dirs)
    {
        std::string subPath = path + "/" + dir;
        ReadFiles(L, subPath);
    }
}

void ElunaLoader::CombineLists()
{
    m_scriptCache.clear();
    m_scriptCache.reserve(m_scripts.size() + m_extensions.size());

    // Scripts first, then extensions (extensions override scripts)
    for (auto const& script : m_scripts)
        m_scriptCache.push_back(script);
    for (auto const& ext : m_extensions)
        m_scriptCache.push_back(ext);
}

void ElunaLoader::ProcessScript(lua_State* L, std::string filename, const size_t& /*filesize*/, const std::string& fullpath, int32 mapId)
{
    LuaScript script;
    script.filename = filename;
    script.filepath = fullpath;
    script.mapId = mapId;

    if (!CompileScript(L, script))
    {
        ELUNA_LOG_ERROR("[Eluna]: Failed to compile script: %s", fullpath.c_str());
        return;
    }

    // Check if filename starts with "ext_" or "extension_" to categorize
    std::string lowerName = filename;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    if (lowerName.find("ext_") == 0 || lowerName.find("extension_") == 0)
    {
        // Determine module path from filename
        script.modulepath = fullpath;
        m_extensions.push_back(std::move(script));
    }
    else
    {
        m_scripts.push_back(std::move(script));
    }
}

bool ElunaLoader::CompileScript(lua_State* L, LuaScript& script)
{
    // Read file contents
    std::ifstream file(script.filepath, std::ios::binary);
    if (!file)
        return false;

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Compile the Lua code into bytecode
    if (luaL_loadbuffer(L, content.c_str(), content.size(), script.filename.c_str()) != 0)
    {
        ELUNA_LOG_ERROR("[Eluna]: Compile error in %s: %s", script.filepath.c_str(), lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }

    // Get the compiled bytecode
    lua_dump(L, LoadBytecodeChunk, &script.bytecode);
    lua_pop(L, 1); // pop the loaded function

    return !script.bytecode.empty();
}

int ElunaLoader::LoadBytecodeChunk(lua_State* /*L*/, const void* p, size_t sz, void* ud)
{
    BytecodeBuffer* buffer = static_cast<BytecodeBuffer*>(ud);
    uint8 const* bytes = static_cast<uint8 const*>(p);
    buffer->insert(buffer->end(), bytes, bytes + sz);
    return 0;
}
