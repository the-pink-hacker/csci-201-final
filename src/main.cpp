#include <iostream>

#include "book.h"

using namespace std;

int main() {
    Book test("Example Book", "John Doe", Genre::Biography);

    cout << test;

    return 0;
}
