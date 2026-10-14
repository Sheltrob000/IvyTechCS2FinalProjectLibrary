#include <string>
#include <vector>
class Library {
    std::vector<Book*> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;

public:
    ~Library();
    void loadData();
    void saveData();
    void addBook(Book* b);
    void addPatron(const Patron& p);
    void checkoutBook(int patronId, std::string title);
    void returnBook(int patronId, std::string title);
    void displayBooks() const;
    void displayPatrons() const;
};