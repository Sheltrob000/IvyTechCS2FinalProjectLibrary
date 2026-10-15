#include "../Header/Library.h"
#include <iostream>
#include <ostream>

void Library::addBook(Book *b) { books.push_back(b); }

void Library::addPatron(const Patron &p) { patrons.push_back(p); }

void Library::displayBooks() const {
    for (const auto &book : books) {
        book->displayInfo();
        std::cout << std::endl;
    }
}

void Library::displayPatrons() const {
    for (const auto &patron : patrons) {
        patron.displayPatron();
        std::cout << std::endl;
    }
}