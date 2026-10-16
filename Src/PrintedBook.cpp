#include "../Header/PrintedBook.h"
#include <iostream>

PrintedBook::PrintedBook(std::string t, std::string a, Genre g, BookStatus status, int pages) : Book(t, a, g, status) {
    pageCount = pages;
}

void PrintedBook::displayInfo() const {
    std::cout << title << ", " << author << ", " << genre << ", " << status << ", " << pageCount << std::endl;
}
