add_library(Language STATIC lexer.cpp parser.cpp)
target_include_directories(Language INTERFACE ${PROJECT_SOURCE_DIR}/include)
