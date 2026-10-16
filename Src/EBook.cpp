#include "../Header/EBook.h"
#include <iostream>

EBook::EBook(std::string t, std::string a, Genre g, BookStatus status, double size) : Book(t,a,g,status) {
    title = t;
    author = a;
    genre = g;
    this->status = status;
    fileSizeMB = size;
}

void EBook::displayInfo() const {
    std::cout << title << ", " << author << ", " << genre << ", " << status << ", " << fileSizeMB << std::endl;
}
