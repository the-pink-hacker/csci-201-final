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
    public:
        Book(std::string title, std::string author, Genre genre);
        virtual ~Book() = default;

        // Pretty print
        virtual void displayInfo() const;
        void setStatus(BookStatus status);
        BookStatus getStatus() const;

        bool operator==(const std::string& title) const;
        // CSV format
        friend std::ostream& operator<<(std::ostream& stream, const Book& book);

    protected:
        std::string title;
        std::string author;
        Genre genre;
        BookStatus status;

        // CSV format
        virtual void outputStream(std::ostream& stream) const;
};

#endif
