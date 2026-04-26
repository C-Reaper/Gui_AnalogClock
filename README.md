# Project README

## Overview
This project is a simple analog clock application implemented in C. It uses a custom windowing system library, and supports building for Linux, Windows (both native and via Wine), and WebAssembly.

## Features
- Basic analog clock functionality
- Clock displays hours, minutes, and seconds with separate hands
- Customizable appearance through the use of a header file

## Project Structure
- `build/`: Contains executable files produced by Main.c
- `src/`: Contains source code, including `Main.c` as the entry point.
- `Makefile.linux`: Linux build configuration
- `Makefile.windows`: Windows build configuration
- `Makefile.wine`: Wine build configuration for building on Linux and running on Windows
- `Makefile.web`: Emscripten build configuration for WebAssembly

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects:
  - **Linux**: X11
  - **Windows**: WINAPI
  - **Wine**: Wine SDK
  - **Web**: Emscripten

## Build & Run
### Linux
To build and run the project on Linux, execute the following commands:

```bash
cd <Project>
make -f Makefile.linux all
make -f Makefile.linux exe
```

For a clean rebuild:

```bash
make -f Makefile.linux clean
make -f Makefile.linux all
```

### Windows (Native)
To build and run the project on Windows, execute the following commands:

```bash
cd <Project>
make -f Makefile.windows all
make -f Makefile.windows exe
```

For a clean rebuild:

```bash
make -f Makefile.windows clean
make -f Makefile.windows all
```

### Windows (Wine)
To build and run the project on Linux using Wine for Windows, execute the following commands:

```bash
cd <Project>
make -f Makefile.wine all
make -f Makefile.wine exe
```

For a clean rebuild:

```bash
make -f Makefile.wine clean
make -f Makefile.wine all
```

### WebAssembly
To build and run the project for WebAssembly, execute the following commands:

```bash
cd <Project>
make -f Makefile.web all
make -f Makefile.web exe
```

For a clean rebuild:

```bash
make -f Makefile.web clean
make -f Makefile.web all
```

These build instructions will allow you to compile and run the analog clock application on your chosen platform.