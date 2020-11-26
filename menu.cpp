#include <iostream>
#include <fstream>
#include "RBTree.hpp"
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
            str_copy(line, line);
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
                    std::cout << "ERROR: There is no write permission\n";
                }
                
                else {
                    tree_save(File, tree, tree->FindRoot());
                    File.close();
                    std::cout << "OK\n";
                } 
            }
            if (line[0] == 'L') {
                std::cin >> line;
                std::ifstream File;
                File.open(line, std::ios_base::binary);
                if (!File.is_open()) {
                    std::cout << "ERROR: The entered file does not exist\n";
                }
                else {
                    Tree<char *, unsigned long long> *new_tree;
                    new_tree = new Tree<char *, unsigned long long>;
                    load_tree(&File, new_tree);
                    File.close();
                    delete tree;
                    tree = new_tree;
                    std::cout << "OK\n";
                }
            }
        }
        else {
            str_copy(line, line);
            Node<char*, unsigned long long> *searching_node = tree->Search(line);
            if (searching_node != nullptr) {
                std::cout << "OK: " << searching_node->FindValue() << "\n";
            }
            else {
                std::cout << "NoSuchWord\n";
            }
        }
    }
    delete tree;
    return 0;
}