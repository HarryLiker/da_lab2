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
            tree->Insert(node);
            std::cout << "OK\n";
            node = nullptr;
        }
        else if (line[0] == '-') {
            std::cin >> line;
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
                    Vector<NPair::TPair<char*, unsigned long long>> *vector;
                    vector = new Vector<NPair::TPair<char*, unsigned long long>>;
                    //

                    write_in_vector(vector, tree, tree->FindRoot());
                    write_in_file(&File, vector);
                    File.close();
                }
            }
            else {
                
            }
        }
    }
    tree->AllTreeDelete();
    delete tree;
    return 1;
}