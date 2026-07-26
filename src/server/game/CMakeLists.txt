# Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent implied by the law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Suppress C4828: invalid character in source charset (GBK characters in UTF-8 files)
if(MSVC)
  add_compile_options(/wd4828)
endif()

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBot
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI)

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

if (PLAYERBOT)
  # PlayerBot 核心模块
  file(GLOB PLAYERBOT_CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBot/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBot/*.h)
  list(APPEND PRIVATE_SOURCES ${PLAYERBOT_CORE_SOURCES})

  # Server 扩展（PlayerBotSession + OnlineMgr）
  list(APPEND PRIVATE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/PlayerBotSession.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/PlayerBotSession.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/OnlineMgr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/OnlineMgr.h)

  message(STATUS "PlayerBot core module: ENABLED (sources added)")

  if (PLAYERBOT_AI)
    # AI 系统根目录
    file(GLOB PLAYERBOT_AI_ROOT_SOURCES
      ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI/*.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI/*.h)
    list(APPEND PRIVATE_SOURCES ${PLAYERBOT_AI_ROOT_SOURCES})

    # AI 子目录
    foreach(AI_SUBDIR BotFieldAI BotGroupAI BotDuelAI BotArenaAI BotClassAI)
      file(GLOB PLAYERBOT_AI_SUB_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI/${AI_SUBDIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI/${AI_SUBDIR}/*.h)
      list(APPEND PRIVATE_SOURCES ${PLAYERBOT_AI_SUB_SOURCES})
    endforeach()

    message(STATUS "PlayerBot AI system: ENABLED (sources added)")
  else()
    message(STATUS "PlayerBot AI system: DISABLED")
  endif()
endif()

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

if (PLAYERBOT)
  target_compile_definitions(game PRIVATE PLAYERBOT)
  if (PLAYERBOT_AI)
    target_compile_definitions(game PRIVATE PLAYERBOT_AI)
  endif()
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
