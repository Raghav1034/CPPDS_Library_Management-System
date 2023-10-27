
# Library Management System using Hash Table

This C++ program implements a simple Library Management System using a hash table data structure. The system allows users to manage a library by performing operations such as displaying books, issuing books to students, returning books, searching for students, and displaying the hash table.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [How to Use](#how-to-use)
- [Code Explanation](#code-explanation)
- [Improvements](#improvements)
- [Contributing](#contributing)
- [License](#license)

- ## Introduction

The Library Management System uses a Hash Table to efficiently manage and search for student records and their issued books. It offers the following functionalities:

- Display a list of available books.
- Issue a book to a student.
- Return a book.
- Search for a student and the book they have issued.
- Display the current state of the Hash Table.

## Components

The program is implemented with the following key components:

- `HashTable` class: Represents the Hash Table and its operations.
- `books` and `book_id` arrays: Store book names and their corresponding IDs.
- `checkPrime` and `getPrime` functions: Calculate prime numbers for table size.
- `hashFunction` method: Determines the index for a given key.
- `displayBooks` method: Displays the list of available books.
- `bookThere` method: Checks if a book is available for issuing.
- Menu-driven interface: Users can choose options to interact with the system.

The program provides a user-friendly menu-driven interface. When you run the program, you will see a menu with the following options:

1. Display Books
2. Issue Book
3. Return Book
4. Search for Student
5. Display Hash Table
6. Exit

You can select an option by entering the corresponding number. Depending on your choice, the program will display a list of books, allow you to issue or return a book, search for a student's issued book, display the Hash Table, or exit the program.

## Usage

1. Compile and run the program.
2. Follow the menu options to interact with the Library Management System.
3. Use the provided book IDs to issue or return books.

## Example

Here's an example of using the program:

1. Display Books
   - You can view a list of available books and their IDs.

2. Issue Book
   - Enter the student's PRN.
   - Enter the book's ID to issue.
   - If the book is available, it will be issued to the student.

3. Return Book
   - Enter the student's PRN to return the book.

4. Search for Student
   - Enter the student's PRN to find the book they have issued.

5. Display Hash Table
   - View the current state of the Hash Table.

6. Exit
   - Choose this option to exit the program.

## Features
- Display available books with their titles and IDs.
- Issue books to students, ensuring a book can only be issued once by a student.
- Return books, tracking the book's location for efficient return.
- Search for students and find the issued book.
- Display the internal structure of the hash table for efficient book management.
- Use of prime-sized arrays for the hash table to minimize collisions and enhance performance.

## Prerequisites
- C++ compiler (e.g., g++)
- Terminal or IDE for running the code


5. Follow the on-screen instructions to interact with the Library Management System.

## Code Explanation

The code consists of a C++ program structured as follows:

- `HashTable` Class:
 - Manages the library, including book storage and hash table operations.
 - Keeps track of book titles and IDs.
 - Enforces constraints on book issuance and return.

- `main()` Function:
 - Implements the menu for library management operations.
 - Utilizes the `HashTable` class for book management.
 - Allows users to interact with the system and perform various actions.

For a detailed explanation of how the code works, please refer to the [Code Explanation](#code-explanation) section in the README.

## Improvements
The Library Management System can be further improved with the following enhancements:
- User authentication and access control.
- Database integration for storing book and student information.
- Enhanced error handling and data validation.
- Implementing a dynamic array resizing strategy for the hash table.

## Contributing
If you'd like to contribute to this project, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bug fix: `git checkout -b feature/my-feature`.
3. Commit your changes: `git commit -m 'Add a new feature'`.
4. Push to your branch: `git push origin feature/my-feature`.
5. Open a pull request with a description of your changes.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


