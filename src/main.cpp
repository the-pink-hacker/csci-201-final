#include <iostream>

#include "book.h"
#include "ebook.h"

using namespace std;

int main() {
    cout << Book("Example Book", "John Doe", Genre::Biography);
    cout << EBook("Example EBook", "John Doe", Genre::Biography, 12.34);

    return 0;
}
