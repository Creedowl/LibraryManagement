//
// Created by creedowl on 2019-05-15.
//

#ifndef LIBRARYMANAGEMENT_UTILS_H
#define LIBRARYMANAGEMENT_UTILS_H

#include <iostream>

// remove '\t' from text to avoid conflict
std::string escape(std::string s);

// stimulate suspension
void pause();

// clean screen
void clear();

// display bookList's title
void showTitle(std::ostream &os);

// make sure the type of input is right
template<typename T>
void safeInput(T &in) {
    while (true) {
        std::cin >> in;
        if (std::cin.fail()) {
            std::cout << "数据类型错误，请重新输入" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif //LIBRARYMANAGEMENT_UTILS_H
