# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/School/Repos/CS3100/Assign4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/School/Repos/CS3100/Assign4/build

# Include any dependencies generated for this target.
include CMakeFiles/assign4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assign4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assign4.dir/flags.make

CMakeFiles/assign4.dir/main.cpp.o: CMakeFiles/assign4.dir/flags.make
CMakeFiles/assign4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/School/Repos/CS3100/Assign4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assign4.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign4.dir/main.cpp.o -c /home/pi/School/Repos/CS3100/Assign4/main.cpp

CMakeFiles/assign4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign4.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/School/Repos/CS3100/Assign4/main.cpp > CMakeFiles/assign4.dir/main.cpp.i

CMakeFiles/assign4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign4.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/School/Repos/CS3100/Assign4/main.cpp -o CMakeFiles/assign4.dir/main.cpp.s

CMakeFiles/assign4.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/assign4.dir/main.cpp.o.requires

CMakeFiles/assign4.dir/main.cpp.o.provides: CMakeFiles/assign4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign4.dir/build.make CMakeFiles/assign4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/assign4.dir/main.cpp.o.provides

CMakeFiles/assign4.dir/main.cpp.o.provides.build: CMakeFiles/assign4.dir/main.cpp.o


CMakeFiles/assign4.dir/utilities.cpp.o: CMakeFiles/assign4.dir/flags.make
CMakeFiles/assign4.dir/utilities.cpp.o: ../utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/School/Repos/CS3100/Assign4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assign4.dir/utilities.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign4.dir/utilities.cpp.o -c /home/pi/School/Repos/CS3100/Assign4/utilities.cpp

CMakeFiles/assign4.dir/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign4.dir/utilities.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/School/Repos/CS3100/Assign4/utilities.cpp > CMakeFiles/assign4.dir/utilities.cpp.i

CMakeFiles/assign4.dir/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign4.dir/utilities.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/School/Repos/CS3100/Assign4/utilities.cpp -o CMakeFiles/assign4.dir/utilities.cpp.s

CMakeFiles/assign4.dir/utilities.cpp.o.requires:

.PHONY : CMakeFiles/assign4.dir/utilities.cpp.o.requires

CMakeFiles/assign4.dir/utilities.cpp.o.provides: CMakeFiles/assign4.dir/utilities.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign4.dir/build.make CMakeFiles/assign4.dir/utilities.cpp.o.provides.build
.PHONY : CMakeFiles/assign4.dir/utilities.cpp.o.provides

CMakeFiles/assign4.dir/utilities.cpp.o.provides.build: CMakeFiles/assign4.dir/utilities.cpp.o


# Object files for target assign4
assign4_OBJECTS = \
"CMakeFiles/assign4.dir/main.cpp.o" \
"CMakeFiles/assign4.dir/utilities.cpp.o"

# External object files for target assign4
assign4_EXTERNAL_OBJECTS =

assign4: CMakeFiles/assign4.dir/main.cpp.o
assign4: CMakeFiles/assign4.dir/utilities.cpp.o
assign4: CMakeFiles/assign4.dir/build.make
assign4: CMakeFiles/assign4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/School/Repos/CS3100/Assign4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable assign4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assign4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assign4.dir/build: assign4

.PHONY : CMakeFiles/assign4.dir/build

CMakeFiles/assign4.dir/requires: CMakeFiles/assign4.dir/main.cpp.o.requires
CMakeFiles/assign4.dir/requires: CMakeFiles/assign4.dir/utilities.cpp.o.requires

.PHONY : CMakeFiles/assign4.dir/requires

CMakeFiles/assign4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assign4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assign4.dir/clean

CMakeFiles/assign4.dir/depend:
	cd /home/pi/School/Repos/CS3100/Assign4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/School/Repos/CS3100/Assign4 /home/pi/School/Repos/CS3100/Assign4 /home/pi/School/Repos/CS3100/Assign4/build /home/pi/School/Repos/CS3100/Assign4/build /home/pi/School/Repos/CS3100/Assign4/build/CMakeFiles/assign4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assign4.dir/depend

