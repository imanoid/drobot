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
include src/drobot/learning/CMakeFiles/DRobotLearning.dir/depend.make

# Include the progress variables for this target.
include src/drobot/learning/CMakeFiles/DRobotLearning.dir/progress.make

# Include the compile flags for this target's objects.
include src/drobot/learning/CMakeFiles/DRobotLearning.dir/flags.make

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o: src/drobot/learning/CMakeFiles/DRobotLearning.dir/flags.make
src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o: ../src/drobot/learning/DRobotPopulationCoding/DRobotPopulationCoding.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o -c /home/imanol/workspace/drobot/src/drobot/learning/DRobotPopulationCoding/DRobotPopulationCoding.cpp

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/learning/DRobotPopulationCoding/DRobotPopulationCoding.cpp > CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.i

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/learning/DRobotPopulationCoding/DRobotPopulationCoding.cpp -o CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.s

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.requires:
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.requires

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.provides: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.requires
	$(MAKE) -f src/drobot/learning/CMakeFiles/DRobotLearning.dir/build.make src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.provides.build
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.provides

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.provides.build: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o: src/drobot/learning/CMakeFiles/DRobotLearning.dir/flags.make
src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o: ../src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o -c /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp > CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.i

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp -o CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.s

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.requires:
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.requires

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.provides: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.requires
	$(MAKE) -f src/drobot/learning/CMakeFiles/DRobotLearning.dir/build.make src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.provides.build
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.provides

src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.provides.build: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o

# Object files for target DRobotLearning
DRobotLearning_OBJECTS = \
"CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o" \
"CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o"

# External object files for target DRobotLearning
DRobotLearning_EXTERNAL_OBJECTS =

src/drobot/learning/libDRobotLearning.so: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o
src/drobot/learning/libDRobotLearning.so: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o
src/drobot/learning/libDRobotLearning.so: src/drobot/learning/CMakeFiles/DRobotLearning.dir/build.make
src/drobot/learning/libDRobotLearning.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/x86_64-linux-gnu/libQtXml.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/x86_64-linux-gnu/libQtSvg.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/libqwt.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/libboost_thread-mt.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/libboost_system-mt.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/libboost_filesystem-mt.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/x86_64-linux-gnu/libpthread.so
src/drobot/learning/libDRobotLearning.so: /usr/lib/libphidget21.so
src/drobot/learning/libDRobotLearning.so: src/drobot/learning/CMakeFiles/DRobotLearning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libDRobotLearning.so"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DRobotLearning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/drobot/learning/CMakeFiles/DRobotLearning.dir/build: src/drobot/learning/libDRobotLearning.so
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/build

src/drobot/learning/CMakeFiles/DRobotLearning.dir/requires: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPopulationCoding/DRobotPopulationCoding.cpp.o.requires
src/drobot/learning/CMakeFiles/DRobotLearning.dir/requires: src/drobot/learning/CMakeFiles/DRobotLearning.dir/DRobotPerceptron/DRobotPerceptron.cpp.o.requires
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/requires

src/drobot/learning/CMakeFiles/DRobotLearning.dir/clean:
	cd /home/imanol/workspace/drobot/build/src/drobot/learning && $(CMAKE_COMMAND) -P CMakeFiles/DRobotLearning.dir/cmake_clean.cmake
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/clean

src/drobot/learning/CMakeFiles/DRobotLearning.dir/depend:
	cd /home/imanol/workspace/drobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imanol/workspace/drobot /home/imanol/workspace/drobot/src/drobot/learning /home/imanol/workspace/drobot/build /home/imanol/workspace/drobot/build/src/drobot/learning /home/imanol/workspace/drobot/build/src/drobot/learning/CMakeFiles/DRobotLearning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/drobot/learning/CMakeFiles/DRobotLearning.dir/depend

