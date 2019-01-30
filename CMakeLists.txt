cmake_minimum_required(VERSION 3.2)
project(ggj19 VERSION 1.0 LANGUAGES CXX C)

include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE STORY_FILES ${PROJECT_SOURCE_DIR}/assets/*)

set(PRODUCT_DIR "${CMAKE_SOURCE_DIR}/product")
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(CMAKE_INSTALL_PREFIX ${PRODUCT_DIR})

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

include_directories(include ${SDL2_INCLUDE_DIRS})
link_directories("${LINK_DIRECTORIES}" "${SDL2_LIBDIR}")
add_subdirectory(src)

add_custom_target(run
    COMMAND alive
    DEPENDS alive
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
