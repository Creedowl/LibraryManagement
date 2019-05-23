//
// Created by creedowl on 2019-05-15.
//

#include <iostream>
#include <iomanip>
#include "utils.h"

std::string escape(std::string x) {
    int p = 0;
    while (true) {
        p = x.find('\t', p);
        if (p == std::string::npos) break;
        x.erase(p, p + 1);
        p++;
    }
    return x;
}

void showTitle(std::ostream &os) {
    os << std::left << std::setw(8) << "书号" << ' ' << std::setw(32) << "书名" << ' ' << std::setw(10)
       << "数量" << ' ' << "备注" << std::endl;
    os << "-------------------------------------------------------" << std::endl;
}

void pause() {
    std::cout << "请按回车继续..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void clear() {
#ifdef __GNUC__
    system("clear");
#elif defined _MSC_VER
    system("cls");
#endif
}
