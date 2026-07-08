# Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent implied by the law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

set(ELUNA_DIR ${CMAKE_SOURCE_DIR}/src/server/eluna)

if (ELUNA)
  # Add Eluna source files to the game library
  file(GLOB_RECURSE ELUNA_SOURCES
    ${ELUNA_DIR}/*.cpp
    ${ELUNA_DIR}/*.h
    ${ELUNA_DIR}/*.hpp)
  list(APPEND PRIVATE_SOURCES ${ELUNA_SOURCES})
endif()

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
    ${CMAKE_CURRENT_BINARY_DIR})

if (ELUNA)
  target_include_directories(game PRIVATE ${ELUNA_DIR})
  target_include_directories(game PRIVATE ${ELUNA_DIR}/hooks)
  target_include_directories(game PRIVATE ${ELUNA_DIR}/methods/TrinityCore)
  target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/dep/lua52/src)
endif()

target_link_libraries(game
  PRIVATE
    trinity-core-interface
  PUBLIC
    shared
    Detour)

if (ELUNA)
  target_compile_definitions(game PRIVATE ELUNA_TRINITY)
  target_compile_definitions(game PRIVATE ELUNA_EXPANSION=EXP_RETAIL)
  target_link_libraries(game PRIVATE lua52)
  set_property(TARGET game PROPERTY CXX_STANDARD 17)
endif()

set_target_properties(game
    PROPERTIES
      FOLDER
        "server")

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(game ${PRIVATE_PCH_HEADER})
endif ()
