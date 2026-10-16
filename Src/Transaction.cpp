#include "../Header/Transaction.h"
#include <iostream>

Transaction::Transaction(int pid, std::string bt) {
    patronId = pid;
    bookTitle = bt;
}

void Transaction::displayTransaction() const{
    std::cout << patronId << " : " << bookTitle;
}

std::ostream &operator<<(std::ostream &os, const Transaction &p) {
    os << p.patronId << ", " << p.bookTitle;
}