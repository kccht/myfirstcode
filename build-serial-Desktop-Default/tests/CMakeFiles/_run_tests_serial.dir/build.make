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
CMAKE_SOURCE_DIR = /home/relaybot/catkin_ws/src/myserial/serial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/relaybot/catkin_ws/src/myserial/build-serial-Desktop-Default

# Utility rule file for _run_tests_serial.

# Include the progress variables for this target.
include tests/CMakeFiles/_run_tests_serial.dir/progress.make

tests/CMakeFiles/_run_tests_serial:

_run_tests_serial: tests/CMakeFiles/_run_tests_serial
_run_tests_serial: tests/CMakeFiles/_run_tests_serial.dir/build.make
.PHONY : _run_tests_serial

# Rule to build all files generated by this target.
tests/CMakeFiles/_run_tests_serial.dir/build: _run_tests_serial
.PHONY : tests/CMakeFiles/_run_tests_serial.dir/build

tests/CMakeFiles/_run_tests_serial.dir/clean:
	cd /home/relaybot/catkin_ws/src/myserial/build-serial-Desktop-Default/tests && $(CMAKE_COMMAND) -P CMakeFiles/_run_tests_serial.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/_run_tests_serial.dir/clean

tests/CMakeFiles/_run_tests_serial.dir/depend:
	cd /home/relaybot/catkin_ws/src/myserial/build-serial-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/relaybot/catkin_ws/src/myserial/serial /home/relaybot/catkin_ws/src/myserial/serial/tests /home/relaybot/catkin_ws/src/myserial/build-serial-Desktop-Default /home/relaybot/catkin_ws/src/myserial/build-serial-Desktop-Default/tests /home/relaybot/catkin_ws/src/myserial/build-serial-Desktop-Default/tests/CMakeFiles/_run_tests_serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/_run_tests_serial.dir/depend

