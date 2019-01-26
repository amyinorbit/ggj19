cmake_minimum_required(VERSION 3.2)
project(ggj19 VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# find_package(FreeType 2.9 REQUIRED)
# find_package(glfw3 3.2 REQUIRED)
# find_package(OpenGL REQUIRED)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(include)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-exceptions -fno-rtti")

add_subdirectory(src)
add_subdirectory(test)

add_custom_target(run
    COMMAND ggj19
    DEPENDS ggj19
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
