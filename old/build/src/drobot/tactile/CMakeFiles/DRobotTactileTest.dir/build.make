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
include src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/depend.make

# Include the progress variables for this target.
include src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/progress.make

# Include the compile flags for this target's objects.
include src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/flags.make

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/flags.make
src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o: ../src/drobot/tactile/DRobotTactileSensorBoard.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o -c /home/imanol/workspace/drobot/src/drobot/tactile/DRobotTactileSensorBoard.cpp

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/tactile/DRobotTactileSensorBoard.cpp > CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.i

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/tactile/DRobotTactileSensorBoard.cpp -o CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.s

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.requires:
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.requires

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.provides: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.requires
	$(MAKE) -f src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/build.make src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.provides.build
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.provides

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.provides.build: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/flags.make
src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o: ../src/drobot/tactile/DRobotTactileTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o -c /home/imanol/workspace/drobot/src/drobot/tactile/DRobotTactileTest.cpp

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/tactile/DRobotTactileTest.cpp > CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.i

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/tactile/DRobotTactileTest.cpp -o CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.s

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.requires:
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.requires

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.provides: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.requires
	$(MAKE) -f src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/build.make src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.provides.build
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.provides

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.provides.build: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o

# Object files for target DRobotTactileTest
DRobotTactileTest_OBJECTS = \
"CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o" \
"CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o"

# External object files for target DRobotTactileTest
DRobotTactileTest_EXTERNAL_OBJECTS =

src/drobot/tactile/DRobotTactileTest: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o
src/drobot/tactile/DRobotTactileTest: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o
src/drobot/tactile/DRobotTactileTest: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/build.make
src/drobot/tactile/DRobotTactileTest: /usr/lib/x86_64-linux-gnu/libQtCore.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/x86_64-linux-gnu/libQtGui.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/x86_64-linux-gnu/libQtXml.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/x86_64-linux-gnu/libQtSvg.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/libqwt.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_calib3d.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_contrib.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_core.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_features2d.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_flann.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_gpu.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_highgui.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_imgproc.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_legacy.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_ml.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_nonfree.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_objdetect.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_photo.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_stitching.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_superres.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_ts.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_video.so
src/drobot/tactile/DRobotTactileTest: /usr/local/lib/libopencv_videostab.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/libboost_thread-mt.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/libboost_system-mt.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/libboost_filesystem-mt.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/x86_64-linux-gnu/libpthread.so
src/drobot/tactile/DRobotTactileTest: /usr/lib/libphidget21.so
src/drobot/tactile/DRobotTactileTest: src/drobot/utils/libDRobotUtils.so
src/drobot/tactile/DRobotTactileTest: src/drobot/actuation/libDRobotActuation.so
src/drobot/tactile/DRobotTactileTest: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable DRobotTactileTest"
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DRobotTactileTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/build: src/drobot/tactile/DRobotTactileTest
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/build

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/requires: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileSensorBoard.cpp.o.requires
src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/requires: src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DRobotTactileTest.cpp.o.requires
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/requires

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/clean:
	cd /home/imanol/workspace/drobot/build/src/drobot/tactile && $(CMAKE_COMMAND) -P CMakeFiles/DRobotTactileTest.dir/cmake_clean.cmake
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/clean

src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/depend:
	cd /home/imanol/workspace/drobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imanol/workspace/drobot /home/imanol/workspace/drobot/src/drobot/tactile /home/imanol/workspace/drobot/build /home/imanol/workspace/drobot/build/src/drobot/tactile /home/imanol/workspace/drobot/build/src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/drobot/tactile/CMakeFiles/DRobotTactileTest.dir/depend

