# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lifu/Documents/DBdriver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lifu/Documents/DBdriver/build

# Include any dependencies generated for this target.
include CMakeFiles/DBdriver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DBdriver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DBdriver.dir/flags.make

CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o: CMakeFiles/DBdriver.dir/flags.make
CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o: ../src/test/testDB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lifu/Documents/DBdriver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o -c /Users/lifu/Documents/DBdriver/src/test/testDB.cpp

CMakeFiles/DBdriver.dir/src/test/testDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBdriver.dir/src/test/testDB.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lifu/Documents/DBdriver/src/test/testDB.cpp > CMakeFiles/DBdriver.dir/src/test/testDB.cpp.i

CMakeFiles/DBdriver.dir/src/test/testDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBdriver.dir/src/test/testDB.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lifu/Documents/DBdriver/src/test/testDB.cpp -o CMakeFiles/DBdriver.dir/src/test/testDB.cpp.s

CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.requires:

.PHONY : CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.requires

CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.provides: CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.requires
	$(MAKE) -f CMakeFiles/DBdriver.dir/build.make CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.provides.build
.PHONY : CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.provides

CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.provides.build: CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o


CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o: CMakeFiles/DBdriver.dir/flags.make
CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o: ../src/DBdriverpqsql.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lifu/Documents/DBdriver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o -c /Users/lifu/Documents/DBdriver/src/DBdriverpqsql.cpp

CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lifu/Documents/DBdriver/src/DBdriverpqsql.cpp > CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.i

CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lifu/Documents/DBdriver/src/DBdriverpqsql.cpp -o CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.s

CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.requires:

.PHONY : CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.requires

CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.provides: CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.requires
	$(MAKE) -f CMakeFiles/DBdriver.dir/build.make CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.provides.build
.PHONY : CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.provides

CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.provides.build: CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o


# Object files for target DBdriver
DBdriver_OBJECTS = \
"CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o" \
"CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o"

# External object files for target DBdriver
DBdriver_EXTERNAL_OBJECTS =

../bin/DBdriver: CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o
../bin/DBdriver: CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o
../bin/DBdriver: CMakeFiles/DBdriver.dir/build.make
../bin/DBdriver: CMakeFiles/DBdriver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lifu/Documents/DBdriver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/DBdriver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DBdriver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DBdriver.dir/build: ../bin/DBdriver

.PHONY : CMakeFiles/DBdriver.dir/build

CMakeFiles/DBdriver.dir/requires: CMakeFiles/DBdriver.dir/src/test/testDB.cpp.o.requires
CMakeFiles/DBdriver.dir/requires: CMakeFiles/DBdriver.dir/src/DBdriverpqsql.cpp.o.requires

.PHONY : CMakeFiles/DBdriver.dir/requires

CMakeFiles/DBdriver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DBdriver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DBdriver.dir/clean

CMakeFiles/DBdriver.dir/depend:
	cd /Users/lifu/Documents/DBdriver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lifu/Documents/DBdriver /Users/lifu/Documents/DBdriver /Users/lifu/Documents/DBdriver/build /Users/lifu/Documents/DBdriver/build /Users/lifu/Documents/DBdriver/build/CMakeFiles/DBdriver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DBdriver.dir/depend
