# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "/Users/elizavetametla/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4505.18/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/elizavetametla/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4505.18/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/elizavetametla/Desktop/cpp_test/labatri

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/labatri.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/labatri.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/labatri.dir/flags.make

CMakeFiles/labatri.dir/main.cpp.o: CMakeFiles/labatri.dir/flags.make
CMakeFiles/labatri.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/labatri.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/labatri.dir/main.cpp.o -c /Users/elizavetametla/Desktop/cpp_test/labatri/main.cpp

CMakeFiles/labatri.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/labatri.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elizavetametla/Desktop/cpp_test/labatri/main.cpp > CMakeFiles/labatri.dir/main.cpp.i

CMakeFiles/labatri.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/labatri.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elizavetametla/Desktop/cpp_test/labatri/main.cpp -o CMakeFiles/labatri.dir/main.cpp.s

# Object files for target labatri
labatri_OBJECTS = \
"CMakeFiles/labatri.dir/main.cpp.o"

# External object files for target labatri
labatri_EXTERNAL_OBJECTS =

labatri: CMakeFiles/labatri.dir/main.cpp.o
labatri: CMakeFiles/labatri.dir/build.make
labatri: CMakeFiles/labatri.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable labatri"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/labatri.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/labatri.dir/build: labatri

.PHONY : CMakeFiles/labatri.dir/build

CMakeFiles/labatri.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/labatri.dir/cmake_clean.cmake
.PHONY : CMakeFiles/labatri.dir/clean

CMakeFiles/labatri.dir/depend:
	cd /Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/elizavetametla/Desktop/cpp_test/labatri /Users/elizavetametla/Desktop/cpp_test/labatri /Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug /Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug /Users/elizavetametla/Desktop/cpp_test/labatri/cmake-build-debug/CMakeFiles/labatri.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/labatri.dir/depend
