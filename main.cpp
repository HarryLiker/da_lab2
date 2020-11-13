#include <iostream>
#include "RBTree.hpp"
#include "functions.hpp"

int main() {
    /*
    char word1 [256];
    char word2 [256];
    std::cin >> word1;
    std::cin >> word2;
    
    std::cout << strings_compare(word1, word2);
    */
    
    Node<char *, unsigned long long>* node;
    Tree<char *, unsigned long long>* tree;
    tree = new Tree<char *, unsigned long long>;
    char word [256];
    unsigned long long value;
    
    for(int i = 0; i < 20; i ++) {
        std::cout << "Write key: ";
        std::cin >> word;
        std::cout << "Write value: ";
        std::cin >> value;
        node = new Node<char *, unsigned long long>;
        node->GetKey(word);
        node->GetValue(value);
        tree->Insert2(node);
        node = nullptr;
    }
    tree->Delete(tree->FindRoot()->FindRight()->FindLeft());
    //
}