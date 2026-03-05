#include "printed_book.h"

using namespace std;

PrintedBook::PrintedBook(string title, string author, Genre genre, uint32_t pageCount)
    : Book(title, author, genre), pageCount(pageCount) {}

void PrintedBook::displayInfo() const {
    cout << this;
}

std::ostream& operator<<(std::ostream& stream, const PrintedBook& book) {
    stream << (Book)book;
    stream << "    Size: " << book.pageCount << " pages" << endl;
    return stream;
}
