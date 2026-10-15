#include "../Header/Patron.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

Patron::Patron(std::string n, int i) {
    name = n;
    id = i;
}

void Patron::borrowBook(Book *b) {    
    if (b->getStatus() == BookStatus::Available) {
        b->setStatus(BookStatus::CheckedOut);
        borrowedBooks.push_back(b);
    } else {
        throw std::runtime_error("Book Is Checked Out.");
    }
}

void Patron::returnBook(Book *b) {
    bool hasBook = false;
    for (auto &book : borrowedBooks) {
        if (b == book) {
            b->setStatus(BookStatus::Available);
            auto deleteValue = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
            borrowedBooks.erase(deleteValue);
        }
    }
}

void Patron::displayPatron() const {
    std::cout << name << ", " << id << ":" << std::endl;
    for (auto &book : borrowedBooks) {
        std::cout << "   ";
        book->displayInfo();
        std::cout << std::endl;
    }
}

bool Patron::operator==(const Patron &other) const {
    if ((name == other.name) && (id == other.id)) {
        return true;
    }else {return false;}
}

std::ostream &operator<<(std::ostream &os, const Patron &p) {
    os << p.name << ", " << p.id << std::endl;
}