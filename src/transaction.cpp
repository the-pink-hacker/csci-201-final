#include <chrono>

#include "transaction.h"

using namespace std;

Transaction::Transaction(uint32_t patronId, string bookTitle, BookStatus status)
    : patronId(patronId), bookTitle(bookTitle), status(status) {
        date = chrono::system_clock::to_time_t(
            chrono::system_clock::now()
        );
    }

ostream& operator<<(ostream& stream, const Transaction& transaction) {
    switch (transaction.status) {
        case BookStatus::CheckedOut:
            stream << "Checked Out";
            break;
        case BookStatus::Available:
            stream << "Returned";
            break;
    }

    stream << " Transaction " <<  ctime(&transaction.date);
    stream << "    Book Title: " << transaction.bookTitle << endl;
    stream << "    Patron ID: " << transaction.patronId << endl;
    return stream;
}
