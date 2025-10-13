# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Repository Overview

This is a C++ learning repository that's part of the "polilang" project. The repository contains progressively numbered exercises and examples covering fundamental to advanced C++ concepts, from basic Hello World programs to complex topics like file I/O, structs, pointers, and memory management.

## Build and Development Commands

### Basic Compilation
```bash
# Compile a single C++ file
g++ filename.cpp -o executable_name

# Compile with specific C++ standard
g++ -std=c++17 filename.cpp -o executable_name

# Compile with debug information and warnings
g++ -g -Wall filename.cpp -o executable_name

# Run the compiled program
./executable_name
```

### Using the Makefile Template
```bash
# Based on the template in 36-MakefileTamplate
# Create a Makefile with these common settings:
# - CC=g++
# - DEBUG=-g
# - OPT=-O2
# - WARN=-Wall
# - CCFLAGS=$(DEBUG) $(OPT) $(WARN)

make all       # Build the project
make clean     # Remove object files
make install   # Install to /usr/local/bin (requires sudo)
make uninstall # Remove from /usr/local/bin (requires sudo)
```

### Development Workflow
```bash
# Quick compile and run for testing
g++ filename.cpp && ./a.out

# Compile with modern C++ standards
g++ -std=c++17 -Wall -g filename.cpp -o test && ./test

# Check compiler version and C++ standard support
g++ --version
g++ -std=c++20 9999-CompilerVersion.cpp -o check_std && ./check_std
```

## Code Structure and Learning Progression

### File Naming Convention
- **01-99**: Sequential learning exercises with descriptive names
- **9999-**: Reference materials, compiler information, and advanced documentation
- **.h files**: Header files for specific exercises
- **.md files**: Documentation and detailed explanations

### Key Learning Topics Covered

**Foundation (01-10)**
- Basic syntax, namespaces, constants, variables, operators
- Function basics and headers

**Intermediate (11-25)**
- Type conversion, arrays, input/output, control structures
- Preprocessor directives, pointers, and memory management

**Advanced (26-35)**
- Vectors and dynamic arrays, strings manipulation
- File I/O (text and binary), structs, enums, environment interaction

### Important Architectural Patterns

**Memory Management Approach**
- Examples progress from basic stack allocation to dynamic memory with `new`/`delete`
- Advanced examples show RAII principles and smart pointer concepts
- File I/O examples demonstrate proper resource management

**Modern C++ Features**
- Uses `std::` namespace explicitly in early examples, then introduces `using namespace std`
- Demonstrates range-based for loops with `auto` keyword
- Shows proper exception handling in file operations

**Header Organization**
- Simple header files for function declarations (e.g., `10-Produto.h`, `14-AlteraArray.h`)
- Preprocessor directives and conditional compilation examples

## Key Reference Files

### Essential Documentation
- `9999-Aprofundamento.md`: Complete roadmap for advancing C++ skills, including modern C++ practices (RAII, STL, templates)
- `9999-SobrecargaFuncoes.md`: Function overloading concepts and best practices
- `31-Struct_vs_Classes.md`: Fundamental differences between structs and classes

### Compiler and Standards
- `9999-CompilerVersion.cpp`: Utility to check current C++ standard support
- `9999-SetLanguageStandard.md`: Guide for setting C++ standards in GCC/G++/Clang

### Build Configuration
- `36-MakefileTamplate`: Standard Makefile template with debug flags and optimization settings

## Development Guidelines

### Code Style
- Portuguese comments for learning context
- Explicit `std::` usage in foundational examples
- Progressive complexity with detailed inline documentation
- Error handling patterns shown in file I/O examples

### Testing Approach
- Each numbered file is a self-contained example
- Run individual examples to understand specific concepts
- Binary files (.bin) and temporary files are ignored via `.gitignore`

### Learning Path
1. **Master the Basics** (01-15): Syntax, variables, functions, arrays
2. **Control Structures** (16-23): Conditionals, loops, advanced flow control
3. **Advanced Features** (24-32): Preprocessor, pointers, structs, memory management
4. **System Programming** (33-35): File I/O, system interaction, graphics basics
5. **Reference Study**: Review `9999-*` files for deep understanding and modern practices

## Common Development Tasks

### Debugging
```bash
# Compile with debug symbols
g++ -g -Wall filename.cpp -o debug_version
gdb ./debug_version
```

### Performance Testing
```bash
# Compile with optimization
g++ -O2 -Wall filename.cpp -o optimized_version
time ./optimized_version
```

### Modern C++ Standards
```bash
# Use C++17 features
g++ -std=c++17 filename.cpp -o modern_version

# Use C++20 features (if supported)
g++ -std=c++20 filename.cpp -o modern_version
```