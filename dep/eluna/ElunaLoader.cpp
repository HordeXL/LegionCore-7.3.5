#include "ElunaCompat.h"
#include "ElunaConfig.h"
#include "ElunaLoader.h"
#include "ElunaUtility.h"

ElunaLoader::ElunaLoader() : m_cacheState(SCRIPT_CACHE_NONE) { }
ElunaLoader::~ElunaLoader() { }

ElunaLoader* ElunaLoader::instance()
{
    static ElunaLoader instance;
    return &instance;
}

void ElunaLoader::LoadScripts() { }
void ElunaLoader::ReloadElunaForMap(int mapId) { }

void ElunaLoader::ReloadScriptCache() { m_cacheState = SCRIPT_CACHE_READY; }

void ElunaLoader::ReadFiles(lua_State* L, std::string path) { }

void ElunaLoader::CombineLists() { }

void ElunaLoader::ProcessScript(lua_State* L, std::string filename, const size_t& filesize, const std::string& fullpath, int32 mapId) { }

bool ElunaLoader::CompileScript(lua_State* L, LuaScript& script) { return false; }

int ElunaLoader::LoadBytecodeChunk(lua_State* L, uint8* bytes, size_t len, BytecodeBuffer* buffer) { return 0; }
