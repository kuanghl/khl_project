# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kuanghongliang/Documents/vscode_projects/khl_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kuanghongliang/Documents/vscode_projects/khl_project/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/libuv_server.dir/depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/libuv_server.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/libuv_server.dir/flags.make

src/server/CMakeFiles/libuv_server.dir/libuv_server.c.o: src/server/CMakeFiles/libuv_server.dir/flags.make
src/server/CMakeFiles/libuv_server.dir/libuv_server.c.o: ../src/server/libuv_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kuanghongliang/Documents/vscode_projects/khl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/server/CMakeFiles/libuv_server.dir/libuv_server.c.o"
	cd /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libuv_server.dir/libuv_server.c.o -c /home/kuanghongliang/Documents/vscode_projects/khl_project/src/server/libuv_server.c

src/server/CMakeFiles/libuv_server.dir/libuv_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libuv_server.dir/libuv_server.c.i"
	cd /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kuanghongliang/Documents/vscode_projects/khl_project/src/server/libuv_server.c > CMakeFiles/libuv_server.dir/libuv_server.c.i

src/server/CMakeFiles/libuv_server.dir/libuv_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libuv_server.dir/libuv_server.c.s"
	cd /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kuanghongliang/Documents/vscode_projects/khl_project/src/server/libuv_server.c -o CMakeFiles/libuv_server.dir/libuv_server.c.s

# Object files for target libuv_server
libuv_server_OBJECTS = \
"CMakeFiles/libuv_server.dir/libuv_server.c.o"

# External object files for target libuv_server
libuv_server_EXTERNAL_OBJECTS =

bin/libuv_server: src/server/CMakeFiles/libuv_server.dir/libuv_server.c.o
bin/libuv_server: src/server/CMakeFiles/libuv_server.dir/build.make
bin/libuv_server: log/simple_log/liblog.so.SOVERSION
bin/libuv_server: 3rd/libuv/libuv.a
bin/libuv_server: src/server/CMakeFiles/libuv_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kuanghongliang/Documents/vscode_projects/khl_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/libuv_server"
	cd /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libuv_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/libuv_server.dir/build: bin/libuv_server

.PHONY : src/server/CMakeFiles/libuv_server.dir/build

src/server/CMakeFiles/libuv_server.dir/clean:
	cd /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/libuv_server.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/libuv_server.dir/clean

src/server/CMakeFiles/libuv_server.dir/depend:
	cd /home/kuanghongliang/Documents/vscode_projects/khl_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kuanghongliang/Documents/vscode_projects/khl_project /home/kuanghongliang/Documents/vscode_projects/khl_project/src/server /home/kuanghongliang/Documents/vscode_projects/khl_project/build /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server /home/kuanghongliang/Documents/vscode_projects/khl_project/build/src/server/CMakeFiles/libuv_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/CMakeFiles/libuv_server.dir/depend

