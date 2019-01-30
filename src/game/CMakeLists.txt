add_executable(alive MACOSX_BUNDLE WIN32 font.c main.cpp driver.cpp sdlio.cpp ggj19.cpp ${STORY_FILES})
target_link_libraries(alive House)
target_link_libraries(alive Language)
target_link_libraries(alive ${SDL2_LIBRARIES})
install(TARGETS alive DESTINATION ${CMAKE_SYSTEM_NAME})

IF(APPLE)
	set_target_properties(alive PROPERTIES
		MACOSX_BUNDLE_GUI_IDENTIFIER com.idsmlmgames.alive
		MACOSX_BUNDLE_BUNDLE_NAME "GGJ19 - Alive"
		MACOSX_BUNDLE_COPYRIGHT "Copyright (c) 2019 IDSMLM Games, Emma Rydstrom and Amy Parent"
  	  	MACOSX_BUNDLE_GUI_IDENTIFIER "com.idsmlmgames.alive"
		MACOSX_BUNDLE_SHORT_VERSION_STRING "3dr2"
		MACOSX_BUNDLE_BUNDLE_VERSION "1"
  		MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/info.plist.in"
	)
	add_custom_command(TARGET alive PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
	    "${ASSETS_DIR}" "$<TARGET_FILE_DIR:alive>/../Resources"
	)
	install(CODE "
	   include(BundleUtilities)
	   fixup_bundle(${CMAKE_INSTALL_PREFIX}/${CMAKE_SYSTEM_NAME}/alive.app \"\" \"${CMAKE_SOURCE_DIR}/assets\")
	   " COMPONENT Runtime
   )
						   
ELSE()
	add_custom_command(TARGET alive PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
	    "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:alive>/assets"
	)
	install(DIRECTORY "${ASSETS_DIR}"
		DESTINATION "${CMAKE_INSTALL_PREFIX}/${CMAKE_SYSTEM_NAME}")
					
ENDIF()

