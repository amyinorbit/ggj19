cmake_minimum_required(VERSION 3.2)
project(ggj19 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(FreeType 2.9 REQUIRED)
# find_package(glfw3 3.2 REQUIRED)
# find_package(OpenGL REQUIRED)

# include_directories(include ${OPENGL_INCLUDE_DIR})
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-exceptions -fno-rtti")

add_subdirectory(lib)
add_subdirectory(src)
