#include <iostream>
#include "BookList.h"
#include "utils.h"
#include "Operation.h"

int main() {
    // filename
    const std::string file = "BookList.txt";

    // create BookList instance, load data from BookList.txt
    BookList list(file);

    // create menu operator
    Operation ope(list);

    int op = -1;
    // show menu
    while (true) {
        Operation::showUsage();
        // operation
        std::cin >> op;
        clear();
        switch (op) {
            case 1:
                ope.appendBook();
                pause();
                break;
            case 2:
                ope.deleteBook();
                pause();
                break;
            case 3:
                ope.showAll();
                pause();
                break;
            case 4:
                ope.query();
                pause();
                break;
            case 5:
                ope.addBook();
                pause();
                break;
            case 6:
                ope.sellBook();
                pause();
                break;
            case 7:
                ope.loadBooks(file);
                pause();
                break;
            case 8:
                ope.saveBooks(file);
                pause();
                break;
            case 9:
                ope.sortList();
                pause();
                break;
            case 10:
                ope.deleteAll();
                pause();
                break;
            case 0:
                exit(0);
            default:
                continue;
        }
    }
}