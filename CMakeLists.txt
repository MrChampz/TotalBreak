cmake_minimum_required(VERSION 3.6)
project(TotalBreak)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -fpermissive")

find_package(PkgConfig REQUIRED)

#OPENGL
find_package(OpenGL REQUIRED)

#GLFW
find_package(glfw3 REQUIRED)

#GLEW
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} Header/)
INCLUDE_DIRECTORIES(Dependencies/include/)

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

set(
        SOURCE_FILES
        Source/Program.cpp
        Source/Game.cpp Header/Game.h
        Source/Shader.cpp Header/Shader.h
        Source/Texture.cpp Header/Texture.h
        Source/ResourceManager.cpp Header/ResourceManager.h
        Source/SpriteRenderer.cpp Header/SpriteRenderer.h
        Source/GameObject.cpp Header/GameObject.h
        )

add_executable(TotalBreak ${SOURCE_FILES})
target_link_libraries (TotalBreak ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES}  ${GLEW_LIBRARIES} GL glfw GLEW SOIL)