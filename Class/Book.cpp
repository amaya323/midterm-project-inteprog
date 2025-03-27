//
// Created by Amaya on 3/16/2025.
//
#include "Book.h"
string Book::getId() const{
    return id;
}

string Book::getIsbn() const{
    return isbn;
}

string Book::getTitle() const{
    return title;
}

string Book::getAuthor() const{
    return author;
}

string Book::getEdition() const{
    return edition;
}

string Book::getPublication() const{
    return publication;
}

string Book::getCategory() const{
    return category;
}

//set book id;
void Book::setId(string id) {
    this->id = id;
}

//prompt user to enter ISBN and store the value
void Book::setIsbn() {
    isbn = getStringInput("Enter ISBN: ");
}

//prompt user to enter book title and store the value
void Book::setTitle() {
    title = getStringInput("Enter Title: ");
}

//prompt user to enter book author and store the value
void Book::setAuthor() {
    author = getStringInput("Enter Author: ");
}

//prompt user to enter book edition and store the value
void Book::setEdition() {
    edition = getStringInput("Enter Edition: ");
}

//prompt user to enter book publication and store the value
void Book::setPublication() {
    publication = getStringInput("Enter Publication: ");
}

//prompt user to enter book category and store the value
void Book::setCategory() {
    bool isValidCategory;
    do{ //get user input and validate
        category = getStringInput("Enter Category [Fiction/Non-Fiction]: ");
        category = toRemoveSpace(toLowerCase(category));
        if(category == "fiction"){
            category = "Fiction";
            isValidCategory = true;
        }else if(category == "non-fiction" || category == "nonfiction"){
            category = "Non-Fiction";
            isValidCategory = true;
        }else{
            cout << endl << "Error: Category not found." << endl << endl;
            isValidCategory = false;
        }
    }while(!isValidCategory); //loop until user inputs a correct category
}

//function to print book details of a book
void Book::printBook() const {
    cout << left << setw(10) << id
        << setw(15) << isbn
        << setw(40) << title
        << setw(30) << author
        << setw(10) << edition
        << setw(15) << publication
        << setw(10) << category << endl;
    cout << endl;
}





