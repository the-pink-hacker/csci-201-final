#include "printed_book.h"

using namespace std;

PrintedBook::PrintedBook(string title, string author, Genre genre, uint32_t pageCount)
    : Book(title, author, genre), pageCount(pageCount) {}

void PrintedBook::outputStream(ostream& stream) const {
    Book::outputStream(stream);
    stream << ',' << pageCount;
}

void PrintedBook::displayInfo() const {
    Book::displayInfo();
    cout << "    Size: " << pageCount << " pages" << endl;
}
