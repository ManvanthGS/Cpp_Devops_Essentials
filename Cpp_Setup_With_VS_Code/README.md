# C++ on Windows (MSYS2) and Visual Studio Code — Quick Setup

This README explains how to install a modern GCC toolchain on Windows using MSYS2 (UCRT recommended) and how to configure Visual Studio Code to compile and debug C++ files.

## Overview (quick)
- Install MSYS2, update packages.
- Install the UCRT toolchain (recommended) or mingw64 if you prefer.
- Add MSYS2 bin to PATH.
- Install VS Code + C/C++ extension and configure tasks/launch for building and debugging.

## 1. Install MSYS2 and GCC (UCRT recommended)
1. Download & install MSYS2: https://www.msys2.org/
2. Open the MSYS2 MSYS terminal and update the package DB and core packages:
   - pacman -Syu
   - Close the terminal and re-open (important). Then run:
   - pacman -Su
3. Install the UCRT toolchain (recommended for new projects):
   - pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-gdb
   (If you prefer the traditional MinGW runtime, remove all occurences of `ucrt` from the command and run.)
4. Add MSYS2 bin to PATH:
   - Open System Properties → Environment Variables → Path → Edit → New
   - Add: C:\msys64\ucrt64\bin  (or PATH to your ucrt64 bin directory)
   - (If you installed mingw64 instead: C:\msys64\mingw64\bin)
   - Make sure you open a new terminal after changing PATH.

## 2. Verify installation
Open a new Command Prompt or VS Code integrated terminal and run:
```sh
gcc --version
g++ --version
gdb --version
```
Compile a quick test:
```sh
g++ -std=c++17 -O2 -o hello.exe hello.cpp
.\hello.exe
```

## 3. Install Visual Studio Code and the C/C++ extension
1. Install VS Code: https://code.visualstudio.com/
2. In VS Code, install the "C/C++" extension by Microsoft.
3. Install "Code Runner" for quick runs, but tasks are preferred for reproducible builds.
4. To quickly run the C++ file right click inside the cpp file and click on run code (NOTE: This will work only after installing Code Runner).

## 4. Recommended VS Code configuration
Create a .vscode folder in your project and add the following snippets. Adjust paths if you installed MSYS2 to a different location.

- c_cpp_properties.json (IntelliSense)
```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": [
        "${workspaceFolder}/**"
      ],
      "compilerPath": "C:\\msys64\\ucrt64\\bin\\g++.exe",
      "cStandard": "c11",
      "cppStandard": "c++20",
      "intelliSenseMode": "gcc-x64"
    }
  ],
  "version": 4
}
```

- tasks.json (build task using g++)
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "g++",
      "args": [
        "-g",
        "-std=c++20",
        "${file}",
        "-o",
        "${fileDirname}\\bin\\${fileBasenameNoExtension}.exe"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": [
        "$gcc"
      ]
    }
  ]
}
```

- launch.json (debug with gdb)
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "gdb (Windows)",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}\\bin\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "C:\\msys64\\ucrt64\\bin\\gdb.exe",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "build", // Ensure this matches the label in tasks.json
    }
  ]
}
```
Notes:
- Adjust the paths to `g++.exe` and `gdb.exe` if you installed mingw64 instead of ucrt64.
- Use forward slashes `/` or escaped backslashes `\\` in JSON paths.
- If your installation directory is different, then the path must be updated to that directory.

## 5. Build & Run from VS Code
- Open a C++ file.
- Run the build task: Terminal → Run Build Task (or Ctrl+Shift+B).
- Start debugging: Run and Debug → Select "gdb (Windows)" → Start Debugging (F5).
- To run without debugging, build using the task and run the generated .exe from the integrated terminal:
  - .\\yourprogram.exe
- If you have installed code runner you can run the code directly using the run button and selecting the desired configuration.

## 6. Quick tips
- Use ucrt64 environment for new projects to follow universal standard, for legacy code use mingw64 environment which is compatible with older versions.
- You can add multiple configurations using tasks.json and launch.json to cater for different builds (Debug/Release) and for different compilers or architectures.
- If IntelliSense cannot find headers, ensure `"compilerPath"` points to the installed g++.exe and that the MSYS2 bin directory is in PATH or specified in includePath.
- If gdb cannot start, check the `miDebuggerPath` points to gdb.exe in the same environment (ucrt64/mingw64) you used for g++.
- For multi-file projects consider using CMake (msys2 packages include cmake).