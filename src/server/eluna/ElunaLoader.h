/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* Copyright (C) 2022 - 2022 Hour of Twilight <https://www.houroftwilight.net/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _ELUNALOADER_H
#define _ELUNALOADER_H

#include "LuaEngine.h"

#include <unordered_map>
#include <ctime>
#include <algorithm>

#if defined ELUNA_TRINITY && defined(TRACKABLE_PTR_NAMESPACE)
#include <efsw/efsw.hpp>
#endif

extern "C"
{
#include "lua.h"
};

enum ElunaReloadActions
{
    RELOAD_CACHE_ONLY   = -3,
    RELOAD_ALL_STATES   = -2,
    RELOAD_GLOBAL_STATE = -1
};

enum ElunaScriptCacheState
{
    SCRIPT_CACHE_NONE = 0,
    SCRIPT_CACHE_REINIT = 1,
    SCRIPT_CACHE_LOADING = 2,
    SCRIPT_CACHE_READY = 3
};

struct LuaScript;

class ElunaLoader
{
private:
    ElunaLoader();
    ~ElunaLoader();

public:
    ElunaLoader(ElunaLoader const&) = delete;
    ElunaLoader(ElunaLoader&&) = delete;

    ElunaLoader& operator= (ElunaLoader const&) = delete;
    ElunaLoader& operator= (ElunaLoader&&) = delete;
    static ElunaLoader* instance();

    void LoadScripts();
    void ReloadElunaForMap(int mapId);
    void CheckForScriptChanges();

    uint8 GetCacheState() const { return m_cacheState; }
    const std::vector<LuaScript>& GetLuaScripts() const { return m_scriptCache; }
    const std::string& GetRequirePath() const { return m_requirePath; }
    const std::string& GetRequireCPath() const { return m_requirecPath; }

#if defined ELUNA_TRINITY && defined(TRACKABLE_PTR_NAMESPACE)
    // efsw file watcher
    void InitializeFileWatcher();
    efsw::FileWatcher lua_fileWatcher;
    efsw::WatchID lua_scriptWatcher;
#endif

private:
    void ReloadScriptCache();
    void ReadFiles(lua_State* L, std::string path);
    void CombineLists();
    void ProcessScript(lua_State* L, std::string filename, const size_t& filesize, const std::string& fullpath, int32 mapId);
    bool CompileScript(lua_State* L, LuaScript& script);
    static int LoadBytecodeChunk(lua_State* L, uint8* bytes, size_t len, BytecodeBuffer* buffer);

    std::atomic<uint8> m_cacheState;
    std::vector<LuaScript> m_scriptCache;
    std::string m_requirePath;
    std::string m_requirecPath;
    std::list<LuaScript> m_scripts;
    std::list<LuaScript> m_extensions;
    std::thread m_reloadThread;
    std::unordered_map<std::string, std::time_t> m_fileTimestamps;
};

#if defined ELUNA_TRINITY && defined(TRACKABLE_PTR_NAMESPACE)
/// File watcher responsible for watching lua scripts
class ElunaUpdateListener : public efsw::FileWatchListener
{
public:
    ElunaUpdateListener() { }
    virtual ~ElunaUpdateListener() { }

    void handleFileAction(efsw::WatchID /*watchid*/, std::string const& dir,
        std::string const& filename, efsw::Action /*action*/, std::string oldFilename = "") final override;
};

static ElunaUpdateListener elunaUpdateListener;
#endif

#define sElunaLoader ElunaLoader::instance()

#endif
