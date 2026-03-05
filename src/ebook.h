#ifndef EBOOK_H
#define EBOOK_H

#include "book.h"

class EBook : public Book {
    public:
        EBook(std::string title, std::string author, Genre genre, double size);
        
        void displayInfo() const override;

        friend std::ostream& operator<<(std::ostream& stream, const EBook& book);
    private:
        double fileSizeMB;
};

#endif
