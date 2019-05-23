//
// Created by creedowl on 2019-05-15.
//

#ifndef LIBRARYMANAGEMENT_BOOK_H
#define LIBRARYMANAGEMENT_BOOK_H

#include <string>
#include <ostream>

using std::string;

class Book {
private:
    int id;
    string name;
    int quantity;
    string info;
public:
    // create instance from element
    Book(int id, const string &name, int quantity, const string &info = "");

    // create instance from elements array
    explicit Book(string *elements);

    // get book id
    int getId() const;

    // get book name, used for sorting
    const string &getName() const;

    // get book quantity
    int getQuantity() const;

    // increase book
    bool inc(int num);

    // decrease book
    bool dec(int num);

    // serialize
    string to_string();

    friend std::ostream &operator<<(std::ostream &os, const Book &book);
};


#endif //LIBRARYMANAGEMENT_BOOK_H
