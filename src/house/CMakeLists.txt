add_library(House STATIC lexer.cpp file.cpp utf8.c loader.cpp)
target_include_directories(House INTERFACE ${PROJECT_SOURCE_DIR}/include)
