#include "ebook.h"

using namespace std;

EBook::EBook(string title, string author, Genre genre, double fileSizeMB)
    : Book(title, author, genre), fileSizeMB(fileSizeMB) {}

void EBook::displayInfo() const {
    cout << this;
}

std::ostream& operator<<(std::ostream& stream, const EBook& book) {
    stream << (Book)book;
    stream << "    Size: " << book.fileSizeMB << " MB" << endl;
    return stream;
}
