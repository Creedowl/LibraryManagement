//
// Created by creedowl on 2019-05-16.
//

#include <iostream>
#include "Operation.h"
#include "utils.h"

Operation::Operation(const BookList &list) : list(list) {}

void Operation::action(const std::function<void(Book &)> &f) {
    int type = 0;
    op res;
    while (true) {
        std::cout << "请输入书号-1，书名-2，查询全部-3，退出-0：" << std::endl;
        safeInput<int>(type);
        if (type == 0) return;
        else if (type == 1) {
            int param;
            std::cout << "请输入书号：";
            safeInput<int>(param);
            res = list.query(param);
        } else if (type == 2) {
            std::string param;
            std::cout << "请输入书名：";
            std::cin >> param;
            res = list.query(param);
        } else if (type == 3) {
            showAll();
            continue;
        } else continue;
        if (res) {
            f(res->get());
        } else std::cout << "未找到该书，请检查书号或书名是否正确" << std::endl;
    }
}

void Operation::appendBook() {
    int id, quantity;
    std::string name, info;
    while (true) {
        std::cout << "请输入书号：";
        safeInput(id);
        // check if already existed
        if (list.query(id)) std::cout << "此书已存在，请更换书号或者更新图书记录" << std::endl;
        else break;
    }
    while (true) {
        std::cout << "请输入书名：";
        safeInput(name);
        // check if already existed
        if (list.query(name)) std::cout << "此书已存在，请更换书名或者更新图书记录" << std::endl;
        else break;
    }
    std::cout << "请输入数量：";
    safeInput(quantity);
    std::cout << "请输入备注，默认为空：";
    std::getline(std::cin, info);
    list.add(id, name, quantity, info, true);
    std::cout << "添加成功" << std::endl;
}

void Operation::deleteBook() {
    auto f = [&](Book &res) -> void {
        list.remove(res.getId());
        std::cout << "删除成功" << std::endl;
    };
    action(f);
}

void Operation::showAll() {
    std::cout << list << std::endl;
}

void Operation::query() {
    auto f = [](Book &res) -> void {
        showTitle(std::cout);
        std::cout << res << std::endl;
    };
    action(f);
}

void Operation::addBook() {
    auto f = [](Book &res) -> void {
        showTitle(std::cout);
        std::cout << res << std::endl;
        std::cout << "请输入添加数量" << std::endl;
        int quantity;
        safeInput<int>(quantity);
        res.inc(quantity);
        std::cout << "添加成功，当前数量：" << res.getQuantity() << std::endl;
        pause();
        clear();
    };
    action(f);
}

void Operation::sellBook() {
    auto f = [](Book &res) -> void {
        showTitle(std::cout);
        std::cout << res << std::endl;
        std::cout << "请输入添加数量" << std::endl;
        int quantity;
        safeInput<int>(quantity);
        if (res.dec(quantity)) {
            std::cout << "销售成功，当前数量：" << res.getQuantity() << std::endl;
        } else std::cout << "销售失败，剩余图书数量不足" << std::endl;
    };
    action(f);
}

void Operation::loadBooks(const std::string &file) {
    std::string fileName;
    std::cout << "请输入文件名，默认 " << file << " ：";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fileName);
    if (fileName == "") fileName = file;
    list.loadFromFile(fileName);
    std::cout << "加载完成" << std::endl;
}

void Operation::saveBooks(const std::string &file) {
    std::string fileName;
    std::cout << "请输入文件名，默认 " << file << " ：";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fileName);
    if (fileName == "") fileName = file;
    list.saveToFile(fileName);
    std::cout << "保存成功" << std::endl;
}

void Operation::sortList() {
    int op;
    bool flag;
    std::cout << "请输入排序位置，书号-1，书名-2，数量-3：";
    safeInput<int>(op);
    std::cout << "请输入排序方式，升序-1，降序-0：";
    safeInput<bool>(flag);
    switch (op) {
        case 1:
        default:
            list.sortList(bookId, flag);
            break;
        case 2:
            list.sortList(bookName, flag);
            break;
        case 3:
            list.sortList(bookQuantity, flag);
            break;
    }
    std::cout << "排序完成" << std::endl;
}

void Operation::deleteAll() {
    std::string flag;
    std::cout << "你确定要删除全部记录🐴(y/N)：";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, flag);
    if (flag == "y" || flag == "Y") {
        list.deleteAll();
        std::cout << "已删除全部记录" << std::endl;
    } else std::cout << "取消操作" << std::endl;
}

void Operation::showUsage() {
    clear();
    std::cout << "        图书库存管理系统" << std::endl;
    std::cout << "1： 追加图书记录" << std::endl;
    std::cout << "2： 删除图书记录" << std::endl;
    std::cout << "3： 显示所有图书记录" << std::endl;
    std::cout << "4： 查询图书" << std::endl;
    std::cout << "5： 图书入库" << std::endl;
    std::cout << "6： 图书销售" << std::endl;
    std::cout << "7： 批量导入图书记录" << std::endl;
    std::cout << "8： 导出图书记录" << std::endl;
    std::cout << "9： 排序" << std::endl;
    std::cout << "10：删除全部图书记录" << std::endl;
    std::cout << "0： 退出" << std::endl;
    std::cout << "请输入选择：";
}
