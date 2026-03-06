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

void Book::outputStream(ostream& stream) const {
    stream << genreIntoString(genre) << ',' << title << ',' << author << ',';
}

void Book::displayInfo() const {
    cout << title << endl;
    cout << TAB << "Author: " << author << endl;
    cout << TAB << "Genre: " << genreIntoString(genre) << endl;
    cout << TAB << "Status: " << statusIntoString(status) << endl;
}

void Book::setStatus(BookStatus status) {
    this->status = status;
}

BookStatus Book::getStatus() const {
    return status;
}

bool Book::operator==(const string& title) const {
    return this->title == title;
}

ostream& operator<<(ostream& stream, const Book& book) {
    book.outputStream(stream);
    return stream;
}
