# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/benja/Desktop/shell-sistemasoperativos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/shell_sistemasoperativos.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/shell_sistemasoperativos.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/shell_sistemasoperativos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shell_sistemasoperativos.dir/flags.make

CMakeFiles/shell_sistemasoperativos.dir/main.c.o: CMakeFiles/shell_sistemasoperativos.dir/flags.make
CMakeFiles/shell_sistemasoperativos.dir/main.c.o: /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/main.c
CMakeFiles/shell_sistemasoperativos.dir/main.c.o: CMakeFiles/shell_sistemasoperativos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/shell_sistemasoperativos.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/shell_sistemasoperativos.dir/main.c.o -MF CMakeFiles/shell_sistemasoperativos.dir/main.c.o.d -o CMakeFiles/shell_sistemasoperativos.dir/main.c.o -c /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/main.c

CMakeFiles/shell_sistemasoperativos.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/shell_sistemasoperativos.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/main.c > CMakeFiles/shell_sistemasoperativos.dir/main.c.i

CMakeFiles/shell_sistemasoperativos.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/shell_sistemasoperativos.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/main.c -o CMakeFiles/shell_sistemasoperativos.dir/main.c.s

# Object files for target shell_sistemasoperativos
shell_sistemasoperativos_OBJECTS = \
"CMakeFiles/shell_sistemasoperativos.dir/main.c.o"

# External object files for target shell_sistemasoperativos
shell_sistemasoperativos_EXTERNAL_OBJECTS =

shell_sistemasoperativos: CMakeFiles/shell_sistemasoperativos.dir/main.c.o
shell_sistemasoperativos: CMakeFiles/shell_sistemasoperativos.dir/build.make
shell_sistemasoperativos: CMakeFiles/shell_sistemasoperativos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable shell_sistemasoperativos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shell_sistemasoperativos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shell_sistemasoperativos.dir/build: shell_sistemasoperativos
.PHONY : CMakeFiles/shell_sistemasoperativos.dir/build

CMakeFiles/shell_sistemasoperativos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shell_sistemasoperativos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shell_sistemasoperativos.dir/clean

CMakeFiles/shell_sistemasoperativos.dir/depend:
	cd /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/benja/Desktop/shell-sistemasoperativos /mnt/c/Users/benja/Desktop/shell-sistemasoperativos /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug /mnt/c/Users/benja/Desktop/shell-sistemasoperativos/cmake-build-debug/CMakeFiles/shell_sistemasoperativos.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/shell_sistemasoperativos.dir/depend

