# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hp\image_filters1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hp\image_filters1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main1.dir/flags.make

CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj: CMakeFiles/main1.dir/flags.make
CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj: ../CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp
CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj: CMakeFiles/main1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hp\image_filters1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj -MF CMakeFiles\main1.dir\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj.d -o CMakeFiles\main1.dir\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj -c C:\Users\hp\image_filters1\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp

CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hp\image_filters1\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp > CMakeFiles\main1.dir\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.i

CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hp\image_filters1\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp -o CMakeFiles\main1.dir\CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.s

# Object files for target main1
main1_OBJECTS = \
"CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj"

# External object files for target main1
main1_EXTERNAL_OBJECTS =

main1.exe: CMakeFiles/main1.dir/CS112-203-2nd-S3-20210049-20210067-20211053-A3-Part1.cpp.obj
main1.exe: CMakeFiles/main1.dir/build.make
main1.exe: CMakeFiles/main1.dir/linklibs.rsp
main1.exe: CMakeFiles/main1.dir/objects1.rsp
main1.exe: CMakeFiles/main1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hp\image_filters1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main1.dir/build: main1.exe
.PHONY : CMakeFiles/main1.dir/build

CMakeFiles/main1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main1.dir/clean

CMakeFiles/main1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hp\image_filters1 C:\Users\hp\image_filters1 C:\Users\hp\image_filters1\cmake-build-debug C:\Users\hp\image_filters1\cmake-build-debug C:\Users\hp\image_filters1\cmake-build-debug\CMakeFiles\main1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main1.dir/depend

