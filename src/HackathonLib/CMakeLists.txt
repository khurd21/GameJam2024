set(lib_name HackathonLib)

set(sources
    Objects/Character.cpp
    Objects/Wall.cpp
    Objects/Token.cpp
    Game.cpp
    PixelPerfectDetection.cpp
    Runners/GameRunner.cpp
    Runners/Scores.cpp
    Runners/Instructions.cpp
    )

set(include_dir ${PROJECT_SOURCE_DIR}/include)
set(lib_dir ${include_dir}/HackathonLib)
set(includes
    ${lib_dir}/Objects/IObject.hpp
    ${lib_dir}/Objects/Wall.hpp
    ${lib_dir}/Objects/Character.hpp
    ${lib_dir}/Objects/Token.hpp
    ${lib_dir}/Game.hpp
    ${lib_dir}/Type.hpp
    ${lib_dir}/Textures.hpp
    ${lib_dir}/PixelPerfectDetection.hpp
    ${lib_dir}/Runners/GameRunner.hpp
    ${lib_dir}/Runners/IRunner.hpp
    ${lib_dir}/Runners/ScoreRunner.hpp
    ${lib_dir}/Runners/InstructRunner.hpp
    )

add_library(${lib_name} ${sources} ${includes})
add_library(${PROJECT_NAME}::${lib_name} ALIAS ${lib_name})

target_include_directories(${lib_name} PRIVATE ${include_dir})
target_include_directories(${lib_name} PRIVATE ${SFML_INCLUDE_DIRS})

target_link_libraries(${lib_name} PRIVATE
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network)
