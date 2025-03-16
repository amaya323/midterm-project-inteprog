#ifndef BOOK_H
#define BOOK_H
#include "../Function.h"
#include <iomanip>


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

    void setIsbn();
    void setTitle();
    void setAuthor();
    void setEdition();
    void setPublication();
    void setCategory();
    void printBook(const string& id) const;

};


#endif
