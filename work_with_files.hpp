#pragma once

#include <iostream>
#include <fstream>
#include "vector.hpp"
#include "RBTree.hpp"
#include "pair.hpp"

template <class T1, class T2>
void write_in_vector(Vector<NPair::TPair<T1,T2>> *vector, Tree<T1,T2> *tree, Node<T1,T2> *node) {
    if (node != tree->FindTNull()) {
        write_in_vector(vector, tree, node->FindLeft());
        NPair::TPair<T1,T2> pair;
        pair.GetKey(node->FindKey());
        pair.Value = node->FindValue();
        vector->PushBack(pair);
        write_in_vector(vector, tree, node->FindRight());
    }
}

template <class T1, class T2>
void write_in_file(std::ofstream *File, Vector<NPair::TPair<T1,T2>> *vector) {
    File->write(reinterpret_cast<char*>(vector), vector->FindSize()*sizeof(NPair::TPair<T1,T2>));
    vector->Clear();
}

template <class T1, class T2>
void write(std::ofstream *File, Tree<T1,T2> *tree, Node<T1,T2> *node) {
    if (node != tree->FindTNull()) {
        write(File, tree, node->FindLeft());
        NPair::TPair<T1,T2> pair;
        pair.GetKey(node->FindKey());
        pair.Value = node->FindValue();
        File->write(reinterpret_cast<char*>(&pair), sizeof(NPair::TPair<T1,T2>));
        write(File, tree, node->FindRight());
    }
}

template <class T1, class T2>
void load_tree(std::ifstream *File, Tree<T1,T2> *tree) {
    while (!File->eof()) {
        char key [257];
        unsigned long long value;
        File->read(reinterpret_cast<char*>(key), 257*sizeof(char));
        File->read(reinterpret_cast<char*>(&value), sizeof(unsigned long long));
        Node<T1,T2> *node = new Node <T1,T2>;
        node->GetKey(key);
        node->GetValue(value);
        if (tree->Insert(node) != 0) {
            delete [] node->FindKey();
            delete node;
        }
        //File->read(reinterpret_cast<char*>(&pair), sizeof(NPair::TPair<T1,T2>));
        //Node<T1,T2> *node = new Node<T1,T2>;
        //node->GetKey(pair.Key);
        //node->GetValue(pair.Value);
        //tree->Insert(node);
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