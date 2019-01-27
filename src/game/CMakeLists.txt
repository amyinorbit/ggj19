add_executable(ggj19 font.c main.cpp driver.cpp sdlio.cpp ggj19.cpp ${STORY_FILES})
target_link_libraries(ggj19 House)
target_link_libraries(ggj19 Language)
target_link_libraries(ggj19 ${SDL2_LIBRARIES})

IF(APPLE)
	set_target_properties(ggj19 PROPERTIES
		MACOSX_BUNDLE TRUE
		MACOSX_BUNDLE_GUI_IDENTIFIER com.idsmlmgames.alive
		MACOSX_BUNDLE_BUNDLE_NAME "GGJ19 - Alive"
		MACOSX_BUNDLE_COPYRIGHT "(c) 2019 IDSMLM Games, Emma Rydstrom and Amy Parent"
		# RESOURCE "${STORY_FILES}"
	)
	add_custom_command(TARGET ggj19 PRE_BUILD
	                   COMMAND ${CMAKE_COMMAND} -E copy_directory
	                       "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:ggj19>/../Resources")
ELSE()
	set_target_properties(ggj19 PROPERTIES
		WIN32 TRUE
	)
	add_custom_command(TARGET ggj19 PRE_BUILD
	                   COMMAND ${CMAKE_COMMAND} -E copy_directory
	                       "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:ggj19>/assets")
ENDIF()