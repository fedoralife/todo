# Project Manager for C

A task management system built in C with a graphical user interface and database integration.

## Overview

This project is a task management application that combines the power of CMake for build management, Raylib for GUI rendering, and SQLite for data persistence. It provides basic task manipulation features with user authentication.

## Dependencies

- [CMake](https://cmake.org/documentation/) - Build system and project management
- [Raylib](https://www.raylib.com/) - Graphical user interface framework
- [SQLite](https://www.sqlite.org/) - Local database management

## Features

- Task Management
  - Create, Read, Update, and Delete (CRUD) operations for tasks
  - Task categorization and organization
  - Task status tracking

- User Interface
  - Modern and intuitive graphical interface using Raylib
  - Easy-to-navigate task views
  - Interactive task management

- Data Persistence
  - Secure local storage using SQLite
  - Efficient data retrieval and management
  - Data backup capabilities

- Security
  - User authentication system
  - Secure data access

## Building the Project

### Prerequisites

- C compiler (GCC recommended)
- CMake (version 3.x or higher)
- Raylib development libraries
- SQLite development libraries

### Build Instructions

#### Manual Build

1. Clone the repository:
   ```bash
   git clone https://github.com/tsdios/obang.git
   cd obang
   ```

2. Create and navigate to the build directory:
   ```bash
   mkdir build
   cd build
   ```

3. Generate build files and compile:
   ```bash
   cmake ..
   make
   ```

4. Run the application:
   ```bash
   ./obang
   ```
### Build Instructions
#### Using the build script

1. Clone the repository:
   ```bash
   git clone https://github.com/tsdios/obang.git
   cd obang
   ```

2. Run the build script:
   ```bash
   ./scripts/build.sh
   ```

3. Run the application:
   ```bash
   ./scripts/run.sh
   ```

## Usage

[Add specific instructions on how to use the application, including:
- How to create tasks
- How to manage tasks
- How to navigate the GUI
- User authentication process]

## Contributing

[Add contribution guidelines, if applicable]

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.




