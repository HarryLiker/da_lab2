#include <iostream>
#include <fstream>
#include "RBTree.hpp"
#include "vector.hpp"
#include "work_with_files.hpp"
#include "menu.hpp"


int menu() {
    Tree<char *, unsigned long long> *tree = new Tree<char *, unsigned long long>;
    char line [257];
    unsigned long long value;
    while(std::cin >> line) {
        if (line[0] == '+') {
            std::cin >> line;
            std::cin >> value;
            Node<char *, unsigned long long> *node = new Node<char *, unsigned long long>;
            node->GetKey(line);
            node->GetValue(value);
            if (tree->Insert(node) == 0) {
                std::cout << "OK\n";
            }
            else {
                delete [] node->FindKey();
                delete node;
                std::cout << "Exist\n";
            }
            node = nullptr;
        }
        else if (line[0] == '-') {
            std::cin >> line;
            Node<char*, unsigned long long> *deliting_node = tree->Search(line);
            if (deliting_node != nullptr) {
                tree->Delete(deliting_node);
                std::cout << "OK\n";
            }
            else {
                std::cout << "NoSuchWord\n";
            }
        }
        else if (line[0] == '!') {
            std::cin >> line;
            if (line[0] == 'S') {
                std::cin >> line; // Path
                std::ofstream File;
                File.open(line, std::ios_base::binary);
                if (!File.is_open()) {
                    std::cout << "ERROR\n";
                }
                else {
                    //
                    //Vector<Node<char*,unsigned long long>> *vector;
                    //vector = new Vector<Node<char*,unsigned long long>>;
                    //write_in_vector(vector, tree, tree->FindRoot());
                    //write_in_file(&File, vector);
                    //write(&File, tree, tree->FindRoot());

                    save_in_tree(&File, tree, tree->FindRoot());
                    File.close();
                    std::cout << "OK\n";
                }
            }
            if (line[0] == 'L') {
                std::cin >> line;
                std::ifstream File;
                File.open(line, std::ios_base::binary);
                if (!File.is_open()) {
                    std::cout << "ERROR\n";
                }
                else {
                    delete tree;
                    tree = new Tree<char *, unsigned long long>;
                    //Tree<char *, unsigned long long> *new_tree;
                    //new_tree = new Tree<char *, unsigned long long>;
                    load_tree(&File, tree);
                    File.close();
                }
            }
        }
        else {
            Node<char*, unsigned long long> *searching_node = tree->Search(line);
            if (searching_node != nullptr) {
                std::cout << "OK: " << searching_node->FindValue() << "\n";
            }
            else {
                std::cout << "NoSuchWord\n";
            }
        }
    }
    //tree->AllTreeDelete();
    delete tree;
    return 1;
}