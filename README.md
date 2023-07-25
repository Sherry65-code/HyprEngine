# HyprEngine

A library to implement OpenGL that works as a engine.

Sure, here's the same set of instructions written in Markdown format:

```markdown
# Project Dependencies - Installation Instructions

This project requires the following libraries to be installed on your system: GLEW, OpenGL, and freeglut. Below are the instructions for installing these libraries on different operating systems.

## Ubuntu / Debian-based Systems

1. Open a terminal.

2. Update the package list:
   ```bash
   sudo apt-get update
   ```

3. Install GLEW, OpenGL, and freeglut development libraries:
   ```bash
   sudo apt-get install libglew-dev libglu1-mesa-dev freeglut3-dev
   ```

## Fedora / Red Hat-based Systems

1. Open a terminal.

2. Update the package list:
   ```bash
   sudo dnf update
   ```

3. Install GLEW, OpenGL, and freeglut development libraries:
   ```bash
   sudo dnf install glew-devel mesa-libGLU-devel freeglut-devel
   ```

## macOS (using Homebrew)

1. Open a terminal.

2. Install Homebrew (if not already installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

3. Install GLEW using Homebrew:
   ```bash
   brew install glew
   ```

## Windows (using MSYS2 or MinGW)

1. Install MSYS2 or MinGW, if not already installed.

2. Open the MSYS2/MinGW terminal.

3. Update the package database:
   ```bash
   pacman -Syu
   ```

4. Install GLEW, OpenGL, and freeglut development packages:
   ```bash
   pacman -S mingw-w64-x86_64-glew mingw-w64-x86_64-glu mingw-w64-x86_64-freeglut
   ```

## Verifying Installation

After installing the required libraries, you can verify the installation by checking if the "GL/glew.h" header file is present on your system. You can do this using the `find` command (on Unix-based systems) or manually looking for it in the system include paths.

## Compiling the Project

Once the dependencies are installed successfully, you can compile your project using the following command:
```bash
make
```

