#ifndef EBOOK_H
#define EBOOK_H

#include "book.h"

class EBook : public Book {
    public:
        EBook(std::string title, std::string author, Genre genre, double fileSizeMB);
        
        void outputStream(std::ostream& stream) const override;
    private:
        double fileSizeMB;
};

#endif
