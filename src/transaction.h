#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstdint>
#include <iostream>

#include "book.h"

class Transaction {
    public:
        Transaction(uint32_t patronId, std::string bookTitle, BookStatus status);

        friend std::ostream& operator<<(std::ostream& stream, const Transaction& transaction);

    private:
        uint32_t patronId;
        std::string bookTitle;
        std::time_t date;
        BookStatus status;
};

#endif
