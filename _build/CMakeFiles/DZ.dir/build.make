# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/876/bin/cmake

# The command to remove a file.
RM = /snap/cmake/876/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bartem1us/bartem1us/warship

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bartem1us/bartem1us/warship/_build

# Include any dependencies generated for this target.
include CMakeFiles/DZ.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DZ.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DZ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DZ.dir/flags.make

CMakeFiles/DZ.dir/sources/game_ship.cpp.o: CMakeFiles/DZ.dir/flags.make
CMakeFiles/DZ.dir/sources/game_ship.cpp.o: ../sources/game_ship.cpp
CMakeFiles/DZ.dir/sources/game_ship.cpp.o: CMakeFiles/DZ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartem1us/bartem1us/warship/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DZ.dir/sources/game_ship.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DZ.dir/sources/game_ship.cpp.o -MF CMakeFiles/DZ.dir/sources/game_ship.cpp.o.d -o CMakeFiles/DZ.dir/sources/game_ship.cpp.o -c /home/bartem1us/bartem1us/warship/sources/game_ship.cpp

CMakeFiles/DZ.dir/sources/game_ship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DZ.dir/sources/game_ship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartem1us/bartem1us/warship/sources/game_ship.cpp > CMakeFiles/DZ.dir/sources/game_ship.cpp.i

CMakeFiles/DZ.dir/sources/game_ship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DZ.dir/sources/game_ship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartem1us/bartem1us/warship/sources/game_ship.cpp -o CMakeFiles/DZ.dir/sources/game_ship.cpp.s

# Object files for target DZ
DZ_OBJECTS = \
"CMakeFiles/DZ.dir/sources/game_ship.cpp.o"

# External object files for target DZ
DZ_EXTERNAL_OBJECTS =

libDZ.a: CMakeFiles/DZ.dir/sources/game_ship.cpp.o
libDZ.a: CMakeFiles/DZ.dir/build.make
libDZ.a: CMakeFiles/DZ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bartem1us/bartem1us/warship/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDZ.a"
	$(CMAKE_COMMAND) -P CMakeFiles/DZ.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DZ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DZ.dir/build: libDZ.a
.PHONY : CMakeFiles/DZ.dir/build

CMakeFiles/DZ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DZ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DZ.dir/clean

CMakeFiles/DZ.dir/depend:
	cd /home/bartem1us/bartem1us/warship/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bartem1us/bartem1us/warship /home/bartem1us/bartem1us/warship /home/bartem1us/bartem1us/warship/_build /home/bartem1us/bartem1us/warship/_build /home/bartem1us/bartem1us/warship/_build/CMakeFiles/DZ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DZ.dir/depend

