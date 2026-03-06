#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <cstdint>
#include <string>

#include "book.h"
#include "patron.h"
#include "transaction.h"

class Library {
    public:
        ~Library();
        void loadData(int argc, char *argv[]);
        void saveData(int argc, char *argv[]);
        void addBook(Book* book);
        void addPatron(const Patron& patron);
        void checkoutBook(uint32_t patronId, std::string title);
        void returnBook(uint32_t patronId, std::string title);
        void displayBooks() const;
        void displayPatrons() const;

    private:
        std::vector<Book*> books;
        std::vector<Patron> patrons;
        std::vector<Transaction> transactions;
};

#endif
