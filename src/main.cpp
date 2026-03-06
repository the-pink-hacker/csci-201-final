#include <iostream>

#include "library.h"

using namespace std;

// books.txt patrons.txt transactions.txt
int main(int argc, char *argv[]) {
    Library library;

    try {
        library.loadData(argc, argv);
        library.displayBooks();
        library.displayPatrons();

        library.checkoutBook(1, "The Great Gatsby");
        library.returnBook(1, "The Great Gatsby");
        library.saveData(argc, argv);
    } catch (const exception& e) {
        cerr << "Application Error: " << e.what() << endl;
    }

    return 0;
}
