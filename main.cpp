#include <iostream>
#include "RBTree.hpp"
#include "functions.hpp"

int main() {
    /*
    char word1 [6];
    char word2 [6];
    std::cin >> word1;
    std::cout << "Word 1 entered!\n";
    std::cin >> word2;
    std::cout << word1 << " " << word2;
    std::cout << "Word2 entered!\n";
    equal_strings(word1, word2) == 0 ? std::cout << "YES" : std::cout << "NO";
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
    std::cin >> word;
    tree->Search(word) != nullptr ? std::cout << "YES" : std::cout << "NO";
    tree->Delete(tree->FindRoot()->FindRight()->FindLeft());
    tree->AllTreeDelete();
    
    
    /*
    std::cout << "Write searching word: ";
    std::cin >> word;
    Node<char*,unsigned long long> *ptr = tree->Search(word);
    if (ptr != nullptr) {
        tree->Delete(ptr);
    }
    */


    delete tree;

    // main();
}