# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/main/CLionProjects/abc_dz1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/main/CLionProjects/abc_dz1/build

# Include any dependencies generated for this target.
include CMakeFiles/task01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task01.dir/flags.make

CMakeFiles/task01.dir/vehicle.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/vehicle.cpp.o: ../vehicle.cpp
CMakeFiles/task01.dir/vehicle.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task01.dir/vehicle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/vehicle.cpp.o -MF CMakeFiles/task01.dir/vehicle.cpp.o.d -o CMakeFiles/task01.dir/vehicle.cpp.o -c /Users/main/CLionProjects/abc_dz1/vehicle.cpp

CMakeFiles/task01.dir/vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/vehicle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/CLionProjects/abc_dz1/vehicle.cpp > CMakeFiles/task01.dir/vehicle.cpp.i

CMakeFiles/task01.dir/vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/vehicle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/CLionProjects/abc_dz1/vehicle.cpp -o CMakeFiles/task01.dir/vehicle.cpp.s

CMakeFiles/task01.dir/truck.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/truck.cpp.o: ../truck.cpp
CMakeFiles/task01.dir/truck.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task01.dir/truck.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/truck.cpp.o -MF CMakeFiles/task01.dir/truck.cpp.o.d -o CMakeFiles/task01.dir/truck.cpp.o -c /Users/main/CLionProjects/abc_dz1/truck.cpp

CMakeFiles/task01.dir/truck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/truck.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/CLionProjects/abc_dz1/truck.cpp > CMakeFiles/task01.dir/truck.cpp.i

CMakeFiles/task01.dir/truck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/truck.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/CLionProjects/abc_dz1/truck.cpp -o CMakeFiles/task01.dir/truck.cpp.s

CMakeFiles/task01.dir/bus.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/bus.cpp.o: ../bus.cpp
CMakeFiles/task01.dir/bus.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task01.dir/bus.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/bus.cpp.o -MF CMakeFiles/task01.dir/bus.cpp.o.d -o CMakeFiles/task01.dir/bus.cpp.o -c /Users/main/CLionProjects/abc_dz1/bus.cpp

CMakeFiles/task01.dir/bus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/bus.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/CLionProjects/abc_dz1/bus.cpp > CMakeFiles/task01.dir/bus.cpp.i

CMakeFiles/task01.dir/bus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/bus.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/CLionProjects/abc_dz1/bus.cpp -o CMakeFiles/task01.dir/bus.cpp.s

CMakeFiles/task01.dir/car.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/car.cpp.o: ../car.cpp
CMakeFiles/task01.dir/car.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task01.dir/car.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/car.cpp.o -MF CMakeFiles/task01.dir/car.cpp.o.d -o CMakeFiles/task01.dir/car.cpp.o -c /Users/main/CLionProjects/abc_dz1/car.cpp

CMakeFiles/task01.dir/car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/car.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/CLionProjects/abc_dz1/car.cpp > CMakeFiles/task01.dir/car.cpp.i

CMakeFiles/task01.dir/car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/car.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/CLionProjects/abc_dz1/car.cpp -o CMakeFiles/task01.dir/car.cpp.s

CMakeFiles/task01.dir/container.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/container.cpp.o: ../container.cpp
CMakeFiles/task01.dir/container.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task01.dir/container.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/container.cpp.o -MF CMakeFiles/task01.dir/container.cpp.o.d -o CMakeFiles/task01.dir/container.cpp.o -c /Users/main/CLionProjects/abc_dz1/container.cpp

CMakeFiles/task01.dir/container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/container.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/CLionProjects/abc_dz1/container.cpp > CMakeFiles/task01.dir/container.cpp.i

CMakeFiles/task01.dir/container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/container.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/CLionProjects/abc_dz1/container.cpp -o CMakeFiles/task01.dir/container.cpp.s

CMakeFiles/task01.dir/main.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/main.cpp.o: ../main.cpp
CMakeFiles/task01.dir/main.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/task01.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/main.cpp.o -MF CMakeFiles/task01.dir/main.cpp.o.d -o CMakeFiles/task01.dir/main.cpp.o -c /Users/main/CLionProjects/abc_dz1/main.cpp

CMakeFiles/task01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/CLionProjects/abc_dz1/main.cpp > CMakeFiles/task01.dir/main.cpp.i

CMakeFiles/task01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/CLionProjects/abc_dz1/main.cpp -o CMakeFiles/task01.dir/main.cpp.s

# Object files for target task01
task01_OBJECTS = \
"CMakeFiles/task01.dir/vehicle.cpp.o" \
"CMakeFiles/task01.dir/truck.cpp.o" \
"CMakeFiles/task01.dir/bus.cpp.o" \
"CMakeFiles/task01.dir/car.cpp.o" \
"CMakeFiles/task01.dir/container.cpp.o" \
"CMakeFiles/task01.dir/main.cpp.o"

# External object files for target task01
task01_EXTERNAL_OBJECTS =

../bin/task01: CMakeFiles/task01.dir/vehicle.cpp.o
../bin/task01: CMakeFiles/task01.dir/truck.cpp.o
../bin/task01: CMakeFiles/task01.dir/bus.cpp.o
../bin/task01: CMakeFiles/task01.dir/car.cpp.o
../bin/task01: CMakeFiles/task01.dir/container.cpp.o
../bin/task01: CMakeFiles/task01.dir/main.cpp.o
../bin/task01: CMakeFiles/task01.dir/build.make
../bin/task01: CMakeFiles/task01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/main/CLionProjects/abc_dz1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../bin/task01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task01.dir/build: ../bin/task01
.PHONY : CMakeFiles/task01.dir/build

CMakeFiles/task01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task01.dir/clean

CMakeFiles/task01.dir/depend:
	cd /Users/main/CLionProjects/abc_dz1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/main/CLionProjects/abc_dz1 /Users/main/CLionProjects/abc_dz1 /Users/main/CLionProjects/abc_dz1/build /Users/main/CLionProjects/abc_dz1/build /Users/main/CLionProjects/abc_dz1/build/CMakeFiles/task01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task01.dir/depend

