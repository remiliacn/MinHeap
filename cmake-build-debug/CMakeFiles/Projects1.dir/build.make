# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\ASU\CSE_310\Projects\Projects1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projects1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projects1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projects1.dir/flags.make

CMakeFiles/Projects1.dir/util.cpp.obj: CMakeFiles/Projects1.dir/flags.make
CMakeFiles/Projects1.dir/util.cpp.obj: ../util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projects1.dir/util.cpp.obj"
	E:\C++\minGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Projects1.dir\util.cpp.obj -c E:\ASU\CSE_310\Projects\Projects1\util.cpp

CMakeFiles/Projects1.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projects1.dir/util.cpp.i"
	E:\C++\minGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\ASU\CSE_310\Projects\Projects1\util.cpp > CMakeFiles\Projects1.dir\util.cpp.i

CMakeFiles/Projects1.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projects1.dir/util.cpp.s"
	E:\C++\minGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\ASU\CSE_310\Projects\Projects1\util.cpp -o CMakeFiles\Projects1.dir\util.cpp.s

CMakeFiles/Projects1.dir/heap.cpp.obj: CMakeFiles/Projects1.dir/flags.make
CMakeFiles/Projects1.dir/heap.cpp.obj: ../heap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projects1.dir/heap.cpp.obj"
	E:\C++\minGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Projects1.dir\heap.cpp.obj -c E:\ASU\CSE_310\Projects\Projects1\heap.cpp

CMakeFiles/Projects1.dir/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projects1.dir/heap.cpp.i"
	E:\C++\minGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\ASU\CSE_310\Projects\Projects1\heap.cpp > CMakeFiles\Projects1.dir\heap.cpp.i

CMakeFiles/Projects1.dir/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projects1.dir/heap.cpp.s"
	E:\C++\minGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\ASU\CSE_310\Projects\Projects1\heap.cpp -o CMakeFiles\Projects1.dir\heap.cpp.s

# Object files for target Projects1
Projects1_OBJECTS = \
"CMakeFiles/Projects1.dir/util.cpp.obj" \
"CMakeFiles/Projects1.dir/heap.cpp.obj"

# External object files for target Projects1
Projects1_EXTERNAL_OBJECTS =

Projects1.exe: CMakeFiles/Projects1.dir/util.cpp.obj
Projects1.exe: CMakeFiles/Projects1.dir/heap.cpp.obj
Projects1.exe: CMakeFiles/Projects1.dir/build.make
Projects1.exe: CMakeFiles/Projects1.dir/linklibs.rsp
Projects1.exe: CMakeFiles/Projects1.dir/objects1.rsp
Projects1.exe: CMakeFiles/Projects1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Projects1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Projects1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projects1.dir/build: Projects1.exe

.PHONY : CMakeFiles/Projects1.dir/build

CMakeFiles/Projects1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Projects1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Projects1.dir/clean

CMakeFiles/Projects1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\ASU\CSE_310\Projects\Projects1 E:\ASU\CSE_310\Projects\Projects1 E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug E:\ASU\CSE_310\Projects\Projects1\cmake-build-debug\CMakeFiles\Projects1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projects1.dir/depend

