//
// Created by Amaya on 3/16/2025.
//
#include "../Function.hpp"
#include "Book.h"

string Book::getId() {
    return id;
}

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

void Book::setId() {
    id = getStringInput("Enter ID: ");
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
    category = getStringInput("Enter Category [Fiction/Non-Fiction]: ");
}


