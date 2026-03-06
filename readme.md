# CSCI 201 Final

## Building

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

## Running

The program takes three paths: the books csv, patrons csv, and a transaction log.
The books and patrons are parsed, then any books that are checked out, or returned,
are logged in the transaction file.

```sh
./csci_201_final books.txt patrons.txt transactions.txt
```

Upon running the program, the user is prompted whether to checkout or return a book. They can also select to exit and save the program. When checking out or returning a book, they are prompted their patron ID and the title of the book. This applies the action and creates a transaction that will go in the log on exit.
