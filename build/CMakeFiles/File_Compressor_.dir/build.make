# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /workspaces/File_Compressor_/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/File_Compressor_/build

# Include any dependencies generated for this target.
include CMakeFiles/File_Compressor_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/File_Compressor_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/File_Compressor_.dir/flags.make

CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.o: CMakeFiles/File_Compressor_.dir/flags.make
CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.o: /workspaces/File_Compressor_/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/File_Compressor_/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.o -c /workspaces/File_Compressor_/src/main.cpp

CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/File_Compressor_/src/main.cpp > CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.i

CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/File_Compressor_/src/main.cpp -o CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.s

CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.o: CMakeFiles/File_Compressor_.dir/flags.make
CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.o: /workspaces/File_Compressor_/src/compressor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/File_Compressor_/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.o -c /workspaces/File_Compressor_/src/compressor.cpp

CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/File_Compressor_/src/compressor.cpp > CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.i

CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/File_Compressor_/src/compressor.cpp -o CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.s

# Object files for target File_Compressor_
File_Compressor__OBJECTS = \
"CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.o" \
"CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.o"

# External object files for target File_Compressor_
File_Compressor__EXTERNAL_OBJECTS =

File_Compressor_: CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/main.cpp.o
File_Compressor_: CMakeFiles/File_Compressor_.dir/workspaces/File_Compressor_/src/compressor.cpp.o
File_Compressor_: CMakeFiles/File_Compressor_.dir/build.make
File_Compressor_: CMakeFiles/File_Compressor_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/File_Compressor_/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable File_Compressor_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/File_Compressor_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/File_Compressor_.dir/build: File_Compressor_

.PHONY : CMakeFiles/File_Compressor_.dir/build

CMakeFiles/File_Compressor_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/File_Compressor_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/File_Compressor_.dir/clean

CMakeFiles/File_Compressor_.dir/depend:
	cd /workspaces/File_Compressor_/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/File_Compressor_/build /workspaces/File_Compressor_/build /workspaces/File_Compressor_/build /workspaces/File_Compressor_/build /workspaces/File_Compressor_/build/CMakeFiles/File_Compressor_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/File_Compressor_.dir/depend

