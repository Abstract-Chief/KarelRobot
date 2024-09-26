This file contains:

-   Build requirements for Karel the robot
-   Installation instructions for Karel the robot
-   Where to get more information on Karel the robot
-   Notes about Karel the robot installation

## Build requirements for Karel the robot

-   gcc
-   cmake
-   make
-   ncurses (pdcurses if Windows)
-   gettext
-   pkg-config
-   check

## Installation instructions for Karel the robot

To compile this package:

1.  Normally, you just `cd` to the directory containing the cmake's `CMakeLists.txt` file.

2.  Type `mkdir build && cd build` to create `build` directory.

3.  Type `cmake ..` to create `Makefile`

4.  Type `make` to compile the library

5.  Type `make install` to install library and the documentation.

6.  You can remove the compiled library and object files from the directory by typing `make clean`.

## Notes about Karel the robot installation

Karel the robot has been run in the following configurations:

-   amd64-\*-linux
-   i386-\*-linux
-   Windows XP
-   Windows Vista
-   Windows 7

You will need an ANSI C Compiler (such as GCC), libc library and ncurses library to compile the source.
