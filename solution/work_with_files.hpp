#pragma once

#include <iostream>
#include <fstream>
#include "RBTree.hpp"

template <class T1, class T2>
void load_tree(std::ifstream *File, Tree<T1,T2> *tree) {
    char key [257];
    unsigned long long value;
    while (File->read(reinterpret_cast<char*>(key), 257*sizeof(char)) && File->read(reinterpret_cast<char*>(&value), sizeof(unsigned long long))) {
        Node<T1,T2> *node = new Node <T1,T2>;
        node->GetKey(key);
        node->GetValue(value);
        if (tree->Insert(node) != 0) {
            delete [] node->FindKey();
            delete node;
        }
    }
}

template <class T1, class T2>
void save_in_tree(std::ostream *File, Tree<T1,T2> *tree, Node<T1,T2> *node) {
    if (node != tree->FindTNull()) {
        save_in_tree(File, tree, node->FindLeft());
        char key [257];
        unsigned long long value;
        str_copy(node->FindKey(), key);
        value = node->FindValue();
        File->write(reinterpret_cast<char*>(key), 257*sizeof(char));
        File->write(reinterpret_cast<char*>(&value), sizeof(unsigned long long));
        save_in_tree(File, tree, node->FindRight());
    }
}