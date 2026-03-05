#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

enum class Genre {
    Fiction,
    Science,
    Dystopia,
    Horror,
    NonFiction,
    Mystery,
    Biography,
};

enum class BookStatus {
    Available,
    CheckedOut,
};

class Book {
    protected:
        std::string title;
        std::string author;
        Genre genre;
        BookStatus status;

    public:
        Book(std::string title, std::string author, Genre genre);
        virtual ~Book() = default;

        virtual void displayInfo() const;
        void setStatus(BookStatus status);
        BookStatus getStatus() const;

        bool operator==(const Book& other) const;
        friend std::ostream& operator<<(std::ostream& stream, const Book& book);
};

#endif
