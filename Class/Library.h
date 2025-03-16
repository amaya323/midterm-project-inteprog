//
// Created by Amaya on 3/16/2025.


#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#include "Book.h"
#include <map>

class Library {
private:
    string id;
    map<string, Book> Library;
public:
    string getId();

    void setId();

    void addBook();

    void editBook();

    void searchBook();

    void viewBooksByCategory();

    void viewAllBooks();

};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
