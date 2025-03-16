//
// Created by Amaya on 3/16/2025.


#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include <map>

class Library {
private:
    map<string, Book> library;
    string id;

public:
    string getId();

    void setId();

    void printBookHeader();

    void addBook();

    void editBook();

    void searchBook();

    void deleteBook();

    void viewBooksByCategory();

    void viewAllBooks();
};


#endif
