#include <iostream>

#include "book.h"
#include "ebook.h"
#include "printed_book.h"

using namespace std;

int main() {
    cout << Book("Example Book", "John Doe", Genre::Biography);
    cout << EBook("Example EBook", "John Doe", Genre::Biography, 12.34);
    cout << PrintedBook("Example Printed Book", "John Doe", Genre::Biography, 1234);

    return 0;
}
