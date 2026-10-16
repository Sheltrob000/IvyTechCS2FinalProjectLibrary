#include "../Header/Book.h"
#include <iostream>
#include <ostream>

Book::Book(std::string t, std::string a, Genre g, BookStatus s) {
    title = t;
    author = a;
    genre = g;
    status = s;
}

std::string Book::getTitle() {
    return title;
}

void Book::setStatus(BookStatus s) { status = s; }

BookStatus Book::getStatus() const { return status; }

std::ostream& operator<<(std::ostream& os, const Genre& genre) {
    switch (genre) {
        case Genre::Fiction:
            os << "Fiction";
            break;
        case Genre::NonFiction:
            os << "Non-Fiction";
            break;
        case Genre::Mystery:
            os << "Mystery";
            break;
        case Genre::Science:
            os << "Science";
            break;
        case Genre::Biography:
            os << "Biography";
            break;
        default:
            os << "Unknown";
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const BookStatus &status) {
    switch (status) {
        case BookStatus::Available:
            os << "Available";
            break;
        case BookStatus::CheckedOut:
            os << "CheckedOut";
            break;
        default:
            os << "unknown, this is an error";
            break;

    }
    return os;
}


void Book::displayInfo() const {
    std::cout << title << ", " << author << ", " << genre << ", " << status << std::endl;
}

bool Book::operator==(const Book &other) const {
    if ((title == other.title) &&(author == other.author) &&(genre == other.genre)) {
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Book &b) {
    os << b.title << ", " << b.author << ", " << b.genre << ", " << b.status << std::endl;
    // TODO make sure this is the correct implementation!!!
        return os;

}

