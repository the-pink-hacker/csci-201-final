#ifndef PATRON_H
#define PATRON_H

#include <cstdint>
#include <string>
#include <iostream>
#include <vector>

#include "book.h"

class Patron {
    public:
        Patron(std::string name, uint32_t id);
        void borrowBook(Book* book);
        void returnBook(Book* book);

        bool operator==(const Patron& other) const;
        // Pretty print
        void displayPatron() const;
        // CSV
        friend std::ostream& operator<<(std::ostream& stream, const Patron& patron);

    private:
        std::string name;
        uint32_t id;
        std::vector<Book*> borrowedBooks;
};

#endif
