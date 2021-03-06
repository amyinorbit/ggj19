cmake_minimum_required(VERSION 3.2)
project(ggj19 VERSION 3.0 LANGUAGES CXX C)

# set(DEV_VERSION_POSTFIX "-dr3")

# if(CMAKE_BUILD_TYPE MATCHES RELEASE)
# 	set(PROJECT_VERSION "${PROJECT_VERSION}")
# 	message("Debug Mode")
# else()
# 	set(PROJECT_VERSION "${PROJECT_VERSION}${DEV_VERSION_POSTFIX}")
# 	message("Release Mode")
# endif()
	

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
