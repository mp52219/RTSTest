# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Marin\CLionProjects\RTSTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RTSTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RTSTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RTSTest.dir/flags.make

CMakeFiles/RTSTest.dir/src/main.cpp.obj: CMakeFiles/RTSTest.dir/flags.make
CMakeFiles/RTSTest.dir/src/main.cpp.obj: CMakeFiles/RTSTest.dir/includes_CXX.rsp
CMakeFiles/RTSTest.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RTSTest.dir/src/main.cpp.obj"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RTSTest.dir\src\main.cpp.obj -c C:\Users\Marin\CLionProjects\RTSTest\src\main.cpp

CMakeFiles/RTSTest.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSTest.dir/src/main.cpp.i"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Marin\CLionProjects\RTSTest\src\main.cpp > CMakeFiles\RTSTest.dir\src\main.cpp.i

CMakeFiles/RTSTest.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSTest.dir/src/main.cpp.s"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Marin\CLionProjects\RTSTest\src\main.cpp -o CMakeFiles\RTSTest.dir\src\main.cpp.s

CMakeFiles/RTSTest.dir/src/FindPath.cpp.obj: CMakeFiles/RTSTest.dir/flags.make
CMakeFiles/RTSTest.dir/src/FindPath.cpp.obj: CMakeFiles/RTSTest.dir/includes_CXX.rsp
CMakeFiles/RTSTest.dir/src/FindPath.cpp.obj: ../src/FindPath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RTSTest.dir/src/FindPath.cpp.obj"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RTSTest.dir\src\FindPath.cpp.obj -c C:\Users\Marin\CLionProjects\RTSTest\src\FindPath.cpp

CMakeFiles/RTSTest.dir/src/FindPath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSTest.dir/src/FindPath.cpp.i"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Marin\CLionProjects\RTSTest\src\FindPath.cpp > CMakeFiles\RTSTest.dir\src\FindPath.cpp.i

CMakeFiles/RTSTest.dir/src/FindPath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSTest.dir/src/FindPath.cpp.s"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Marin\CLionProjects\RTSTest\src\FindPath.cpp -o CMakeFiles\RTSTest.dir\src\FindPath.cpp.s

CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.obj: CMakeFiles/RTSTest.dir/flags.make
CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.obj: CMakeFiles/RTSTest.dir/includes_CXX.rsp
CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.obj: ../src/GlobalGameVariables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.obj"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RTSTest.dir\src\GlobalGameVariables.cpp.obj -c C:\Users\Marin\CLionProjects\RTSTest\src\GlobalGameVariables.cpp

CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.i"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Marin\CLionProjects\RTSTest\src\GlobalGameVariables.cpp > CMakeFiles\RTSTest.dir\src\GlobalGameVariables.cpp.i

CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.s"
	C:\Users\Marin\Downloads\mingw7-3\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Marin\CLionProjects\RTSTest\src\GlobalGameVariables.cpp -o CMakeFiles\RTSTest.dir\src\GlobalGameVariables.cpp.s

# Object files for target RTSTest
RTSTest_OBJECTS = \
"CMakeFiles/RTSTest.dir/src/main.cpp.obj" \
"CMakeFiles/RTSTest.dir/src/FindPath.cpp.obj" \
"CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.obj"

# External object files for target RTSTest
RTSTest_EXTERNAL_OBJECTS =

RTSTest.exe: CMakeFiles/RTSTest.dir/src/main.cpp.obj
RTSTest.exe: CMakeFiles/RTSTest.dir/src/FindPath.cpp.obj
RTSTest.exe: CMakeFiles/RTSTest.dir/src/GlobalGameVariables.cpp.obj
RTSTest.exe: CMakeFiles/RTSTest.dir/build.make
RTSTest.exe: /SFML/lib/libsfml-system-d.a
RTSTest.exe: /SFML/lib/libsfml-window-d.a
RTSTest.exe: /SFML/lib/libsfml-graphics-d.a
RTSTest.exe: CMakeFiles/RTSTest.dir/linklibs.rsp
RTSTest.exe: CMakeFiles/RTSTest.dir/objects1.rsp
RTSTest.exe: CMakeFiles/RTSTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable RTSTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RTSTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RTSTest.dir/build: RTSTest.exe

.PHONY : CMakeFiles/RTSTest.dir/build

CMakeFiles/RTSTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RTSTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RTSTest.dir/clean

CMakeFiles/RTSTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Marin\CLionProjects\RTSTest C:\Users\Marin\CLionProjects\RTSTest C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug C:\Users\Marin\CLionProjects\RTSTest\cmake-build-debug\CMakeFiles\RTSTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RTSTest.dir/depend

