#include <iostream>
#include "../Function.hpp"
using namespace std;

#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOK_H


class Book {
private:
    string isbn;
    string title;
    string author;
    string edition;
    string publication;
    string category;
public:
    string getIsbn();
    string getTitle();
    string getAuthor();
    string getEdition();
    string getPublication();
    string getCategory();

    void setId();
    void setIsbn();
    void setTitle();
    void setAuthor();
    void setEdition();
    void setPublication();
    void setCategory();
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
