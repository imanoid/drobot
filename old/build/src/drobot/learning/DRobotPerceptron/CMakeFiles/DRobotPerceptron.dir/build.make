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
include src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/depend.make

# Include the progress variables for this target.
include src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/progress.make

# Include the compile flags for this target's objects.
include src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/flags.make

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/flags.make
src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o: ../src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o -c /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp > CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.i

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptron.cpp -o CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.s

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.requires:
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.requires

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.provides: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.requires
	$(MAKE) -f src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/build.make src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.provides.build
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.provides

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.provides.build: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/flags.make
src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o: ../src/drobot/learning/DRobotPerceptron/DRobotPerceptronTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/imanol/workspace/drobot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o -c /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptronTest.cpp

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.i"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptronTest.cpp > CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.i

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.s"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron/DRobotPerceptronTest.cpp -o CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.s

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.requires:
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.requires

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.provides: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.requires
	$(MAKE) -f src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/build.make src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.provides.build
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.provides

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.provides.build: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o

# Object files for target DRobotPerceptron
DRobotPerceptron_OBJECTS = \
"CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o" \
"CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o"

# External object files for target DRobotPerceptron
DRobotPerceptron_EXTERNAL_OBJECTS =

src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/build.make
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/x86_64-linux-gnu/libQtXml.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/x86_64-linux-gnu/libQtSvg.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/libqwt.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_calib3d.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_contrib.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_core.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_features2d.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_flann.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_gpu.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_highgui.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_imgproc.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_legacy.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_ml.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_nonfree.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_objdetect.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_photo.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_stitching.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_superres.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_ts.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_video.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/local/lib/libopencv_videostab.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/libboost_thread-mt.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/libboost_system-mt.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/libboost_filesystem-mt.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/x86_64-linux-gnu/libpthread.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: /usr/lib/libphidget21.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: src/drobot/utils/libDRobotUtils.so
src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libDRobotPerceptron.so"
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DRobotPerceptron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/build: src/drobot/learning/DRobotPerceptron/libDRobotPerceptron.so
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/build

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/requires: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptron.cpp.o.requires
src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/requires: src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DRobotPerceptronTest.cpp.o.requires
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/requires

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/clean:
	cd /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron && $(CMAKE_COMMAND) -P CMakeFiles/DRobotPerceptron.dir/cmake_clean.cmake
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/clean

src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/depend:
	cd /home/imanol/workspace/drobot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imanol/workspace/drobot /home/imanol/workspace/drobot/src/drobot/learning/DRobotPerceptron /home/imanol/workspace/drobot/build /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron /home/imanol/workspace/drobot/build/src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/drobot/learning/DRobotPerceptron/CMakeFiles/DRobotPerceptron.dir/depend

