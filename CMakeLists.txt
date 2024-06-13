cmake_minimum_required(VERSION 3.0)
project(MyGLFWProject)

set(TEST_PUBLIC_INCLUDES
    test/include/game.hpp
    test/include/shader.hpp
    test/include/texture.hpp
    test/include/resource_manager.hpp
    test/include/stb_image.hpp
    test/include/sprite_renderer.hpp
    test/include/game_object.hpp
    test/include/game_level.hpp
    test/include/ball_object.hpp
    test/include/particle_generator.hpp
)

set(TEST_PUBLIC_SOURCES
	test/src/game.cpp
    test/src/shader.cpp
    test/src/texture.cpp
    test/src/resource_manager.cpp
    test/src/stb_image.cpp
    test/src/main.cpp
    test/src/sprite_renderer.cpp
    test/src/game_object.cpp
    test/src/game_level.cpp
    test/src/ball_object.cpp
    test/src/particle_generator.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test/include)

add_executable(MyGLFWProject
	${TEST_PUBLIC_INCLUDES}
	${TEST_PUBLIC_SOURCES}
)

file(GLOB_RECURSE RESOURCES RELATIVE ${CMAKE_SOURCE_DIR} "resources/*")
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)
execute_process(
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_subdirectory(external/glfw)
target_link_libraries(MyGLFWProject PUBLIC glfw)

add_subdirectory(external/glad)
target_link_libraries(MyGLFWProject PUBLIC glad)

add_subdirectory(external/glm)
target_link_libraries(MyGLFWProject PUBLIC glm)
