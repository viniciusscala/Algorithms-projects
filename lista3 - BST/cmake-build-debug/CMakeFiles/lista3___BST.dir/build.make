# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lista3___BST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lista3___BST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lista3___BST.dir/flags.make

CMakeFiles/lista3___BST.dir/main.cpp.o: CMakeFiles/lista3___BST.dir/flags.make
CMakeFiles/lista3___BST.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lista3___BST.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lista3___BST.dir/main.cpp.o -c "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/main.cpp"

CMakeFiles/lista3___BST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lista3___BST.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/main.cpp" > CMakeFiles/lista3___BST.dir/main.cpp.i

CMakeFiles/lista3___BST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lista3___BST.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/main.cpp" -o CMakeFiles/lista3___BST.dir/main.cpp.s

# Object files for target lista3___BST
lista3___BST_OBJECTS = \
"CMakeFiles/lista3___BST.dir/main.cpp.o"

# External object files for target lista3___BST
lista3___BST_EXTERNAL_OBJECTS =

lista3___BST: CMakeFiles/lista3___BST.dir/main.cpp.o
lista3___BST: CMakeFiles/lista3___BST.dir/build.make
lista3___BST: CMakeFiles/lista3___BST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lista3___BST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lista3___BST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lista3___BST.dir/build: lista3___BST

.PHONY : CMakeFiles/lista3___BST.dir/build

CMakeFiles/lista3___BST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lista3___BST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lista3___BST.dir/clean

CMakeFiles/lista3___BST.dir/depend:
	cd "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST" "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST" "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug" "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug" "/Users/viniciusscala/Desktop/listas-algoritmos/lista3 - BST/cmake-build-debug/CMakeFiles/lista3___BST.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lista3___BST.dir/depend

