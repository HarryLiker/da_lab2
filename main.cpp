#include <iostream>
#include "menu.hpp"
#include "RBTree.hpp"
#include "functions.hpp"
#include "vector.hpp"

int main() {

    //std::ios::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    //std::cout.tie(nullptr);

/*
    char word1 [256];
    char word2 [256];
    std::cin >> word1;
    std::cin >> word2;

    std::cout << equal_strings(word1, word2);
*/
     menu();

    /*
    Node<char *, unsigned long long>* node;
    Tree<char *, unsigned long long>* tree;
    tree = new Tree<char *, unsigned long long>;
    char word [257];
    unsigned long long value;

    for(int i = 0; i < 20; i ++) {
        std::cout << "Write key: ";
        std::cin >> word;
        std::cout << "Write value: ";
        std::cin >> value;
        node = new Node<char *, unsigned long long>;
        node->GetKey(word);
        node->GetValue(value);
        tree->Insert(node);
        node = nullptr;
    }
    */
    /*
    std::cin >> word;
    Node<char*,unsigned long long> *deleting_node =  tree->Search(word);
    if (deleting_node != nullptr) {
        tree->Delete(deleting_node);
    }
    std::cin >> word;
    std::cin >> value;
    node = new Node<char *, unsigned long long>;
    node->GetKey(word);
    node->GetValue(value);
    tree->Insert(node);
    tree->Delete(tree->FindRoot()->FindRight()->FindLeft());
    std::cout << "Key: " << node->FindKey() << "Value: " << node->FindValue() << "\n";
    */
    //tree->AllTreeDelete();
    /*
    std::cin >> word;
    
    for (int i = 0; i < 257; i++) {
        if (word[i] >= 'A' || word[i] <= 'Z') {
            word[i] = word[i] - 'A' + 'a';
        }
    }
    

    std::cout << word << "\n";
*/

    /*
    std::cout << "Write searching word: ";
    std::cin >> word;
    Node<char*,unsigned long long> *ptr = tree->Search(word);
    if (ptr != nullptr) {
        tree->Delete(ptr);
    }
    */


    //delete tree;
    
}