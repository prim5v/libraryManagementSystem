# Online Library Management System (C++)

## 📌 Project Overview
This project is a simple **Online Library Management System** implemented in **C++** using **Object-Oriented Programming (OOP)** principles.  
The system models a library where books can be added, removed, searched, borrowed, and returned by users.

The main goal of this project is to demonstrate a clear understanding of:
- Object-Oriented Design
- Encapsulation
- Class interaction
- Basic testing through positive and negative test cases

---

## 🧱 System Design

The system is built using three main classes:

### 1. Book
Represents a book in the library.

**Attributes:**
- `id` – unique identifier
- `title` – book title
- `author` – book author
- `isBorrowed` – borrowing status

**Methods:**
- Borrow a book
- Return a book
- Display book details

---

### 2. User
Represents a library user.

**Attributes:**
- `name` – user name

**Methods:**
- Get user name

---

### 3. Library
Manages a collection of books and user interactions.

**Responsibilities:**
- Add books to the library
- Remove books from the library
- Search books by title
- Borrow books
- Return books
- Display all available books

---

## ⚙️ Functionalities Implemented
- ✅ Add a book
- ✅ Remove a book
- ✅ Search for a book by title
- ✅ Borrow a book
- ✅ Return a book
- ✅ Prevent borrowing of already borrowed books
- ✅ Handle invalid operations (negative cases)

---

## 🧪 Test Cases
Test cases are implemented in the `main()` function and include:

### Positive Tests
- Adding books to the library
- Searching for an existing book
- Borrowing an available book
- Returning a borrowed book

### Negative Tests
- Borrowing a book that is already borrowed
- Searching for a non-existent book
- Removing a book that does not exist

These tests ensure the system behaves correctly under valid and invalid conditions.

---

## ▶️ How to Compile and Run

### Requirements
- C++ Compiler (g++)
- Terminal / Command Prompt

### Compilation
```bash
g++ library.cpp -o library
