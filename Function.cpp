#include "Function.h"

// Prints a formatted title with a border
void printTitle(const string &title) {
    system("cls"); // Clear console screen (Windows-specific)
    int length = title.length(); // Get the length of the title
    int padding = max(10, 30 - length); // Calculate padding
    string border(padding, '=');
    cout << "\n" << border << " " << title << " " << border << "\n" << endl; // Print the title
}

// Function to get string input of user
string getStringInput(string prompt) {
    string input;
    cout << prompt; // Print the prompt
    getline(cin, input); // Get user input
    return input;
}

// Function to return string with characters in all lowercase
string toLowerCase(string str) {
    for (char &c: str) { // Iterate through the string
        if (isalpha(c)) {  // Check if the character is a letter
            c = tolower(c); // Convert the character to lowercase
        }
    }
    return str;
}

// Function to return string with characters in all uppercase
string toUpperCase(string str) {
    for (char &c: str) { // Iterate through the string
        if (isalpha(c)) { // Check if the character is a letter
            c = toupper(c); // Convert the character to uppercase
        }
    }
    return str;
}

// Validates if input is a positive integer
bool validNumber(const string &input, int &output, int minVal, int maxVal) {
    if (input.find('.') != string::npos) { // Check if the input contains a decimal point
        cout << "Error: Please enter a whole number." << endl << endl;
        return false;
    }
    for (char c: input) { // Check if the input contains any non-digit characters
        if (!isdigit(c) && (input[0] != '-')) {
            cout << "Error: Please enter a whole number." << endl << endl;
            return false;
        }
    }
    try {
        output = stoi(input);
        if (output < minVal || output > maxVal) { // Check if the input is out of range
            cout << "Error: Please enter a number between " << minVal << " and " << maxVal << "." << endl << endl;
            return false;
        }
        return true;
    } catch (invalid_argument &e) { // Check if the input is not a valid integer
        return false;
    } catch (out_of_range &e) { // Check if the input is out of range
        return false;
    }
}

// Gets validated integer input within a specified range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;
    do {
        cout << prompt; // Print the prompt
        getline(cin, input); // Get user input
        if (validNumber(input, output, minVal, maxVal)) { // Check if the input is valid
            isValid = true;
        }
    } while (!isValid); // Loop until the input is valid
}

// Asks the user a Yes/No question and validates input
void askYesOrNo(string question, char &yOrN) {
    string placeholder;
    do {
        cout << endl << question; // Print the question
        getline(cin, placeholder); // Get user input
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n')); // Loop until the input is valid
}

//Function to removeWhiteSpace
string toRemoveSpace(string input) {
    string output;
    for (char &c: input) { // Iterate through the string
        if (!isspace(c)) { // Check if the character is not a space
            output+=c; // Add the character to the output
        }
    }
    return output; // Return the output
}