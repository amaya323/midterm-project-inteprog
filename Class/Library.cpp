//
// Created by Amaya on 3/16/2025.
//

#include "Library.h"
//helper function to look for if a book id input exists in the system
int Library::findBookId(string const& id) {
    for (int i = 0; i < numberOfBooks; i++) {
        if (toRemoveSpace(id) == toRemoveSpace(books[i]->getId())) {
            return i; //if id is found return index of the book in the array
        }
    }
    return -1; //if id is not found return -1
}

//helper function to print header for display of books
void Library::printBookHeader() {
    cout << left << setw(10) << "ID"
         << setw(15) << "ISBN"
         << setw(40) << "Title"
         << setw(30) << "Author"
         << setw(10) << "Edition"
         << setw(15) << "Publication"
         << setw(10) << "Category" << endl;
    cout << string(132, '-') << endl; //Table border
}

//helper function to set book id
void Library::setId(Book* book) {
    bool isValidId;
    string id;

    do{
        id = getStringInput("Enter ID: "); //prompt user to input id and get input
        id = toUpperCase(id);

        if (findBookId(id) != -1) { //check if the id is already taken [will return -1 if the id is not taken]
            cout << endl << "Error: Duplicate ID" << endl << endl;
            isValidId = false;
        } else { //if id is not taken, check if id is alphanumeric
            isValidId = true;
            for (char &c: id) { //check if id is alphanumeric
                if (!isalnum(c)) {
                    cout << endl << "Error: ID must be alphanumeric only" << endl << endl;
                    isValidId = false;
                    break;
                }
            }
        }
    }while(!isValidId); //loop until user input a valid id
    book->setId(id); //set book id if the id is not taken and is alphanumeric
}

//function to set category
void Library::setCategory(int index) {
    bool isValidCategory;
    bool isFiction;
    do{ //get user input and validate
        string category;
        category = getStringInput("Enter Category [Fiction/Non-Fiction]: ");
        category = toRemoveSpace(toLowerCase(category)); //remove spaces and lowercase

        if(category == "fiction"){ //check if fiction
            isFiction = true;
            isValidCategory = true;
        }else if(category == "non-fiction" || category == "nonfiction"){ //check if non-fiction
            isFiction = false;
            isValidCategory = true;
        }else{ //error message
            cout << endl << "Error: Category not found." << endl << endl;
            isValidCategory = false;
        }
    }while(!isValidCategory); //loop until user inputs a correct category

    if(isFiction){
        books[index] = new FictionBook();
    }else{
        books[index] = new NonFictionBook();
    }
    books[index]->setCategory(); // set category
}

//function to print menu
void Library::printMenu() {
    cout << "\t[1] Add Book" << endl;
    cout << "\t[2] Edit Book" << endl;
    cout << "\t[3] Search Book" << endl;
    cout << "\t[4] Delete Book" << endl;
    cout << "\t[5] View Books by Category" << endl;
    cout << "\t[6] View All Books" << endl;
    cout << "\t[7] Exit" << endl;
}

//function to add book to the library
void Library::addBook() {
    setCategory(numberOfBooks); //set category
    setId(books[numberOfBooks]); //set id
    books[numberOfBooks]->setIsbn(); //set isbn
    books[numberOfBooks]->setTitle(); //set title
    books[numberOfBooks]->setAuthor(); //set author
    books[numberOfBooks]->setEdition(); //set edition
    books[numberOfBooks]->setPublication(); //set publication

    numberOfBooks++; //keep track of the number of books in the system

    cout << endl << "Book added successfully!" << endl << endl;
}

//function to view books by category
void Library::viewBooksByCategory() {
    string category;

    bool isValidCategory;

    //validate input for category
    do {
        cout << "Enter Category [Fiction/Non-Fiction]: ";
        getline(cin, category);
        category = toRemoveSpace(toLowerCase(category));
        if (category == "fiction") { //check if fiction
            category = "Fiction";
            isValidCategory = true;
        }else if (category == "non-fiction" || category == "nonfiction" ) { //check if non-fiction
            category = "Non-Fiction";
            isValidCategory = true;
        }else { //error message is not fiction or non-fiction
            cout << endl << "Error: Category not found" << endl << endl;
            isValidCategory = false;
        }
    }while (!isValidCategory); //loop until user inputs a correct category

    bool found = false; //bool to check if there is a book in the chosen category

    //print books in the chosen category
    for (int i = 0; i < numberOfBooks; i++) {
        //print book header and the books if there is a book in the chosen category
        if (books[i]->getCategory() == category) {
            if (!found) {
                printBookHeader();
            }
            books[i]->printBook();
            found = true;
        }
    }

    //print message if there is no book in the chosen category
    if (!found) {
        cout << "No books found in the " << category << " category." << endl << endl;
    }
}

//function to search for books
void Library::searchBook(){
    //prompt and get id of the book the user want to search
    string id = getStringInput("Enter ID of Book: ");
    id = toUpperCase(id);

    //find index of the book [will return -1 if the book is not found]
    int index = findBookId(id);

    if(index == -1){ //print error message if the book is not found
        cout << endl << "Error: Book not found" << endl << endl;
    }else { //print book details if the book id is found
        printBookHeader();
        books[index]->printBook();
        cout << endl;
    }
}

//function to edit book details
void Library::editBook() {
    //prompt and get id of the book the user want to edit
    string id = getStringInput("Enter ID of Book: ");
    id = toUpperCase(id);

    //find index of the book [will return -1 if the book is not found]
    int index = findBookId(id);

    if(index == -1){ //print error message if the book is not found
        cout << endl << "Error: Book not found" << endl << endl;
    }else { //if the books is found continue with the editing of the details
        //print current book details
        cout << endl << "Current Book Details: " << endl << endl;
        printBookHeader();
        books[index]->printBook();

        //edit all book details except id
        cout << endl << "Edit Book: " << endl << endl;

        id = books[index]->getId();

        setCategory(index);

        books[index]->setId(id);

        books[index]->setIsbn();

        books[index]->setTitle();

        books[index]->setAuthor();

        books[index]->setEdition();

        books[index]->setPublication();

        //print new book details
        cout << endl << "New Book Details: " << endl << endl;
        printBookHeader();
        books[index]->printBook();

        cout << endl << "Book edited successfully!" << endl << endl;
    }
}

//function to delete a book in the library
void Library::deleteBook() {
    //prompt and get id of the book the user want to delete
    string id = getStringInput("Enter ID of Book: ");
    id = toUpperCase(id);

    //find index of the book [will return -1 if the book is not found]
    int index = findBookId(id);

    if(index == -1){ //if the book is not found print error
        cout << endl << "Error: Book not found" << endl << endl;
    }else { //if the book is found continue with the deletion
        char deleteBook;
        printBookHeader();
        books[index]->printBook(); //print book details
        cout << endl;

        //ask user if they want to continue deleting the book
        askYesOrNo("Do you want to delete this book? (Y/N): ", deleteBook);
        if (deleteBook == 'y') { //delete book if user say yes
            for (int i = index; i < numberOfBooks - 1; i++) { // adjust array to delete book
                books[i] = books[i + 1];
            }
            numberOfBooks--; //decrement number of books
            cout << endl << "Book deleted successfully!" << endl << endl;
        }
    }
}

//function to view all books in the library
void Library::viewAllBooks() {
    if (numberOfBooks == 0) { //print message if the number of books is 0
        cout << "No books available in the library.\n";
    }else { //print all books
        printBookHeader();
        for (int i = 0; i < numberOfBooks; i++) {
            books[i]->printBook();
        }
    }
}