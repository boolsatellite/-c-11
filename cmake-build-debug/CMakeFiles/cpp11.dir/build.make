# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\satellite\AppData\Local\JetBrains\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\satellite\AppData\Local\JetBrains\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\-c-11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\-c-11\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpp11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp11.dir/flags.make

CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj: CMakeFiles/cpp11.dir/flags.make
CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj: ../23.strongly_typed_enum.cpp
CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj: CMakeFiles/cpp11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\-c-11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj"
	C:\Users\SATELL~1\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj -MF CMakeFiles\cpp11.dir\23.strongly_typed_enum.cpp.obj.d -o CMakeFiles\cpp11.dir\23.strongly_typed_enum.cpp.obj -c D:\github\-c-11\23.strongly_typed_enum.cpp

CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.i"
	C:\Users\SATELL~1\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\-c-11\23.strongly_typed_enum.cpp > CMakeFiles\cpp11.dir\23.strongly_typed_enum.cpp.i

CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.s"
	C:\Users\SATELL~1\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\-c-11\23.strongly_typed_enum.cpp -o CMakeFiles\cpp11.dir\23.strongly_typed_enum.cpp.s

# Object files for target cpp11
cpp11_OBJECTS = \
"CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj"

# External object files for target cpp11
cpp11_EXTERNAL_OBJECTS =

cpp11.exe: CMakeFiles/cpp11.dir/23.strongly_typed_enum.cpp.obj
cpp11.exe: CMakeFiles/cpp11.dir/build.make
cpp11.exe: CMakeFiles/cpp11.dir/linklibs.rsp
cpp11.exe: CMakeFiles/cpp11.dir/objects1.rsp
cpp11.exe: CMakeFiles/cpp11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\-c-11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpp11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cpp11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp11.dir/build: cpp11.exe
.PHONY : CMakeFiles/cpp11.dir/build

CMakeFiles/cpp11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cpp11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cpp11.dir/clean

CMakeFiles/cpp11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\-c-11 D:\github\-c-11 D:\github\-c-11\cmake-build-debug D:\github\-c-11\cmake-build-debug D:\github\-c-11\cmake-build-debug\CMakeFiles\cpp11.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp11.dir/depend

