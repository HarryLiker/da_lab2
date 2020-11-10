#include <iostream>
#include "RB-tree.hpp"

int main() {
    TPair<char *, unsigned long long> pair;
    char str[256];
    std::cin >> str;
    pair.GetKey(str);
    pair.GetValue(1234);
    //std::cout << pair.FindKey();
    //std::cout << pair.FindValue();
    Node<char*, unsigned long long> node(pair.FindKey(), pair.FindValue());
    std::cout << node.FindKey() << " " << node.FindValue() << "\n";
    /*
    RBTree<char*, unsigned long long> *tree;
    tree = new RBTree<char*, unsigned long long>;
    char key[256];
    unsigned long long value;
    std::cin >> key >> value;
    tree->AddInTree(key, value);
    tree->PrintData();
    std::cin >> key >> value;
    tree->AddInTree(key,value);
    tree->PrintData();
    std::cout << "Done!\n";
    */
}