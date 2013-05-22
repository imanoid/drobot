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
include src/drobot/actuation/CMakeFiles/DRobotActuation.dir/depend.make

# Include the progress variables for this target.
include src/drobot/actuation/CMakeFiles/DRobotActuation.dir/progress.make

# Include the compile flags for this target's objects.
include src/drobot/actuation/CMakeFiles/DRobotActuation.dir/flags.make

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o: ../src/drobot/actuation/DRobotActuationEvents.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationEvents.cpp

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationEvents.cpp > CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationEvents.cpp -o CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o: ../src/drobot/actuation/DRobotServoMotor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotServoMotor.cpp

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotServoMotor.cpp > CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotServoMotor.cpp -o CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o: ../src/drobot/actuation/DRobotActuation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuation.cpp

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuation.cpp > CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuation.cpp -o CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/flags.make
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o: ../src/drobot/actuation/DRobotActuationTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o -c /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationTest.cpp

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationTest.cpp > CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.i

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/actuation/DRobotActuationTest.cpp -o CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.s

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.requires:
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.requires

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.provides: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.requires
	$(MAKE) -f src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build.make src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.provides.build
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.provides

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.provides.build: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o

# Object files for target DRobotActuation
DRobotActuation_OBJECTS = \
"CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o" \
"CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o" \
"CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o" \
"CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o"

# External object files for target DRobotActuation
DRobotActuation_EXTERNAL_OBJECTS =

src/drobot/actuation/libDRobotActuation.so: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o
src/drobot/actuation/libDRobotActuation.so: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o
src/drobot/actuation/libDRobotActuation.so: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o
src/drobot/actuation/libDRobotActuation.so: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o
src/drobot/actuation/libDRobotActuation.so: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build.make
src/drobot/actuation/libDRobotActuation.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/x86_64-linux-gnu/libQtXml.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/x86_64-linux-gnu/libQtSvg.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/libqwt.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/libboost_thread-mt.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/libboost_system-mt.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/libboost_filesystem-mt.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/x86_64-linux-gnu/libpthread.so
src/drobot/actuation/libDRobotActuation.so: /usr/lib/libphidget21.so
src/drobot/actuation/libDRobotActuation.so: src/drobot/utils/libDRobotUtils.so
src/drobot/actuation/libDRobotActuation.so: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libDRobotActuation.so"
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DRobotActuation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build: src/drobot/actuation/libDRobotActuation.so
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/build

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationEvents.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotServoMotor.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuation.cpp.o.requires
src/drobot/actuation/CMakeFiles/DRobotActuation.dir/requires: src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DRobotActuationTest.cpp.o.requires
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/requires

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/clean:
	cd /home/imanol/workspace/drobot/build/src/drobot/actuation && $(CMAKE_COMMAND) -P CMakeFiles/DRobotActuation.dir/cmake_clean.cmake
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/clean

src/drobot/actuation/CMakeFiles/DRobotActuation.dir/depend:
	cd /home/imanol/workspace/drobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imanol/workspace/drobot /home/imanol/workspace/drobot/src/drobot/actuation /home/imanol/workspace/drobot/build /home/imanol/workspace/drobot/build/src/drobot/actuation /home/imanol/workspace/drobot/build/src/drobot/actuation/CMakeFiles/DRobotActuation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/drobot/actuation/CMakeFiles/DRobotActuation.dir/depend

