#ifndef PRINTED_BOOK_H
#define PRINTED_BOOK_H

#include <cstdint>

#include "book.h"

class PrintedBook : public Book {
    public:
        PrintedBook(std::string title, std::string author, Genre genre, uint32_t pages);

        void displayInfo() const override;

        friend std::ostream& operator<<(std::ostream& stream, const PrintedBook& book);

    private:
        uint32_t pageCount;
};

#endif
