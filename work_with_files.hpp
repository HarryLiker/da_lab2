#pragma once

#include <iostream>
#include <fstream>
#include "RBTree.hpp"
#include <cstring>

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
void tree_save(std::ostream &File, Tree<T1,T2> *tree, Node<T1,T2> *node) {
    if (node != tree->FindTNull()) {
        tree_save(File, tree, node->FindLeft());
        char key [257];
        unsigned long long value = 0;
        //str_copy(node->FindKey(), key);
        memcpy(key, node->FindKey(), sizeof(char)*257);
        value = node->FindValue();
        File.write((const char *)key, sizeof(char)*257);
        File.write((const char *)&value, sizeof(unsigned long long));
        //File.write(reinterpret_cast<char*>(key), 257*sizeof(char));
        //File.write(reinterpret_cast<char*>(&value), sizeof(unsigned long long));
        tree_save(File, tree, node->FindRight());
    }
}

