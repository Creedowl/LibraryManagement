//
// Created by creedowl on 2019-05-15.
//

#ifndef LIBRARYMANAGEMENT_BOOKLIST_H
#define LIBRARYMANAGEMENT_BOOKLIST_H

#include <vector>
#include <ostream>
#include <optional>
#include <functional>
#include "Book.h"

typedef std::optional<std::reference_wrapper<Book>> op;

using std::vector;

enum sortItem {
    bookId, bookName, bookQuantity
};

class BookList {
private:
    vector<Book> list;
public:
    // load data from file
    explicit BookList(const string &fileName);

    // add new book from elements
    void add(int id, const string &name, int quantity, const string &info = "", bool output = false);

    // add new book from Book instance
    void add(Book &book);

    // remove a book via book id
    bool remove(int id);

    // find a book via book name, return std::optional
    op query(const string &name);

    // find a book via book id, return std::optional
    op query(int id);

    // save bookList to file
    void saveToFile(const string &fileName);

    // load bookList from file
    void loadFromFile(const string &fileName);

    // sort bookList according to key
    void sortList(sortItem key, bool flag = true);

    // delete all books
    void deleteAll();

    friend std::ostream &operator<<(std::ostream &os, const BookList &list);
};


#endif //LIBRARYMANAGEMENT_BOOKLIST_H
