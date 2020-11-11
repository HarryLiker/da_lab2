#include <iostream>
#include "RBTree.hpp"

int main() {
    Node<char *, unsigned long long> node;
    Tree<char *, unsigned long long> tree;
    char word [256];
    unsigned long long value;
    for(int i = 0; i < 3; i ++) {
        std::cout << "Write key: ";
        std::cin >> word;
        std::cout << "Write value: ";
        std::cin >> value;
        tree.AddInTree(word, value);
    }

}