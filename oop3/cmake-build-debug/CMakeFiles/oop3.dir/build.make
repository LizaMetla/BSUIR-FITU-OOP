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
CMAKE_SOURCE_DIR = /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oop3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/oop3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oop3.dir/flags.make

CMakeFiles/oop3.dir/main.cpp.o: CMakeFiles/oop3.dir/flags.make
CMakeFiles/oop3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oop3.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oop3.dir/main.cpp.o -c /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/main.cpp

CMakeFiles/oop3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oop3.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/main.cpp > CMakeFiles/oop3.dir/main.cpp.i

CMakeFiles/oop3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oop3.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/main.cpp -o CMakeFiles/oop3.dir/main.cpp.s

# Object files for target oop3
oop3_OBJECTS = \
"CMakeFiles/oop3.dir/main.cpp.o"

# External object files for target oop3
oop3_EXTERNAL_OBJECTS =

oop3: CMakeFiles/oop3.dir/main.cpp.o
oop3: CMakeFiles/oop3.dir/build.make
oop3: CMakeFiles/oop3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable oop3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oop3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oop3.dir/build: oop3

.PHONY : CMakeFiles/oop3.dir/build

CMakeFiles/oop3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/oop3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/oop3.dir/clean

CMakeFiles/oop3.dir/depend:
	cd /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3 /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3 /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug /Users/elizavetametla/Desktop/BSUIR-IEF/OAIP/oop3/cmake-build-debug/CMakeFiles/oop3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oop3.dir/depend

