#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* ================= BOOK CLASS ================= */
class Book {
private:
    int id;
    string title;
    string author;
    bool isBorrowed;

public:
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isBorrowed = false;
    }

    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool getStatus() const {
        return isBorrowed;
    }

    void borrowBook() {
        isBorrowed = true;
    }

    void returnBook() {
        isBorrowed = false;
    }

    void display() const {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isBorrowed ? "Borrowed" : "Available")
             << endl;
    }
};

/* ================= USER CLASS ================= */
class User {
private:
    string name;

public:
    User(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }
};

/* ================= LIBRARY CLASS ================= */
class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book removed successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }

        for (const Book& book : books) {
            book.display();
        }
    }

    void searchBook(const string& title) const {
        bool found = false;

        for (const Book& book : books) {
            if (book.getTitle() == title) {
                book.display();
                found = true;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    void borrowBook(int id, User& user) {
        for (Book& book : books) {
            if (book.getId() == id) {
                if (!book.getStatus()) {
                    book.borrowBook();
                    cout << user.getName() << " borrowed the book successfully.\n";
                } else {
                    cout << "Book is already borrowed.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id, User& user) {
        for (Book& book : books) {
            if (book.getId() == id) {
                if (book.getStatus()) {
                    book.returnBook();
                    cout << user.getName() << " returned the book successfully.\n";
                } else {
                    cout << "Book was not borrowed.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

/* ================= MAIN (TEST CASES) ================= */
int main() {
    Library library;
    User user("Alice");

    // Test cases
    library.addBook(Book(1, "C++ Basics", "Bjarne"));
    library.addBook(Book(2, "Data Structures", "Mark"));
    library.addBook(Book(3, "Algorithms", "CLRS"));

    cout << "\n--- All Books ---\n";
    library.displayBooks();

    cout << "\n--- Search Book ---\n";
    library.searchBook("C++ Basics");

    cout << "\n--- Borrow Book ---\n";
    library.borrowBook(1, user);

    cout << "\n--- Borrow Same Book Again (Negative Test) ---\n";
    library.borrowBook(1, user);

    cout << "\n--- Return Book ---\n";
    library.returnBook(1, user);

    cout << "\n--- Remove Book ---\n";
    library.removeBook(2);

    cout << "\n--- Final Library State ---\n";
    library.displayBooks();

    return 0;
}
