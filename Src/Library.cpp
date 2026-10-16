#include "../Header/Library.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <unordered_map>

Library::~Library() {
    for (auto *book : books) {
        delete book;
    }
    books.clear();
}

void Library::loadData() {
    // Patrons
    std::ifstream patronFile("SaveFiles/Patrons.txt");
    if (!patronFile.is_open()) {
        throw std::runtime_error("Failed to open Patron.txt");
    }
    std::string line;
    std::string name;
    std::string idstring;
    int id;
    while (!patronFile.eof()) {
        std::getline(patronFile, line);
        std::stringstream ss(line);
        std::getline(ss, name, ',');
        std::getline(ss, idstring, ',');
        id = std::stoi(idstring);

        if (name != "") {
            addPatron(Patron(name, id));
        }
    }
    patronFile.close();


    // Books
    std::ifstream bookFile("SaveFiles/Books.txt");
    if (!bookFile.is_open()) {
        throw std::runtime_error("Failed to open Patron.txt");
    }
    std::string title;
    std::string author;
    std::string genre;
    std::string bookStatus;
    while (!bookFile.eof()) {
        std::getline(bookFile, line);
        std::stringstream ss(line);

        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, bookStatus, ',');

        static const std::unordered_map<std::string, Genre> genreMap = {
            {" Fiction",    Genre::Fiction},
            {" Non-Fiction", Genre::NonFiction},
            {" Mystery",    Genre::Mystery},
            {" Science",    Genre::Science},
            {" Biography",  Genre::Biography}
};
        static const std::unordered_map<std::string, BookStatus> statusMap = {
            {" Available",    BookStatus::Available},
            {" CheckedOut", BookStatus::CheckedOut}

};
        if (title != "") {
            addBook(new Book(title, author, genreMap.at(genre), statusMap.at(bookStatus)));
        }
    }
    bookFile.close();


    // Transactions
    std::ifstream transactionfile("SaveFiles/Transactions.txt");
    if (!transactionfile.is_open()) {
        throw std::runtime_error("Failed to open Transactions.txt");
    }
    std::string patronIdStr;
    std::string booktitle;
    int patronID;
    while (!transactionfile.eof()) {
        std::getline(transactionfile, line);
        std::stringstream ss(line);

        std::getline(ss, patronIdStr, ',');
        std::getline(ss, booktitle, ',');
        try {
            patronID = std::stoi(patronIdStr);

        } catch (std::invalid_argument &e) {
           std::cout << e.what() << patronIdStr <<std::endl;
        }

        transactions.push_back(Transaction(patronID, booktitle));
    }
    transactionfile.close();
}

void Library::saveData() {
    // Patrons
    std::ofstream patronsFile("SaveFiles/Patrons.txt");
    if (!patronsFile.is_open()) {
        throw std::runtime_error("Failed to open Patrons.txt");
    }
    for (auto &patron : patrons) {
        patronsFile << patron;
    }
    patronsFile.close();


    // Books
    std::ofstream BooksFile("SaveFiles/Books.txt");
    if (!BooksFile.is_open()) {
        throw std::runtime_error("Failed to open Books.txt");
    }
    for (auto &book : books) {
        BooksFile << *book;
    }
    BooksFile.close();

    // Transactions
    std::ofstream transactionsFile("SaveFiles/Transactions.txt");
    if (!transactionsFile.is_open()) {
        throw std::runtime_error("Failed to open Transactions.txt");
    }
    for (auto &transaction : transactions) {
        transactionsFile << transaction;
    }
    transactionsFile.close();
}


void Library::addBook(Book *b) {
    for (auto &book : books) {
        if (book == b) {
            throw std::runtime_error("attempted to add duplicate book");
        }
    }
    books.push_back(b);
}

void Library::addPatron(const Patron &p) {
    for (auto &patron : patrons) {
        if (patron == p) {
            throw std::runtime_error("attempted to add duplicate patron");
        }
    }
    patrons.push_back(p);
}

void Library::checkoutBook(int patronID, std::string title) {
    bool foundPatron = false;
    bool foundBook = false;
    Patron *chosenPatron;
    Book *chosenBook;
    for (auto &patron : patrons) {
        if (patron.getid() == patronID) {
            chosenPatron = &patron;
            foundPatron = true;
        }
    }
    for (auto &book : books) {
        if (title == book->getTitle()) {
            chosenBook = book;
            foundBook = true;
        }
    }
    if (foundBook && foundPatron) {
        chosenPatron->borrowBook(chosenBook);
    } else if (foundPatron) {
        throw std::runtime_error("Id was valid, Book title was not");
    } else if (foundBook) {
        throw std::runtime_error("Book title was fine, PatronId was invalid");
    } else {
        throw std::runtime_error("both Book title and PatronId were invalid");
    }
}

void Library::returnBook(int patronID, std::string title) {
    bool foundPatron = false;
    bool foundBook = false;
    Patron *chosenPatron;
    Book *chosenBook;
    for (auto &patron : patrons) {
        if (patron.getid() == patronID) {
            chosenPatron = &patron;
            foundPatron = true;
        }
    }
    for (auto &book : books) {
        if (title == book->getTitle()) {
            chosenBook = book;
            foundBook = true;
        }
    }
    if (foundBook && foundPatron) {
        chosenPatron->returnBook(chosenBook);
    } else if (foundPatron) {
        throw std::runtime_error("Id was valid, Book title was not");
    } else if (foundBook) {
        throw std::runtime_error("Book title was fine, PatronId was invalid");
    } else {
        throw std::runtime_error("both Book title and PatronId were invalid");
    }
}

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