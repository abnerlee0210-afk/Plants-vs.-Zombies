cmake_minimum_required(VERSION 3.16)
project(REPLACE_WITH_YOUR_PROJECT_NAME)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    ptsd

    URL         https://github.com/ntut-open-source-club/practical-tools-for-simple-design/archive/refs/tags/v0.2.zip

    # Or alternatively if you want to use a specific git commit instead of a release:
    # GIT_REPOSITORY  https://github.com/ntut-open-source-club/practical-tools-for-simple-design.git
    # GIT_TAG         <git_tag>

    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/PTSD
)

FetchContent_MakeAvailable(ptsd)

include(files.cmake)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)

# file(GLOB_RECURSE SRC_FILES src/*)
# file(GLOB_RECURSE HEADER_FILES include/*)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/main.cpp
    ${SRC_FILES}
    ${HEADER_FILES}
        include/Board/GameBoard.hpp
        src/Board/GameBoard.cpp
        include/Scene/GameScene.hpp
        src/Scene/GameScene.cpp
        include/Entity/Plant.hpp
        src/Entity/Plant.cpp
        include/Entity/Peashooter.hpp
        src/Entity/Peashooter.cpp
        include/Entity/Zombie.hpp
        src/Entity/Zombie.cpp
        include/Entity/BasicZombie.hpp
        src/Entity/BasicZombie.cpp
        include/Entity/Projectile.hpp
        src/Entity/Projectile.cpp
        include/Entity/Pea.hpp
        src/Entity/Pea.cpp
        include/Entity/Sunflower.hpp
        src/Entity/Sunflower.cpp
        include/Entity/Sun.hpp
        src/Entity/Sun.cpp
        include/UI/SeedCard.hpp
        src/UI/SeedCard.cpp
        include/UI/ShovelButton.hpp
        src/UI/ShovelButton.cpp
        include/Entity/LawnMower.hpp
        src/Entity/LawnMower.cpp
        include/Entity/CherryBomb.hpp
        src/Entity/CherryBomb.cpp
        include/Level/LevelData.hpp
        include/Entity/ConeheadZombie.hpp
        src/Entity/ConeheadZombie.cpp
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    message(FATAL_ERROR "relative RESOURCE_DIR is WIP, Please use `-DCMAKE_BUILD_TYPE=Debug` build for now.")
    # target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2main
    PTSD
)
