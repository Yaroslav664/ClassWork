#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string isbn;
    bool available;

public:
    Book(const string& t, const string& a, int y, const string& i)
        : title(t), author(a), year(y), isbn(i), available(true) {}

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailable(bool isAvailable) {
        available = isAvailable;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void AddBook(const Book& book) {
        books.push_back(book);
    }

    void RemoveBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                books.erase(it);
                break;
            }
        }
    }

    void SearchByAuthor(const string& author) {
        cout << "Books by author '" << author << "':" << endl;
        for (const Book& book : books) {
            if (book.getAuthor() == author) {
                cout << "Title: " << book.getTitle() << ", ISBN: " << book.getISBN() << endl;
            }
        }
    }

    void SearchByTitle(const string& title) {
        cout << "Books with title '" << title << "':" << endl;
        for (const Book& book : books) {
            if (book.getTitle() == title) {
                cout << "Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << endl;
            }
        }
    }

    void ListAvailableBooks() {
        cout << "Available books:" << endl;
        for (const Book& book : books) {
            if (book.isAvailable()) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << endl;
            }
        }
    }
};

int main() {
    Library library;

    Book book1("Book1", "Author1", 2020, "ISBN1");
    Book book2("Book2", "Author2", 2019, "ISBN2");
    Book book3("Book3", "Author1", 2021, "ISBN3");

    library.AddBook(book1);
    library.AddBook(book2);
    library.AddBook(book3);

    int choice;
    string searchValue;

    do {
        cout << "Library Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book by ISBN" << endl;
        cout << "3. Search by Author" << endl;
        cout << "4. Search by Title" << endl;
        cout << "5. List Available Books" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string title, author, isbn;
            int year;

            cout << "Enter title: ";
            cin >> title;
            cout << "Enter author: ";
            cin >> author;
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter ISBN: ";
            cin >> isbn;

            Book newBook(title, author, year, isbn);
            library.AddBook(newBook);
            cout << "Book added to library." << endl;
        }
        break;

        case 2:
        {
            cout << "Enter ISBN of the book to remove: ";
            cin >> searchValue;
            library.RemoveBook(searchValue);
            cout << "Book removed from library." << endl;
        }
        break;

        case 3:
        {
            cout << "Enter author to search for: ";
            cin >> searchValue;
            library.SearchByAuthor(searchValue);
        }
        break;

        case 4:
        {
            cout << "Enter title to search for: ";
            cin >> searchValue;
            library.SearchByTitle(searchValue);
        }
        break;

        case 5:
            library.ListAvailableBooks();
            break;

        case 6:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);
}
