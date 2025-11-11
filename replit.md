# HinLIBS - Library Management System

## Overview
HinLIBS is a C++ library management system that demonstrates object-oriented programming concepts. The project manages a catalogue of various items including fiction books, non-fiction books, magazines, movies, and video games.

## Project Type
Console Application (CLI)

## Language & Tools
- **Language**: C++ (C++11)
- **Compiler**: Clang++ 14
- **Build System**: Direct compilation with clang++

## Project Structure
```
.
├── main.cpp           # Main application with Catalogue class
├── ObjectDefs.h       # Item class hierarchy (books, magazines, movies, video games)
├── UserDefs.h         # Patron class definition
└── README.md          # Original project README
```

## Key Classes
- **Item**: Base class for all library items
- **FictionBook**: Fiction books with ISBN
- **NonFictionBook**: Non-fiction books with ISBN and Dewey Decimal
- **Magazine**: Magazines with issue numbers and publication dates
- **Movie**: Movies with genre and rating
- **VideoGame**: Video games with genre and rating
- **Catalogue**: Manages collection of items
- **Patron**: Library patron/user information

## How to Run
The project is configured to compile and run automatically using the workflow. Click the "Run" button to compile with clang++ and execute the program.

**Compilation command**: `clang++ -std=c++11 main.cpp -o main && ./main`

## Current State
- Console application that displays a pre-populated catalogue
- Demonstrates polymorphism and operator overloading
- Basic foundation for a library management system

## Date Imported
November 11, 2025
