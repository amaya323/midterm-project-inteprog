#include <iostream>
using namespace std;
#include <regex>

// Prints a formatted title with a border
void printTitle(const string &title) {
    system("cls"); // Clear console screen (Windows-specific)
    int length = title.length();
    int padding = max(10, 30 - length);
    string border(padding, '=');
    cout << "\n" << border << " " << title << " " << border << "\n" << endl;
}

// Function to get string input of user
string getStringInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    return input;
}