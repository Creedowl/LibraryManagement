//
// Created by creedowl on 2019-05-16.
//

#ifndef LIBRARYMANAGEMENT_OPERATION_H
#define LIBRARYMANAGEMENT_OPERATION_H


#include "BookList.h"

class Operation {
private:
    BookList list;

    /* this function check your input type and help to find
     * the book via bookId or bookName, and show all books
     *
     * receive a function as param and will call it if find
     * target book
     * */
    void action(const std::function<void(Book &)> &f);

public:
    // constructor
    explicit Operation(const BookList &list);

    // add new book
    void appendBook();

    // delete a book
    void deleteBook();

    // show all books
    void showAll();

    // find a book
    void query();

    // increase a book's quantity
    void addBook();

    // decrease a book's quantity
    void sellBook();

    // load bookList from file
    void loadBooks(const std::string &file);

    // save bookList to file
    void saveBooks(const std::string &file);

    // sort bookList
    void sortList();

    // delete all books
    void deleteAll();

    // show menu
    static void showUsage();
};


#endif //LIBRARYMANAGEMENT_OPERATION_H
