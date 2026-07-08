# Build Lua 5.2 as a static library for Eluna embedding

set(LUA_SOURCES
    src/lapi.c
    src/lauxlib.c
    src/lbaselib.c
    src/lbitlib.c
    src/lcode.c
    src/lcorolib.c
    src/lctype.c
    src/ldblib.c
    src/ldebug.c
    src/ldo.c
    src/ldump.c
    src/lfunc.c
    src/lgc.c
    src/linit.c
    src/liolib.c
    src/llex.c
    src/lmathlib.c
    src/lmem.c
    src/loadlib.c
    src/lobject.c
    src/lopcodes.c
    src/loslib.c
    src/lparser.c
    src/lstate.c
    src/lstring.c
    src/lstrlib.c
    src/ltable.c
    src/ltablib.c
    src/ltm.c
    src/lundump.c
    src/lvm.c
    src/lzio.c
)

set(LUA_HEADERS
    src/lapi.h
    src/lauxlib.h
    src/lcode.h
    src/lctype.h
    src/ldebug.h
    src/ldo.h
    src/lfunc.h
    src/lgc.h
    src/llex.h
    src/llimits.h
    src/lmem.h
    src/lobject.h
    src/lopcodes.h
    src/lparser.h
    src/lstate.h
    src/lstring.h
    src/ltable.h
    src/ltm.h
    src/lua.h
    src/lua.hpp
    src/luaconf.h
    src/lualib.h
    src/lundump.h
    src/lvm.h
    src/lzio.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(lua52 STATIC ${LUA_SOURCES} ${LUA_HEADERS})

set_target_properties(lua52
    PROPERTIES
    FOLDER "dep"
)
