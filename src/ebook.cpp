#include "ebook.h"

using namespace std;

EBook::EBook(string title, string author, Genre genre, double fileSizeMB)
    : Book(title, author, genre), fileSizeMB(fileSizeMB) {}

void EBook::outputStream(ostream& stream) const {
    Book::outputStream(stream);
    stream << "    Size: " << fileSizeMB << " MB" << endl;
}
