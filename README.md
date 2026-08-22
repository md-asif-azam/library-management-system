# library-management-system

A beginner-friendly Library Management System built in C++ as my first major programming project.

The project started as a simple console application and was gradually expanded to include object-oriented programming, data structures, file persistence, input validation, and a modular multi-file architecture.

## Features

- Add books
- Display all books
- Search books by ID
- Issue books
- Return books
- Remove books
- Sort books by ID
- Prevent duplicate Book IDs
- Validate integer input
- Handle empty library states
- Persistent book storage using `books.txt`
- Load saved books when the program starts
- Multi-file C++ project structure

## Concepts Used

- C++
- Object-Oriented Programming
- Classes and Objects
- `vector`
- Linear Search
- Sorting with `std::sort`
- File I/O
- `ifstream` and `ofstream`
- `stringstream`
- References
- `const`
- Input validation
- Functions
- Header files and implementation files
- Git and GitHub

## Project Structure

```text
LibraryManagementSystem/
│
├── main.cpp        # Program entry point and menu
├── Book.h          # Book class
├── Library.h       # Function declarations
├── Library.cpp     # Library functionality
├── books.txt       # Persistent book data
└── README.md       # Project documentation
