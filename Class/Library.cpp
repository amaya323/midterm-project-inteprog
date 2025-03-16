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
        id = toUpperCase(id);

        if (library.find(id) != library.end()) {
            cout << endl << "Error: Duplicate ID" << endl << endl;
            isValidId = false;
        } else {
            isValidId = true;
            for (char &c: id) {
                if (!isalnum(c)) {
                    cout << endl << "Error: ID must be alphanumeric only" << endl << endl;
                    isValidId = false;
                    break;
                }
            }
        }
    }while(!isValidId);
}

void Library::printBookHeader() {
    cout << left << setw(10) << "ID"
         << setw(15) << "ISBN"
         << setw(40) << "Title"
         << setw(30) << "Author"
         << setw(10) << "Edition"
         << setw(15) << "Publication"
         << setw(10) << "Category" << endl;
    cout << string(132, '-') << endl; // Table border
}


void Library::addBook() {
    Book book;
    book.setCategory();

    setId();

    book.setIsbn();

    book.setTitle();

    book.setAuthor();

    book.setEdition();

    book.setPublication();

    library[id] = book;

    cout << endl << "Book added successfully!" << endl << endl;
}

void Library::searchBook(){
    string id = getStringInput("Enter ID of Book: ");

    id = toUpperCase(id);

    if(library.find(id) == library.end()){
        cout << endl << "Error: Book not found" << endl << endl;
    }else {
        printBookHeader();
        library[id].printBook(id);
        cout << endl;
    }
}

void Library::editBook() {
    string id = getStringInput("Enter ID of Book: ");

    id = toUpperCase(id);
    if(library.find(id) == library.end()){
        cout << endl << "Error: Book not found" << endl << endl;
    }else {
        char editAgain;
        int choice;
        do {
            printBookHeader();
            library[id].printBook(id);
            cout << endl;

            cout << "Edit Detail" << endl;
            cout << "[1] ISBN" << endl;
            cout << "[2] Title" << endl;
            cout << "[3] Author" << endl;
            cout << "[4] Edition" << endl;
            cout << "[5] Publication" << endl;
            cout << "[6] Category" << endl;
            cout << "[7] Cancel" << endl;
            getValidatedInput("Choice: ", choice, 1, 7);

            if (choice == 1) {
                library[id].setIsbn();
            }else if (choice == 2) {
                library[id].setTitle();
            }else if (choice == 3) {
                library[id].setAuthor();
            }else if (choice == 4) {
                library[id].setEdition();
            }else if (choice == 5) {
                library[id].setPublication();
            }else if (choice == 6) {
                library[id].setCategory();
            }else {
                break;
            }
            askYesOrNo("Do want to edit another detail? (Y/N): ", editAgain);

        }while (editAgain == 'y');
        if (choice != 7) {
            cout << endl;
            printBookHeader();
            library[id].printBook(id);
        }
    }
}

void Library::deleteBook() {
    string id = getStringInput("Enter ID of Book: ");
    id = toUpperCase(id);
    if(library.find(id) == library.end()){
        cout << endl << "Error: Book not found" << endl << endl;
    }else {
        char deleteBook;
        cout << "ID: " << id << endl;
        library[id].printBook(id);
        cout << endl;

        askYesOrNo("Do you want to delete this book? (Y/N): ", deleteBook);
        if (deleteBook == 'y') {
            library.erase(id);
        }
    }
}

void Library::viewBooksByCategory() {
    string category;

    bool isValidCategory;

    do {
        cout << "Enter Category [Fiction/Non-Fiction]: ";
        getline(cin, category);
        if (toLowerCase(category) == "fiction") {
            category = "Fiction";
            isValidCategory = true;
        }else if (toLowerCase(category) == "non-fiction" || toLowerCase(category) == "non fiction") {
            category = "Non-Fiction";
            isValidCategory = true;
        }else {
            cout << endl << "Error: Category not found" << endl << endl;
            isValidCategory = false;
        }
    }while (!isValidCategory);

    bool found = false;

    for (const auto& entry : library) {
        Book book = entry.second;

        if (book.getCategory() == category) {
            if (!found) {
                printBookHeader();
            }
            book.printBook(entry.first);
            found = true;
        }
    }

    if (!found) {
        cout << "No books found in the " << category << " category." << endl;
    }
}

void Library::viewAllBooks() {
    if (library.empty()) {
        cout << "No books available in the library.\n";
    }else {
        printBookHeader();
        for (const auto& entry : library) {
            Book book = entry.second;
            book.printBook(entry.first);
        }
    }
}





