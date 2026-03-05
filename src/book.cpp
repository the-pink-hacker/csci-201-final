#include "book.h"

using namespace std;

static const char* TAB = "    ";

Book::Book(string title, string author, Genre genre)
    : title(title), author(author), genre(genre), status(BookStatus::Available) {}

static const char* genreIntoString(const Genre genre) {
    switch (genre) {
        case Genre::Fiction:
            return "Fiction";
        case Genre::Science:
            return "Science";
        case Genre::Dystopia:
            return "Dystopia";
        case Genre::Horror:
            return "Horror";
        case Genre::NonFiction:
            return "Non-Fiction";
        case Genre::Mystery:
            return "Mystery";
        case Genre::Biography:
            return "Biography";
        default:
            throw runtime_error("Unknown genre");
    }
}

static const char* statusIntoString(const BookStatus status) {
    switch (status) {
        case BookStatus::Available:
            return "Available";
        case BookStatus::CheckedOut:
            return "Checked Out";
        default:
            throw runtime_error("Unknown status");
    }
}

void Book::displayInfo() const {
    cout << this;
}

void Book::setStatus(BookStatus status) {
    this->status = status;
}

BookStatus Book::getStatus() const {
    return status;
}

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author;
}

std::ostream& operator<<(std::ostream& stream, const Book& book) {
    stream << book.title << endl;
    stream << TAB << "Author: " << book.author << endl;
    stream << TAB << "Genre: " << genreIntoString(book.genre) << endl;
    stream << TAB << "Status: " << statusIntoString(book.status) << endl;
    return stream;
}
