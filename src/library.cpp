#include <iostream>
#include <fstream>
#include <stdexcept>

#include "ebook.h"
#include "library.h"
#include "printed_book.h"

using namespace std;

Library::~Library() {
    for (Book* book : books) {
        delete book;
    }
}

void Library::loadData(int argc, char *argv[]) {
    if (argc < 4) {
        throw runtime_error("Missing arguments");
    }

    cout << "Loading books from: " << argv[1] << endl;

    ifstream booksFile(argv[1]);

    if (!booksFile.is_open()) {
        throw runtime_error("Failed to open books file");
    }

    while (true) {
        string genreRaw;
        Genre genre;
        string title;
        string author;
        string type;

        if (!getline(booksFile, genreRaw, ',')) {
            // No more books
            break;
        }

        if (!getline(booksFile, title, ',')) {
            throw runtime_error("Book missing title");
        }

        if (!getline(booksFile, author, ',')) {
            throw runtime_error("Book missing author");
        }

        if (!getline(booksFile, type, ',')) {
            throw runtime_error("Book missing type");
        }

        Book* newBook;

        if (type == "Printed") {
            string pageCount;

            if (!getline(booksFile, pageCount)) {
                throw runtime_error("Printed book missing page count");
            }

            newBook = new PrintedBook(title, author, genre, stoul(pageCount));
        } else if (type == "EBook") {
            string size;

            if (!getline(booksFile, size)) {
                throw runtime_error("EBook missing size");
            }

            newBook = new EBook(title, author, genre, stod(size));
        } else {
            throw runtime_error("Unknown book type: " + type);
        }

        addBook(newBook);
    }

    booksFile.close();

    cout << "Loading patrons from: " << argv[2] << endl;

    ifstream patronsFile(argv[2]);

    if (!patronsFile.is_open()) {
        throw runtime_error("Failed to open patrons file");
    }

    while (true) {
        string id;
        string name;

        if (!getline(patronsFile, id, ',')) {
            // No more patrons
            break;
        }

        if (!getline(patronsFile, name)) {
            throw runtime_error("Patron missing name");
        }

        addPatron(Patron(name, stoul(id)));
    }

    patronsFile.close();
}

void Library::saveData(int argc, char *argv[]) {
    if (argc < 4) {
        throw runtime_error("Missing arguments");
    }

    ofstream file(argv[3]);

    if (!file.is_open()) {
        throw runtime_error("Failed to open transactions file");
    }

    for (const Transaction& transaction : transactions) {
        file << transaction;
    }

    transactions.clear();

    file.close();
}

void Library::addBook(Book* book) {
    books.push_back(book);
}

void Library::addPatron(const Patron& patron) {
    patrons.push_back(patron);
}

void Library::checkoutBook(uint32_t patronId, string title) {
    for (Book* book : books) {
        if (*book != title) {
            continue;
        }

        if (book->getStatus() == BookStatus::CheckedOut) {
            throw runtime_error("Book already checked out \"" + title + '"');
        }

        transactions.push_back(Transaction(patronId, title, BookStatus::CheckedOut));

        book->setStatus(BookStatus::CheckedOut);

        return;
    }

    throw runtime_error("Book isn't present \"" + title + '"');
}

void Library::returnBook(uint32_t patronId, string title) {
    for (Book* book : books) {
        if (*book != title) {
            continue;
        }

        if (book->getStatus() == BookStatus::Available) {
            throw runtime_error("Book wasn't checked out \"" + title + '"');
        }

        transactions.push_back(Transaction(patronId, title, BookStatus::Available));

        book->setStatus(BookStatus::Available);

        return;
    }

    throw runtime_error("Book isn't present \"" + title + '"');
}

void Library::displayBooks() const {
    cout << "=== Books ===" << endl;

    for (const Book* book : books) {
        book->displayInfo();
    }

    cout << "=== END BOOKS ===" << endl;
}

void Library::displayPatrons() const {
    cout << "Patrons:" << endl;

    for (const Patron& patron : patrons) {
        cout << "    ";
        patron.displayPatron();
        cout << endl;
    }
}
