#include <algorithm>

#include "patron.h"

using namespace std;

Patron::Patron(string name, uint32_t id)
    : name(name), id(id) {}

void Patron::borrowBook(Book* book) {
    borrowedBooks.push_back(book);
}

void Patron::returnBook(Book* book) {
    auto i = find(borrowedBooks.begin(), borrowedBooks.end(), book);

    if (i == borrowedBooks.end()) {
        throw runtime_error("Patron cannot return book");
    }

    borrowedBooks.erase(i);
}

bool Patron::operator==(const Patron& other) const {
    return id == other.id && name == other.name;
}

void Patron::displayPatron() const {
    cout << name << " (" << id << ")";
}

ostream& operator<<(ostream& stream, const Patron& patron) {
    stream << patron.id << ',' << patron.name;
    return stream;
}
