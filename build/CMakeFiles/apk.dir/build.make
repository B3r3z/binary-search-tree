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
CMAKE_SOURCE_DIR = "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build"

# Include any dependencies generated for this target.
include CMakeFiles/apk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/apk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/apk.dir/flags.make

CMakeFiles/apk.dir/main.cpp.o: CMakeFiles/apk.dir/flags.make
CMakeFiles/apk.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/apk.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/apk.dir/main.cpp.o -c "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/main.cpp"

CMakeFiles/apk.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/apk.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/main.cpp" > CMakeFiles/apk.dir/main.cpp.i

CMakeFiles/apk.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/apk.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/main.cpp" -o CMakeFiles/apk.dir/main.cpp.s

# Object files for target apk
apk_OBJECTS = \
"CMakeFiles/apk.dir/main.cpp.o"

# External object files for target apk
apk_EXTERNAL_OBJECTS =

apk: CMakeFiles/apk.dir/main.cpp.o
apk: CMakeFiles/apk.dir/build.make
apk: CMakeFiles/apk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable apk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/apk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/apk.dir/build: apk

.PHONY : CMakeFiles/apk.dir/build

CMakeFiles/apk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/apk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/apk.dir/clean

CMakeFiles/apk.dir/depend:
	cd "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne" "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne" "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build" "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build" "/home/b4rt/Dokumenty/Projekty c++/SEM 3/Tydzien 11 drzewo binarne/build/CMakeFiles/apk.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/apk.dir/depend
