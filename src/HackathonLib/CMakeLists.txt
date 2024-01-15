set(lib_name HackathonLib)

set(sources
    main.cpp
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

add_executable(${lib_name} ${sources} ${includes})

target_include_directories(${lib_name} PRIVATE ${include_dir})
target_include_directories(${lib_name} PRIVATE ${SFML_INCLUDE_DIRS})

target_link_libraries(${lib_name} PRIVATE
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network)

if(WIN32)
    add_custom_command(
        TARGET ${lib_name}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${lib_name}>
        VERBATIM)
endif()

install(TARGETS ${lib_name})