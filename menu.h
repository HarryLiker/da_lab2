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
            Node<char *, long long int> *node = new Node<char *, long long int>;
        }
        else if (symbol == '-') {
            
        }
        else if (symbol == '!') {

        }
        else {

        }
    }
}