#ifndef PrintedBook_h
#define PrintedBook_h

#include "Book.h"
#include <string>

class PrintedBook : public Book {
private:
    int pageCount;

public:
    // This signature must be perfectly clean
    PrintedBook(std::string t, std::string a, Genre g, BookStatus status, int pages);
    
    void displayInfo() const override;
};

#endif