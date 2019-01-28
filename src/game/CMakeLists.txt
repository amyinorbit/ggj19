add_executable(alive MACOSX_BUNDLE WIN32 font.c main.cpp driver.cpp sdlio.cpp ggj19.cpp ${STORY_FILES})
target_link_libraries(alive House)
target_link_libraries(alive Language)
target_link_libraries(alive ${SDL2_LIBRARIES})

IF(APPLE)
	set_target_properties(alive PROPERTIES
		MACOSX_BUNDLE_GUI_IDENTIFIER com.idsmlmgames.alive
		MACOSX_BUNDLE_BUNDLE_NAME "GGJ19 - Alive"
		MACOSX_BUNDLE_COPYRIGHT "(c) 2019 IDSMLM Games, Emma Rydstrom and Amy Parent"
	)
	add_custom_command(TARGET alive PRE_BUILD
	                   COMMAND ${CMAKE_COMMAND} -E copy_directory
	                       "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:alive>/../Resources")
ELSE()
	add_custom_command(TARGET alive PRE_BUILD
	                   COMMAND ${CMAKE_COMMAND} -E copy_directory
	                       "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:alive>/assets")
ENDIF()
