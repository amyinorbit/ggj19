add_executable(ggj19 font.c main.cpp driver.cpp sdlio.cpp ggj19.cpp)
target_link_libraries(ggj19 House)
target_link_libraries(ggj19 Language)
target_link_libraries(ggj19 ${SDL2_LIBRARIES})
