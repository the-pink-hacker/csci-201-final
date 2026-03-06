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
