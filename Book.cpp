//
// Created by creedowl on 2019-05-15.
//

#include "Book.h"
#include "utils.h"
#include <iostream>
#include <iomanip>

Book::Book(int id, const string &name, int quantity, const string &info) : id(id), name(escape(name)),
                                                                           quantity(quantity),
                                                                           info(escape(info)) {}

Book::Book(string *elements) : id(std::stoi(elements[0])), name(escape(elements[1])), quantity(std::stoi(elements[2])),
                               info(escape(elements[3])) {}

string Book::to_string() {
    string res, temp1, temp2;
    temp1 = escape(name);
    temp2 = escape(info);
    res = std::to_string(id) + '\t' + temp1 + '\t' + std::to_string(quantity) + '\t' + temp2 + '\t';
    return res;
}

bool Book::inc(int num) {
    quantity += num;
    return true;
}

bool Book::dec(int num) {
    if (quantity - num < 0) return false;
    quantity -= num;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << std::left << std::setw(5) << book.id << ' ' << std::setw(30) << book.name << ' '
       << std::setw(8)
       << book.quantity << ' ' << book.info << std::endl;
    return os;
}

int Book::getId() const {
    return id;
}

const string &Book::getName() const {
    return name;
}

int Book::getQuantity() const {
    return quantity;
}
