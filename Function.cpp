#include "Function.h"

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

// Function to return string with characters in all lowercase
string toLowerCase(string str) {
    for (char &c: str) {
        if (isalpha(c)) {
            c = tolower(c);
        }
    }
    return str;
}

// Function to return string with characters in all uppercase
string toUpperCase(string str) {
    for (char &c: str) {
        if (isalpha(c)) {
            c = toupper(c);
        }
    }
    return str;
}

// Validates if input is a positive integer
bool validNumber(const string &input, int &output) {
    if (input.find('.') != string::npos) {
        cout << "Error: Please enter a whole number." << endl << endl;
        return false;
    }
    for (char c: input) {
        if (!isdigit(c) && (input[0] != '-')) {
            cout << "Error: Please enter a whole number." << endl << endl;
            return false;
        }
    }
    try {
        output = stoi(input);
        if (output <= 0) {
            cout << "Error: Please enter a value greater than 0." << endl << endl;
            return false;
        }
        return true;
    } catch (invalid_argument &e) {
        return false;
    } catch (out_of_range &e) {
        return false;
    }
}

// Gets validated integer input within a specified range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;
    do {
        cout << prompt;
        getline(cin, input);
        if (validNumber(input, output) && output >= minVal && output <= maxVal) {
            isValid = true;
        }
    } while (!isValid);
}

// Asks the user a Yes/No question and validates input
void askYesOrNo(string question, char &yOrN) {
    string placeholder;
    do {
        cout << endl << question;
        getline(cin, placeholder);
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n'));
}

//Function to removeWhiteSpace
string toRemoveSpace(string input) {
    string output;
    for (char &c: input) {
        if (!isspace(c)) {
            output+=c;
        }
    }
    return output;
}