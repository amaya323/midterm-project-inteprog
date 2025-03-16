//
// Created by balio on 3/16/2025.
//

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
using namespace std;
#include <regex>

// Function declarations
void printTitle(const string &title);
void printMenu();
string getStringInput(string prompt);
string toLowerCase(string str);
string toUpperCase(string str);
bool validNumber(const string &input, int &output);
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal);
void askYesOrNo(string question, char &yOrN);

#endif
