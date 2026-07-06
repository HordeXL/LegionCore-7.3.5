# Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

# Add Eluna Lua Engine sources (Phase A: only core files + ServerHooks)
file(GLOB ELUNA_SOURCES
  ${CMAKE_SOURCE_DIR}/dep/eluna/LuaValue.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/lmarshal.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/LuaEngine.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaConfig.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaEventMgr.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaUtility.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaTemplate.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaSpellWrapper.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaInstanceAI.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/ElunaLoader.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/hooks/ServerHooks.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/methods/Methods.cpp
)
list(APPEND PRIVATE_SOURCES ${ELUNA_SOURCES})

if (USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/gamePCH.h)
endif ()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(game
  ${PRIVATE_SOURCES}
)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(game
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/eluna
    ${CMAKE_SOURCE_DIR}/dep/eluna/hooks
    ${CMAKE_SOURCE_DIR}/dep/eluna/methods/TrinityCore
    ${CMAKE_SOURCE_DIR}/dep/lua52/src
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/src/common/Configuration
    ${CMAKE_SOURCE_DIR}/src/common/Database)

# LuaValue.cpp uses std::variant (C++17); other Eluna files compile at C++14 (default).
# Must disable PCH (/Y- on MSVC) to avoid "/std:c++" flag mismatch.
if(MSVC)
  set_source_files_properties(
    ${CMAKE_SOURCE_DIR}/dep/eluna/LuaValue.cpp
    PROPERTIES COMPILE_FLAGS "/std:c++17 /Y-")
else()
  set_source_files_properties(
    ${CMAKE_SOURCE_DIR}/dep/eluna/LuaValue.cpp
    PROPERTIES COMPILE_FLAGS "-std=c++17")
endif()

target_compile_definitions(game
  PRIVATE
    ELUNA_TRINITY
    ELUNA_EXPANSION=6
    TC_GAME_API=
)

target_link_libraries(game
  PRIVATE
    trinity-core-interface
    lua52
  PUBLIC
    shared
    Detour)

set_target_properties(game
    PROPERTIES
      FOLDER
        "server")

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(game ${PRIVATE_PCH_HEADER})
endif ()
