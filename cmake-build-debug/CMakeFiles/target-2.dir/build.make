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
include CMakeFiles/target-2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/target-2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/target-2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/target-2.dir/flags.make

CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj: CMakeFiles/target-2.dir/flags.make
CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj: ../CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp
CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj: CMakeFiles/target-2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hp\image_filters1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj -MF CMakeFiles\target-2.dir\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj.d -o CMakeFiles\target-2.dir\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj -c C:\Users\hp\image_filters1\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp

CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hp\image_filters1\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp > CMakeFiles\target-2.dir\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.i

CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hp\image_filters1\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp -o CMakeFiles\target-2.dir\CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.s

# Object files for target target-2
target__2_OBJECTS = \
"CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj"

# External object files for target target-2
target__2_EXTERNAL_OBJECTS =

target-2.exe: CMakeFiles/target-2.dir/CS112-2022-2nd-S3-20210049-20210067-20211053-A3Bonus.cpp.obj
target-2.exe: CMakeFiles/target-2.dir/build.make
target-2.exe: CMakeFiles/target-2.dir/linklibs.rsp
target-2.exe: CMakeFiles/target-2.dir/objects1.rsp
target-2.exe: CMakeFiles/target-2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hp\image_filters1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable target-2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\target-2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/target-2.dir/build: target-2.exe
.PHONY : CMakeFiles/target-2.dir/build

CMakeFiles/target-2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\target-2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/target-2.dir/clean

CMakeFiles/target-2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hp\image_filters1 C:\Users\hp\image_filters1 C:\Users\hp\image_filters1\cmake-build-debug C:\Users\hp\image_filters1\cmake-build-debug C:\Users\hp\image_filters1\cmake-build-debug\CMakeFiles\target-2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/target-2.dir/depend
