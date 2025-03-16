//
// Created by Amaya on 3/16/2025.
//
#include "Book.h"

string Book::getIsbn() {
    return isbn;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getEdition() {
    return edition;
}

string Book::getPublication() {
    return publication;
}

string Book::getCategory() {
    return category;
}

void Book::setIsbn() {
    isbn = getStringInput("Enter ISBN: ");
}

void Book::setTitle() {
    title = getStringInput("Enter Title: ");
}

void Book::setAuthor() {
    author = getStringInput("Enter Author: ");
}

void Book::setEdition() {
    edition = getStringInput("Enter Edition: ");
}

void Book::setPublication() {
    publication = getStringInput("Enter Publication: ");
}

void Book::setCategory() {
    bool isValidCategory;
    do{
        category = getStringInput("Enter Category [Fiction/Non-Fiction]: ");
        if(toLowerCase(category) == "fiction"){
            category = "Fiction";
            isValidCategory = true;
        }else if(toLowerCase(category) == "non-fiction" || toLowerCase(category) == "non fiction"){
            category = "Non-Fiction";
            isValidCategory = true;
        }else{
            cout << endl << "Error: Category not found." << endl << endl;
            isValidCategory = false;
        }
    }while(!isValidCategory);
}


