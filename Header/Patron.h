#ifndef Patron_h
#define Patron_h

#include <string>
#include <vector>
#include "Book.h"

class Patron {
    std::string name;
    int id;
    std::vector<Book*> borrowedBooks;
public:
    Patron(std::string n, int i);
    Patron();
    int getid();
    void borrowBook(Book* b);
    void returnBook(Book* b);
    void displayPatron() const;

    bool operator==(const Patron& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Patron& p);
};
#endif