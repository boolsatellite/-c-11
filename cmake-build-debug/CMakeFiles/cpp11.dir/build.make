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
CMAKE_SOURCE_DIR = /mnt/e/code/cpp/-c-11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/code/cpp/-c-11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp11.dir/flags.make

CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.o: CMakeFiles/cpp11.dir/flags.make
CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.o: ../4.snotstatic_member_sizeof.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/code/cpp/-c-11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.o -c /mnt/e/code/cpp/-c-11/4.snotstatic_member_sizeof.cpp

CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/code/cpp/-c-11/4.snotstatic_member_sizeof.cpp > CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.i

CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/code/cpp/-c-11/4.snotstatic_member_sizeof.cpp -o CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.s

CMakeFiles/cpp11.dir/5.expand.cpp.o: CMakeFiles/cpp11.dir/flags.make
CMakeFiles/cpp11.dir/5.expand.cpp.o: ../5.expand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/code/cpp/-c-11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp11.dir/5.expand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp11.dir/5.expand.cpp.o -c /mnt/e/code/cpp/-c-11/5.expand.cpp

CMakeFiles/cpp11.dir/5.expand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp11.dir/5.expand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/code/cpp/-c-11/5.expand.cpp > CMakeFiles/cpp11.dir/5.expand.cpp.i

CMakeFiles/cpp11.dir/5.expand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp11.dir/5.expand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/code/cpp/-c-11/5.expand.cpp -o CMakeFiles/cpp11.dir/5.expand.cpp.s

# Object files for target cpp11
cpp11_OBJECTS = \
"CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.o" \
"CMakeFiles/cpp11.dir/5.expand.cpp.o"

# External object files for target cpp11
cpp11_EXTERNAL_OBJECTS =

cpp11: CMakeFiles/cpp11.dir/4.snotstatic_member_sizeof.cpp.o
cpp11: CMakeFiles/cpp11.dir/5.expand.cpp.o
cpp11: CMakeFiles/cpp11.dir/build.make
cpp11: CMakeFiles/cpp11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/code/cpp/-c-11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpp11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp11.dir/build: cpp11

.PHONY : CMakeFiles/cpp11.dir/build

CMakeFiles/cpp11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp11.dir/clean

CMakeFiles/cpp11.dir/depend:
	cd /mnt/e/code/cpp/-c-11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/code/cpp/-c-11 /mnt/e/code/cpp/-c-11 /mnt/e/code/cpp/-c-11/cmake-build-debug /mnt/e/code/cpp/-c-11/cmake-build-debug /mnt/e/code/cpp/-c-11/cmake-build-debug/CMakeFiles/cpp11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp11.dir/depend

