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

# Add Eluna Lua Engine sources
file(GLOB_RECURSE ELUNA_SOURCES
  ${CMAKE_SOURCE_DIR}/dep/eluna/*.cpp
  ${CMAKE_SOURCE_DIR}/dep/eluna/hooks/*.cpp
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

target_compile_features(game PUBLIC cxx_std_17)

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
