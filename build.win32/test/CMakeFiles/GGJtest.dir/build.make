# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Users/amy/toolchains/mxe/usr/x86_64-apple-darwin17.3.0/bin/cmake

# The command to remove a file.
RM = /Users/amy/toolchains/mxe/usr/x86_64-apple-darwin17.3.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amy/workspace/gamedev/ggj19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amy/workspace/gamedev/ggj19/build.win32

# Include any dependencies generated for this target.
include test/CMakeFiles/GGJtest.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/GGJtest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/GGJtest.dir/flags.make

test/CMakeFiles/GGJtest.dir/test.cpp.obj: test/CMakeFiles/GGJtest.dir/flags.make
test/CMakeFiles/GGJtest.dir/test.cpp.obj: test/CMakeFiles/GGJtest.dir/includes_CXX.rsp
test/CMakeFiles/GGJtest.dir/test.cpp.obj: ../test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.win32/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/GGJtest.dir/test.cpp.obj"
	cd /Users/amy/workspace/gamedev/ggj19/build.win32/test && /Users/amy/toolchains/mxe/usr/bin/i686-w64-mingw32.static-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GGJtest.dir/test.cpp.obj -c /Users/amy/workspace/gamedev/ggj19/test/test.cpp

test/CMakeFiles/GGJtest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GGJtest.dir/test.cpp.i"
	cd /Users/amy/workspace/gamedev/ggj19/build.win32/test && /Users/amy/toolchains/mxe/usr/bin/i686-w64-mingw32.static-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amy/workspace/gamedev/ggj19/test/test.cpp > CMakeFiles/GGJtest.dir/test.cpp.i

test/CMakeFiles/GGJtest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GGJtest.dir/test.cpp.s"
	cd /Users/amy/workspace/gamedev/ggj19/build.win32/test && /Users/amy/toolchains/mxe/usr/bin/i686-w64-mingw32.static-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amy/workspace/gamedev/ggj19/test/test.cpp -o CMakeFiles/GGJtest.dir/test.cpp.s

test/CMakeFiles/GGJtest.dir/test.cpp.obj.requires:

.PHONY : test/CMakeFiles/GGJtest.dir/test.cpp.obj.requires

test/CMakeFiles/GGJtest.dir/test.cpp.obj.provides: test/CMakeFiles/GGJtest.dir/test.cpp.obj.requires
	$(MAKE) -f test/CMakeFiles/GGJtest.dir/build.make test/CMakeFiles/GGJtest.dir/test.cpp.obj.provides.build
.PHONY : test/CMakeFiles/GGJtest.dir/test.cpp.obj.provides

test/CMakeFiles/GGJtest.dir/test.cpp.obj.provides.build: test/CMakeFiles/GGJtest.dir/test.cpp.obj


# Object files for target GGJtest
GGJtest_OBJECTS = \
"CMakeFiles/GGJtest.dir/test.cpp.obj"

# External object files for target GGJtest
GGJtest_EXTERNAL_OBJECTS =

test/GGJtest.exe: test/CMakeFiles/GGJtest.dir/test.cpp.obj
test/GGJtest.exe: test/CMakeFiles/GGJtest.dir/build.make
test/GGJtest.exe: src/language/libLanguage.a
test/GGJtest.exe: test/CMakeFiles/GGJtest.dir/linklibs.rsp
test/GGJtest.exe: test/CMakeFiles/GGJtest.dir/objects1.rsp
test/GGJtest.exe: test/CMakeFiles/GGJtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amy/workspace/gamedev/ggj19/build.win32/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GGJtest.exe"
	cd /Users/amy/workspace/gamedev/ggj19/build.win32/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GGJtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/GGJtest.dir/build: test/GGJtest.exe

.PHONY : test/CMakeFiles/GGJtest.dir/build

test/CMakeFiles/GGJtest.dir/requires: test/CMakeFiles/GGJtest.dir/test.cpp.obj.requires

.PHONY : test/CMakeFiles/GGJtest.dir/requires

test/CMakeFiles/GGJtest.dir/clean:
	cd /Users/amy/workspace/gamedev/ggj19/build.win32/test && $(CMAKE_COMMAND) -P CMakeFiles/GGJtest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/GGJtest.dir/clean

test/CMakeFiles/GGJtest.dir/depend:
	cd /Users/amy/workspace/gamedev/ggj19/build.win32 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amy/workspace/gamedev/ggj19 /Users/amy/workspace/gamedev/ggj19/test /Users/amy/workspace/gamedev/ggj19/build.win32 /Users/amy/workspace/gamedev/ggj19/build.win32/test /Users/amy/workspace/gamedev/ggj19/build.win32/test/CMakeFiles/GGJtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/GGJtest.dir/depend

