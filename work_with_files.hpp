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
        pair.Key = node->FindKey();
        pair.Value = node->FindValue();
        vector->PushBack(pair);
    }
}

template <class T1, class T2>
void write_in_file(std::ofstream *File, Vector<NPair::TPair<T1,T2>> *vector) {
    File->write(reinterpret_cast<char*>(vector), vector->FindSize()*sizeof(NPair::TPair<T1,T2>));
    vector->Clear();
}