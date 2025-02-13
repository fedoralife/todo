cmake_minimum_required(VERSION 3.10)
project(obang VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Ensure the compile_commands.json file is generated
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set output directory within the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (WIN32)
    message(STATUS "Configuring for Windows...")
    if (MSVC)
        set(CMAKE_GENERATOR_PLATFORM x64)
    else()
        find_program(GCC_BIN gcc)
        find_program(CLANG_BIN clang)
        if (GCC_BIN)
            set(CMAKE_C_COMPILER ${GCC_BIN})
        elseif (CLANG_BIN)
            set(CMAKE_C_COMPILER ${CLANG_BIN})
        else()
            message(FATAL_ERROR "Neither MSVC, GCC, nor Clang found! Please install a compiler.")
        endif()
    endif()
elseif (APPLE)
    set(CMAKE_C_COMPILER clang)
elseif (UNIX)
    find_program(GCC_BIN gcc)
    find_program(CLANG_BIN clang)
    if (GCC_BIN)
        set(CMAKE_C_COMPILER ${GCC_BIN})
    elseif (CLANG_BIN)
        set(CMAKE_C_COMPILER ${CLANG_BIN})
    else()
        message(FATAL_ERROR "Neither GCC nor Clang found! Please install a compiler.")
    endif()
endif()
find_package(raylib QUIET)

if(NOT raylib_FOUND)
    message(STATUS "Raylib not found, fetching from source...")

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0  # Change to the desired version
    )

    FetchContent_MakeAvailable(raylib)
endif()

# Locate source files
file(GLOB SOURCES "src/*.c")
file(GLOB SQLITE_SRC "vendor/sqlite3.c")  # Add the sqlite3 source file
message(STATUS "Test include directories: ${CMAKE_CURRENT_SOURCE_DIR}/test1")

file(GLOB TEST "test1/test.c")  # Adjusted to point to your test source files

# Add executable target with source files, including sqlite3.c
add_executable(obang ${SOURCES} ${SQLITE_SRC} ${TEST})

# Link header file directories
target_include_directories(obang PRIVATE include raylib vendor test1)  # Make sure to include test1 where the header is located
target_link_libraries(obang raylib)

if (MSVC)
    target_compile_options(obang PRIVATE /W4 /permissive-)
else()
    target_compile_options(obang PRIVATE -Wall -Wextra -Wpedantic)
endif()

