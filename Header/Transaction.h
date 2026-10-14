#include <ctime>
#include <string>

class Transaction {
    int patronId;
    std::string bookTitle;
    std::string date;
public:
    Transaction(int pid, std::string bt);
    void displayTransaction() const;
};