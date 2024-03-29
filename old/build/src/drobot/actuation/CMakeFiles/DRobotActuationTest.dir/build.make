# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/imanol/workspace/drobot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imanol/workspace/drobot/build

# Include any dependencies generated for this target.
include src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/depend.make

# Include the progress variables for this target.
include src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/progress.make

# Include the compile flags for this target's objects.
include src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o: ../src/drobot/actuation/DRobotActuationEvents.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationEvents.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationEvents.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationEvents.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o: ../src/drobot/actuation/DRobotAbstractServoMotor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAbstractServoMotor.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAbstractServoMotor.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAbstractServoMotor.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o: ../src/drobot/actuation/DRobotAdvancedServoMotor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAdvancedServoMotor.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAdvancedServoMotor.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAdvancedServoMotor.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o: ../src/drobot/actuation/DRobotServoMotor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotServoMotor.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotServoMotor.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotServoMotor.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o: ../src/drobot/actuation/DRobotAbstractActuation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAbstractActuation.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAbstractActuation.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAbstractActuation.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o: ../src/drobot/actuation/DRobotAdvancedActuation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAdvancedActuation.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAdvancedActuation.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotAdvancedActuation.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o: ../src/drobot/actuation/DRobotActuation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuation.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuation.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuation.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o: ../src/drobot/actuation/DRobotActuationTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationTest.cpp

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationTest.cpp > CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationTest.cpp -o CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o

# Object files for target DRobotActuationTest
DRobotActuationTest_OBJECTS = \
"CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o" \
"CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o"

# External object files for target DRobotActuationTest
DRobotActuationTest_EXTERNAL_OBJECTS =

src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build.make
src/drobot/actuation/DRobotActuationTest: /usr/lib/x86_64-linux-gnu/libQtCore.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/x86_64-linux-gnu/libQtGui.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/x86_64-linux-gnu/libQtXml.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/x86_64-linux-gnu/libQtSvg.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/libqwt.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_calib3d.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_contrib.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_core.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_features2d.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_flann.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_gpu.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_highgui.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_imgproc.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_legacy.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_ml.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_nonfree.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_objdetect.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_photo.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_stitching.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_superres.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_ts.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_video.so
src/drobot/actuation/DRobotActuationTest: /usr/local/lib/libopencv_videostab.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/libboost_thread-mt.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/libboost_system-mt.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/libboost_filesystem-mt.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/x86_64-linux-gnu/libpthread.so
src/drobot/actuation/DRobotActuationTest: /usr/lib/libphidget21.so
src/drobot/actuation/DRobotActuationTest: src/drobot/utils/libDRobotUtils.so
src/drobot/actuation/DRobotActuationTest: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable DRobotActuationTest"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DRobotActuationTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build: src/drobot/actuation/DRobotActuationTest
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/build

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationEvents.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractServoMotor.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedServoMotor.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotServoMotor.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAbstractActuation.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotAdvancedActuation.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuation.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DRobotActuationTest.cpp.o.requires
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/requires

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/clean:
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && $(CMAKE_COMMAND) -P CMakeFiles/DRobotActuationTest.dir/cmake_clean.cmake
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/clean

src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/depend:
	cd /home/imanol/workspace/drobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imanol/workspace/drobot /home/imanol/workspace/drobot/src/drobot/actuation /home/imanol/workspace/drobot/build /home/imanol/workspace/drobot/build/src/drobot/actuation /home/imanol/workspace/drobot/build/src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuationTest.dir/depend

