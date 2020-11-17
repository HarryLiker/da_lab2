#pragma once

#include <iostream>
#include "RBTree.hpp"

int main() {
    Tree<char *, unsigned long long> *tree = new Tree<char *, unsigned long long>;
    char symbol;
    while (std::cin >> symbol) {
        if (symbol == '+') {
            char key_word [256];
            long long int value;
            std::cin >> key_word >> value;
            Node<char *, unsigned long long> *node = new Node<char *, unsigned long long>;
            tree->Insert2(node);
        }
        else if (symbol == '-') {
            char key_word [256];
            std::cin >> key_word;
            Node<char *, unsigned long long> *node = tree->Search(key_word);
            if (node != nullptr) {
                tree->Delete(node);
            }
            else {
                std::cout << "NoSuchWord\n";
            }
            tree->Delete(node);
        }
        else if (symbol == '!') {
            char action [5];
            std::cin >> action;
            if (equal_strings(action, "Save") == 0) {
                // Сохраняем дерево
            }
            else if (equal_strings(action, "Load") == 0) {
                // Загружаем дерево
            }
        }
        else {
            std::cout << "Load\n";
        }
    }
}