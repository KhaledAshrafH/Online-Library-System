# Online Library System

This project is a C++ program that simulates an online library system. It allows users to create accounts, browse books, borrow books, return books, and rate books. The program also keeps track of the inventory of books and the history of transactions.

## Classes

The project consists of four classes and their implementation:

- **Book**: This class represents a book object with attributes such as title, isbn, category, id, and author. It also has methods to print the book info, compare two books for equality, and rate the book.
- **User**: This class represents a user object with attributes such as email, name, age, and id. It also has methods to compare two users for equality, borrow a book, return a book, and print the user info.
- **BookList**: This class represents a list of books with an array of book objects and a size attribute. It also has methods to add a book, delete a book, search for a book by title or category, and print the list of books.
- **UserList**: This class represents a list of users with an array of user objects and a size attribute. It also has methods to add a user, delete a user, search for a user by email or name, and print the list of users.

## How to run

To run the program, you need to have a C++ compiler installed on your system. You can use any IDE or command-line tool to compile and execute the program. The main file is `online_library_system.cpp`, which contains the main function that creates an instance of the online library system and interacts with the user through a menu-driven interface. The other files are `book.h`, `book.cpp`, `user.h`, `user.cpp`, `booklist.h`, `booklist.cpp`, `userlist.h`, and `userlist.cpp`, which contain the class declarations and definitions.
