#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cctype>
#include <string>

#include "library.h"

using namespace std;

void getTitlePatron(string& title, uint32_t patronId) {
    cout << "Patron ID" << endl;
    cin >> patronId;
    getline(cin, title); // Discarded
    cout << "Title?" << endl;
    getline(cin, title);
}

// books.txt patrons.txt transactions.txt
int main(int argc, char *argv[]) {
    Library library;

    try {
        library.loadData(argc, argv);
        library.displayBooks();
        library.displayPatrons();

        while (true) {
            cout << "Select action (Checkout/Return/Exit)?" << endl;

            string action;

            getline(cin, action);

            // https://stackoverflow.com/a/313990
            std::transform(
                    action.begin(),
                    action.end(),
                    action.begin(),
                    [](unsigned char c){ return std::tolower(c); }
            );

            string title;
            uint32_t patronId;

            if (action == "checkout") {
                getTitlePatron(title, patronId);
                library.checkoutBook(patronId, title);
            } else if (action == "return") {
                getTitlePatron(title, patronId);
                library.returnBook(patronId, title);
            } else if (action == "exit") {
                cout << "Exiting and saving..." << endl;
                break;
            } else {
                cout << "Unknown action: " << action << endl;
            }

        }
        library.saveData(argc, argv);
    } catch (const exception& e) {
        cerr << "Application Error: " << e.what() << endl;
    }

    return 0;
}
