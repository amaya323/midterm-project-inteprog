//
// Created by Amaya on 3/16/2025.


#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "NonFictionBook.h"
#include "FictionBook.h"
class Library {
private:
    //variable declarations
    Book* books[10] = {}; //books
    int numberOfBooks = 0; //keep track of books

    //helper functions for the public functions, only accessible inside the class
    int findBookId(const string& id);
    void printBookHeader();
    void setId(Book* book);
    void setCategory(int index);

public:
    //functions that are accessible outside the class
    void printMenu();

    void addBook();

    void editBook();

    void searchBook();

    void deleteBook();

    void viewBooksByCategory();

    void viewAllBooks();
};


#endif
