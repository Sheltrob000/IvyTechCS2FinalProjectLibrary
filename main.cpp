#include "Header/Book.h"
#include "Header/Library.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>




int main() {
    std::string input;
    Library library;
    library.loadData();

    std::cout << "what would you like to do?" << std::endl;
    std::cout << "add Book (book)" << std::endl;
    std::cout << "add Patron (patron)" << std::endl;
    std::cout << "checkout a book (checkout)" << std::endl;
    std::cout << "return a book (return)" << std::endl;
    std::cout << "display books (displayB)" << std::endl;
    std::cout << "display patrons (displayP)" << std::endl;
    std::cout << "save Data (save)" << std::endl;
    std::cout << "end program (end)" << std::endl;

    std::cin >> input;
    std::cin.ignore();

//welcome to the jankest code I have written all year!!
    while (input != "end") {
        if (input == "book") {
            std::string title;
            std::string author;
            std::string genre;
            static const std::unordered_map<std::string, Genre> genreMap = {
                    {"Fiction",    Genre::Fiction},
                    {"NonFiction", Genre::NonFiction},
                    {"Mystery",    Genre::Mystery},
                    {"Science",    Genre::Science},
                    {"Biography",  Genre::Biography}
            };
            std::cout << "what is the name of the book: ";
            std::getline(std::cin, title);
            std::cout << "what is the authors Name: ";
            std::getline(std::cin, author);
            std::cout << "what is the genre (Fiction, NonFiction, Mystery, Science, Biography): ";
            std::cin >> genre;
            std::cin.ignore();
            try {
                library.addBook(new Book(title, author, genreMap.at(genre), BookStatus::Available));
            } catch (std::runtime_error &e) {
                std::cout << e.what();
            }
        } else if (input == "patron") {
            std::string patronIdStr;
            std::string name;
            int patronID;
            std::cout << "what is the patrons name: ";
            std::getline(std::cin, name);
            std::cout << "what is the patrons Id: ";
            std::cin >> patronIdStr;
            std::cin.ignore();
            patronID = std::stoi(patronIdStr);
            try {
                library.addPatron(Patron(name, patronID));
            } catch (std::runtime_error &e) {
                std::cout << e.what();
            }

        } else if (input == "checkout") {
            std::string patronIdStr;
            std::string bookTitle;
            int patronID;

            std::cout << "what is the patrons Id: ";
            std::cin >> patronIdStr;
            std::cin.ignore();
            std::cout << "what is the book title: ";
            std::getline(std::cin, bookTitle);
            patronID = std::stoi(patronIdStr);

            try {
                library.checkoutBook(patronID, bookTitle);
            } catch (std::runtime_error &e) {
                std::cout << e.what();
            }
        } else if (input == "return"){
            std::string patronIdStr;
            std::string bookTitle;
            int patronID;
            std::cout << "what is the patrons Id: ";
            std::cin >> patronIdStr;
            std::cin.ignore();
            std::cout << "what is the book title: ";
            std::getline(std::cin, bookTitle);
            patronID = std::stoi(patronIdStr);

            try {
                library.returnBook(patronID, bookTitle);
            } catch (std::runtime_error &e) {
                std::cout << e.what();
            }
        } else if (input == "displayB") {
            library.displayBooks();
        } else if (input == "displayP") {
            library.displayPatrons();
        } else if (input == "save") {
            try {
                library.saveData();

            } catch (std::runtime_error &e) {
                std::cout << e.what();
            }
        } else {
            std::cout << "unrecognized input, please try again." << std::endl;
        }

        std::cout << std::endl << std::endl;
        std::cout << "what would you like to do?" << std::endl;
        std::cout << "add Book (book)" << std::endl;
        std::cout << "add Patron (patron)" << std::endl;
        std::cout << "checkout a book (checkout)" << std::endl;
        std::cout << "return a book (return)" << std::endl;
        std::cout << "display books (displayB)" << std::endl;
        std::cout << "display patrons (displayP)" << std::endl;
        std::cout << "save Data (save)" << std::endl;
        std::cout << "end program (end)" << std::endl;

        std::cin >> input;
        std::cin.ignore();
    }    
    return 0;    
}
