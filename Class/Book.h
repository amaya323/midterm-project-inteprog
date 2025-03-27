#ifndef BOOK_H
#define BOOK_H
#include "../Function.h"
#include <iomanip>


class Book {
private:
    //variable declarations
    string id;
    string isbn;
    string title;
    string author;
    string edition;
    string publication;
    string category;
public:
    //getter for the book attributes
    string getId() const;
    string getIsbn() const;
    string getTitle() const;
    string getAuthor() const;
    string getEdition() const;
    string getPublication() const;
    string getCategory() const;

    //setter for the book attributes
    void setId(string id);
    void setIsbn();
    void setTitle();
    void setAuthor();
    void setEdition();
    void setPublication();
    void setCategory();
    void printBook() const;

};


#endif
