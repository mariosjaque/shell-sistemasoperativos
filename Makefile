# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/benja/Desktop/Shell v2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/benja/Desktop/Shell v2"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/c/Users/benja/Desktop/Shell v2/CMakeFiles" "/mnt/c/Users/benja/Desktop/Shell v2//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/c/Users/benja/Desktop/Shell v2/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Shell_v2

# Build rule for target.
Shell_v2: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Shell_v2
.PHONY : Shell_v2

# fast build rule for target.
Shell_v2/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/build
.PHONY : Shell_v2/fast

comandos.o: comandos.c.o
.PHONY : comandos.o

# target to build an object file
comandos.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/comandos.c.o
.PHONY : comandos.c.o

comandos.i: comandos.c.i
.PHONY : comandos.i

# target to preprocess a source file
comandos.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/comandos.c.i
.PHONY : comandos.c.i

comandos.s: comandos.c.s
.PHONY : comandos.s

# target to generate assembly for a file
comandos.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/comandos.c.s
.PHONY : comandos.c.s

customCom.o: customCom.c.o
.PHONY : customCom.o

# target to build an object file
customCom.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/customCom.c.o
.PHONY : customCom.c.o

customCom.i: customCom.c.i
.PHONY : customCom.i

# target to preprocess a source file
customCom.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/customCom.c.i
.PHONY : customCom.c.i

customCom.s: customCom.c.s
.PHONY : customCom.s

# target to generate assembly for a file
customCom.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/customCom.c.s
.PHONY : customCom.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/main.c.s
.PHONY : main.c.s

signals.o: signals.c.o
.PHONY : signals.o

# target to build an object file
signals.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/signals.c.o
.PHONY : signals.c.o

signals.i: signals.c.i
.PHONY : signals.i

# target to preprocess a source file
signals.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/signals.c.i
.PHONY : signals.c.i

signals.s: signals.c.s
.PHONY : signals.s

# target to generate assembly for a file
signals.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Shell_v2.dir/build.make CMakeFiles/Shell_v2.dir/signals.c.s
.PHONY : signals.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Shell_v2"
	@echo "... comandos.o"
	@echo "... comandos.i"
	@echo "... comandos.s"
	@echo "... customCom.o"
	@echo "... customCom.i"
	@echo "... customCom.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... signals.o"
	@echo "... signals.i"
	@echo "... signals.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

