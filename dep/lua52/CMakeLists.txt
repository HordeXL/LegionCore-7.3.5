# Lua 5.2.4 static library for Eluna

file(GLOB Lua_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

add_library(lua52 STATIC ${Lua_SOURCES})

target_include_directories(lua52
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Disable some MSVC warnings for Lua
if(MSVC)
  target_compile_options(lua52 PRIVATE /wd4996 /wd4244 /wd4267)
endif()

set_target_properties(lua52
  PROPERTIES
    FOLDER "dep"
)
