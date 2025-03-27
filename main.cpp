#include "imports.hpp" //import all class and function files

int main() {
    int choice;
    Library library;
    do {
        printTitle("Library Management System"); //display title
        library.printMenu();//display menu
        getValidatedInput("Choice: ", choice, 1, 7);//handle user input for menu

        //handle user choice
        if (choice == 1) { //add book to the library
            printTitle("Add Book");
            library.addBook();
        }else if (choice == 2) { //edit book in the library
            printTitle("Edit Book");
            library.editBook();
        }else if (choice == 3) { //search for a book in the library
            printTitle("Search Book");
            library.searchBook();
        }else if (choice == 4) { //delete a book in the library
            printTitle("Delete Book");
            library.deleteBook();
        }else if (choice == 5) { //view books in the library based on category
            printTitle("View Books By Category");
            library.viewBooksByCategory();
        }else if (choice == 6) { //view all books in the library
            printTitle("View All Books");
            library.viewAllBooks();
        }else { //exit
            return 0;
        }
        system("pause");
    }while (choice != 7); //loop unless user wants to exit
}
