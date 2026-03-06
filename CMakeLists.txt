cmake_minimum_required(VERSION 4.1.2)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

project(csci_201_final)

add_executable(csci_201_final
    src/main.cpp
    src/book.h
    src/book.cpp
    src/ebook.h
    src/ebook.cpp
    src/library.h
    src/library.cpp
    src/patron.h
    src/patron.cpp
    src/printed_book.h
    src/printed_book.cpp
    src/transaction.h
    src/transaction.cpp
)

install(TARGETS csci_201_final
    LIBRARY DESTINATION lib)
