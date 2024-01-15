cmake_minimum_required(VERSION 3.27)
project(Hackathon LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# Fetch SFML from the official repository
FetchContent_Declare(
    SFML
    GIT_REPOSITORY git@github.com:SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

add_subdirectory(src/HackathonExe)
add_subdirectory(src/HackathonLib)

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/bin)