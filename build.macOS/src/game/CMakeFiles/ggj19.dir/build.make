# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amy/workspace/gamedev/ggj19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amy/workspace/gamedev/ggj19/build.macOS

# Include any dependencies generated for this target.
include src/game/CMakeFiles/ggj19.dir/depend.make

# Include the progress variables for this target.
include src/game/CMakeFiles/ggj19.dir/progress.make

# Include the compile flags for this target's objects.
include src/game/CMakeFiles/ggj19.dir/flags.make

src/game/CMakeFiles/ggj19.dir/font.c.o: src/game/CMakeFiles/ggj19.dir/flags.make
src/game/CMakeFiles/ggj19.dir/font.c.o: ../src/game/font.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.macOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/game/CMakeFiles/ggj19.dir/font.c.o"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ggj19.dir/font.c.o   -c /Users/amy/workspace/gamedev/ggj19/src/game/font.c

src/game/CMakeFiles/ggj19.dir/font.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ggj19.dir/font.c.i"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/amy/workspace/gamedev/ggj19/src/game/font.c > CMakeFiles/ggj19.dir/font.c.i

src/game/CMakeFiles/ggj19.dir/font.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ggj19.dir/font.c.s"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/amy/workspace/gamedev/ggj19/src/game/font.c -o CMakeFiles/ggj19.dir/font.c.s

src/game/CMakeFiles/ggj19.dir/main.cpp.o: src/game/CMakeFiles/ggj19.dir/flags.make
src/game/CMakeFiles/ggj19.dir/main.cpp.o: ../src/game/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.macOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/game/CMakeFiles/ggj19.dir/main.cpp.o"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ggj19.dir/main.cpp.o -c /Users/amy/workspace/gamedev/ggj19/src/game/main.cpp

src/game/CMakeFiles/ggj19.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ggj19.dir/main.cpp.i"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amy/workspace/gamedev/ggj19/src/game/main.cpp > CMakeFiles/ggj19.dir/main.cpp.i

src/game/CMakeFiles/ggj19.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ggj19.dir/main.cpp.s"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amy/workspace/gamedev/ggj19/src/game/main.cpp -o CMakeFiles/ggj19.dir/main.cpp.s

src/game/CMakeFiles/ggj19.dir/driver.cpp.o: src/game/CMakeFiles/ggj19.dir/flags.make
src/game/CMakeFiles/ggj19.dir/driver.cpp.o: ../src/game/driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.macOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/game/CMakeFiles/ggj19.dir/driver.cpp.o"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ggj19.dir/driver.cpp.o -c /Users/amy/workspace/gamedev/ggj19/src/game/driver.cpp

src/game/CMakeFiles/ggj19.dir/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ggj19.dir/driver.cpp.i"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amy/workspace/gamedev/ggj19/src/game/driver.cpp > CMakeFiles/ggj19.dir/driver.cpp.i

src/game/CMakeFiles/ggj19.dir/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ggj19.dir/driver.cpp.s"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amy/workspace/gamedev/ggj19/src/game/driver.cpp -o CMakeFiles/ggj19.dir/driver.cpp.s

src/game/CMakeFiles/ggj19.dir/sdlio.cpp.o: src/game/CMakeFiles/ggj19.dir/flags.make
src/game/CMakeFiles/ggj19.dir/sdlio.cpp.o: ../src/game/sdlio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.macOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/game/CMakeFiles/ggj19.dir/sdlio.cpp.o"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ggj19.dir/sdlio.cpp.o -c /Users/amy/workspace/gamedev/ggj19/src/game/sdlio.cpp

src/game/CMakeFiles/ggj19.dir/sdlio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ggj19.dir/sdlio.cpp.i"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amy/workspace/gamedev/ggj19/src/game/sdlio.cpp > CMakeFiles/ggj19.dir/sdlio.cpp.i

src/game/CMakeFiles/ggj19.dir/sdlio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ggj19.dir/sdlio.cpp.s"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amy/workspace/gamedev/ggj19/src/game/sdlio.cpp -o CMakeFiles/ggj19.dir/sdlio.cpp.s

src/game/CMakeFiles/ggj19.dir/ggj19.cpp.o: src/game/CMakeFiles/ggj19.dir/flags.make
src/game/CMakeFiles/ggj19.dir/ggj19.cpp.o: ../src/game/ggj19.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.macOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/game/CMakeFiles/ggj19.dir/ggj19.cpp.o"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ggj19.dir/ggj19.cpp.o -c /Users/amy/workspace/gamedev/ggj19/src/game/ggj19.cpp

src/game/CMakeFiles/ggj19.dir/ggj19.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ggj19.dir/ggj19.cpp.i"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amy/workspace/gamedev/ggj19/src/game/ggj19.cpp > CMakeFiles/ggj19.dir/ggj19.cpp.i

src/game/CMakeFiles/ggj19.dir/ggj19.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ggj19.dir/ggj19.cpp.s"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amy/workspace/gamedev/ggj19/src/game/ggj19.cpp -o CMakeFiles/ggj19.dir/ggj19.cpp.s

# Object files for target ggj19
ggj19_OBJECTS = \
"CMakeFiles/ggj19.dir/font.c.o" \
"CMakeFiles/ggj19.dir/main.cpp.o" \
"CMakeFiles/ggj19.dir/driver.cpp.o" \
"CMakeFiles/ggj19.dir/sdlio.cpp.o" \
"CMakeFiles/ggj19.dir/ggj19.cpp.o"

# External object files for target ggj19
ggj19_EXTERNAL_OBJECTS =

src/game/ggj19: src/game/CMakeFiles/ggj19.dir/font.c.o
src/game/ggj19: src/game/CMakeFiles/ggj19.dir/main.cpp.o
src/game/ggj19: src/game/CMakeFiles/ggj19.dir/driver.cpp.o
src/game/ggj19: src/game/CMakeFiles/ggj19.dir/sdlio.cpp.o
src/game/ggj19: src/game/CMakeFiles/ggj19.dir/ggj19.cpp.o
src/game/ggj19: src/game/CMakeFiles/ggj19.dir/build.make
src/game/ggj19: src/house/libHouse.a
src/game/ggj19: src/language/libLanguage.a
src/game/ggj19: src/game/CMakeFiles/ggj19.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.macOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ggj19"
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ggj19.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/game/CMakeFiles/ggj19.dir/build: src/game/ggj19

.PHONY : src/game/CMakeFiles/ggj19.dir/build

src/game/CMakeFiles/ggj19.dir/clean:
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game && $(CMAKE_COMMAND) -P CMakeFiles/ggj19.dir/cmake_clean.cmake
.PHONY : src/game/CMakeFiles/ggj19.dir/clean

src/game/CMakeFiles/ggj19.dir/depend:
	cd /Users/amy/workspace/gamedev/ggj19/build.macOS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amy/workspace/gamedev/ggj19 /Users/amy/workspace/gamedev/ggj19/src/game /Users/amy/workspace/gamedev/ggj19/build.macOS /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game /Users/amy/workspace/gamedev/ggj19/build.macOS/src/game/CMakeFiles/ggj19.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/game/CMakeFiles/ggj19.dir/depend
