#include "imports.hpp"

int main() {
    int choice;
    Library library;
    do {
        printTitle("Library Management System");
        printMenu();
        getValidatedInput("Choice: ", choice, 1, 7);
        if (choice == 1) {
            printTitle("Add Book");
            library.addBook();
        }else if (choice == 2) {
            printTitle("Edit Book");
            library.editBook();
        }else if (choice == 3) {
            printTitle("Search Book");
            library.searchBook();
        }else if (choice == 4) {
            printTitle("Delete Book");
            library.deleteBook();
        }else if (choice == 5) {
            printTitle("View Books By Category");
            library.viewBooksByCategory();
        }else if (choice == 6) {
            printTitle("View All Books");
            library.viewAllBooks();
        }else {
            return 0;
        }
        system("pause");
        cout << endl <<"Press any key to Continue" << endl ;
    }while (choice != 7);
}
