//
// Created by creedowl on 2019-05-15.
//

#include "BookList.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <optional>

void BookList::add(int id, const string &name, int quantity, const string &info, bool output) {
    Book book(id, name, quantity, info);
    list.push_back(book);
    if (output) {
        showTitle(std::cout);
        std::cout << book << std::endl;
    }
}

void BookList::add(Book &book) {
    list.push_back(book);
}

void BookList::saveToFile(const string &fileName) {
    std::ofstream out;
    out.open(fileName, std::ios::out);
    for (auto &book : list) {
        out << book.to_string() << std::endl;
    }
    out.close();
}

void BookList::loadFromFile(const string &fileName) {
    list.erase(list.begin(), list.end());
    std::ifstream in;
    in.open(fileName, std::ios::in);
    string temp, elements[4];
    while (std::getline(in, temp)) {
        int p1 = 0, p2 = 0, x = 0;
        while (true) {
            p2 = temp.find('\t', p1);
            if (p2 == std::string::npos) break;
            elements[x] = escape(temp.substr(p1, p2 - p1 + 1));
            p1 = p2 + 1;
            x++;
        }
        Book b(elements);
        add(b);
    }
}

void BookList::sortList(sortItem key, bool flag) {
    std::sort(list.begin(), list.end(),
              [&](const Book &b1, const Book &b2) -> bool {
                  if (key == bookName) return flag ? b1.getName() < b2.getName() : b1.getName() > b2.getName();
                  else if (key == bookQuantity)
                      return flag ? b1.getQuantity() < b2.getQuantity() : b1.getQuantity() > b2.getQuantity();
                  else return flag ? b1.getId() < b2.getId() : b1.getId() > b2.getId();
              });
}

void BookList::deleteAll() {
    list.clear();
}

bool BookList::remove(int id) {
    for (auto book = list.begin(); book != list.end(); book++) {
        if (book->getId() == id) {
            list.erase(book);
            return true;
        }
    }
    return false;
}

op BookList::query(int id) {
    for (auto &book : list) {
        if (book.getId() == id) return book;
    }
    return std::nullopt;
}

op BookList::query(const string &name) {
    for (auto &book : list) {
        if (book.getName() == name) return book;
    }
    return std::nullopt;
}

std::ostream &operator<<(std::ostream &os, const BookList &list) {
    showTitle(os);
    for (const auto &book : list.list) {
        os << book;
    }
    return os;
}

BookList::BookList(const string &fileName) {
    loadFromFile(fileName);
}
