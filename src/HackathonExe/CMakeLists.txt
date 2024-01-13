set(exe_name HackathonExe)

set(sources
    main.cpp)

set(includes
    )

add_executable(${exe_name} ${sources} ${includes})

target_include_directories(${exe_name} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${exe_name} PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(${exe_name} PRIVATE
    HackathonLib
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network)