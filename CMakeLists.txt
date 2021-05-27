cmake_minimum_required(VERSION 3.20.0)
project(opengl VERSION 0.1.0)

# include()
# enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow")
include(CPack)

include_directories(include)

if($ENV{XDG_SESSION_TYPE} STREQUAL "wayland")
set(GLFW_USE_WAYLAND 1)
endif()

# include(CheckIncludeFile)
# include(CheckIncludeFileCXX)
# include(CheckIncludeFiles)
# include(ExternalProject)
# include(libs/glew.cmake)

add_subdirectory(libs)
include_directories(
    include
    vendor/glew_2.2/include
)

link_directories(
    vendor/glew_2.2/lib
)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
    glfw
    GL
    GLEW
)

