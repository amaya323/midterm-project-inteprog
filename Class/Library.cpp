//
// Created by Amaya on 3/16/2025.
//

#include "Library.h"

string Library::getId() {
    return id;
}

void Library::setId() {
    bool isValidId;

    do{
        id = getStringInput("Enter ID: ");

        for(char& c: id){
            if(isalpha(c)){
                c = toupper(c);
            }
        }

        if (Library.find(id) != Library.end()) {
            cout << endl << "Error: Duplicate ID" << endl << endl;
            isValidId = false;
        }else{
            isValidId = true;
        }
    }while(!isValidId);
}

void Library::addBook() {
    Book book;
    book.setCategory();

    setId();

    book.setTitle();

    book.setAuthor();

    book.setEdition();

    book.setPublication();

    Library[id] = book;
}

void Library::searchBook(){
    string id = getStringInput("Enter ID of Book: ");
    if(Library.find(id) != Library.end()){
        cout << endl << "Error: ID not found" << endl << endl;
    }
}

void Library::editBook() {

}



