//
// Created by creedowl on 2019-05-15.
//

#ifndef LIBRARYMANAGEMENT_OPEARATION_H
#define LIBRARYMANAGEMENT_OPEARATION_H

#include "BookList.h"

void appendBook(BookList &list);
void deleteBook(BookList &list);
void showAll(BookList &list);
void query(BookList &list);
void addBook();
void sellBook();
void loadBooks();
void saveBooks();
void sortById();
void deleteAll();
void quit();
void showUsage();

#endif //LIBRARYMANAGEMENT_OPEARATION_H
