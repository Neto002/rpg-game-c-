cmake_minimum_required(VERSION 3.28)
project(rpg-game LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Window SFML::Audio)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode ON")
    target_compile_definitions(main PRIVATE DEBUG_MODE=1)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release mode ON")
    target_compile_definitions(main PRIVATE NDEBUG)
endif()
