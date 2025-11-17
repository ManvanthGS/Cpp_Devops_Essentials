cmake_minimum_required(VERSION 3.15)
project(static_code_analysis VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sources
add_executable(clang_format src/clang_format_example.cpp)

# Correct: Inject MinGW includes into the target
if (MINGW)
    target_include_directories(clang_format SYSTEM PRIVATE
        "C:/msys64/mingw64/include"
        "C:/msys64/mingw64/include/c++/15.2.0"
        "C:/msys64/mingw64/include/c++/15.2.0/x86_64-w64-mingw32"
        "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/15.2.0/include"
    )
endif()

# Optional clang-tidy integration
option(ENABLE_CLANG_TIDY "Run clang-tidy as part of build" OFF)

if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
        set_target_properties(clang_format PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
endif()
