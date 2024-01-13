set(lib_name HackathonLib)

set(sources
    Character.cpp
    Game.cpp
    Wall.cpp
    Runners/GameRunner.cpp
    )

set(include_dir ${PROJECT_SOURCE_DIR}/include)
set(lib_dir ${include_dir}/HackathonLib)
set(includes
    ${lib_dir}/IObject.hpp
    ${lib_dir}/Character.hpp
    ${lib_dir}/Game.hpp
    ${lib_dir}/Wall.hpp
    ${lib_dir}/Type.hpp
    ${lib_dir}/Runners/GameRunner.hpp
    ${lib_dir}/Runners/IRunner.hpp
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
