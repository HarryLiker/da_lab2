#include <iostream>
#include <fstream>

bool Strings_compare(const char *string1, const char *string2) {
    int i = 0;
    while(string1[i] == string2[i]) {
        i++;
    }
    if(string1[i] < string2[i]) {
        return 0;
    }
    else {
        return 1;
    }
}

int Equal_strings(const char *string1, const char *string2) {
    int i = 0;
    while ((string1[i] == string2[i]) && (string1[i] != '\0')) {
        i++;
    }
    if (string1[i] == string2[i]) {
        return 0;
    }
    else if (string1[i] < string2[i]) {
        return -1;
    }
    return 1;
}


void Str_copy(const char *line, char *string) { 
    
    int i = 0;
    while (i < 257 && line[i] != '\0') {
        if ('A' <= line[i] && line[i] <= 'Z') {
            string[i] = line[i] - 'A' + 'a';
        }
        else {
            string[i] = line[i];
        }
        i++;
    }
    string[i] = '\0';
    while(i != 257) {
        string[i] = 0;
        i++;
    }
}

typedef enum { BLACK, RED } NodeColor;

template<class T1, class T2>
class Node {
private:
    T1 Key;
    T2 Value;
    Node* Left;
    Node* Right;
    Node* Parent;
    NodeColor Color; // Color: Black or Red
public:
    Node(): Left(nullptr), Right(nullptr), Parent(nullptr), Color(RED) {}
    
    void GetKey(T1 key) {
        
        Key = new char [257];
        int i = 0;
        while (i != 256 && key[i] != '\0') {
            if ('A' <= key[i] && key[i] <= 'Z') {
                Key[i] = key[i] - 'A' + 'a';
            }
            else {
                Key[i] = key[i];
            }
            i++;            
        }
        Key[i] = '\0';
        while (i != 257) {
            Key[i] = 0;
            i++;
        }
        
    }
    
    T1 FindKey() {
        return Key;
    }
    void GetValue(T2 value) {
        Value = value;
    }
    T2 FindValue() {
        return Value;
    }
    void GetLeft(Node* node) {
        Left = node;
    }
    Node* FindLeft() {
        return Left;
    }
    void GetRight(Node* node) {
        Right = node;
    }
    Node* FindRight() {
        return Right;
    }
    void GetParent(Node* parent) {
        Parent = parent;
    }
    Node* FindParent() {
        return Parent;
    }
    void GetColor(NodeColor color) {
        Color = color;
    }
    NodeColor FindColor() {
        return Color;
    }
    ~Node() {}
};

template<class T1, class T2>
class Tree {
private:
    Node<T1, T2>* Root;
    Node<T1,T2>* TNull;
public:
    Tree(): Root(nullptr) {
        TNull = new Node<T1,T2>;
        TNull->GetLeft(Root);
        TNull->GetRight(Root);
        TNull->GetColor(BLACK);
    }

    Node<T1,T2>* FindRoot() {
        return Root;
    }

    Node<T1,T2>* FindTNull() {
        return TNull;
    }

    void GetKey(T1 key) {
        Root->GetKey(key);
    }

    void GetValue(T2 value) {
        Root->GetValue(value);
    }
    
    void AllTreeDelete() {
        Node<T1,T2> *current_root = Root;
        Node<T1,T2> *deleting_ptr = nullptr;
        while (current_root != TNull) {
            if (current_root->FindLeft() != TNull) {
                current_root = current_root->FindLeft();
            }
            else if (current_root->FindRight() != TNull) {
                current_root = current_root->FindRight();
            }
            else {
                deleting_ptr = current_root;
                if (current_root->FindParent()->FindLeft() == current_root) {
                    current_root->FindParent()->GetLeft(TNull);
                }
                else {
                    current_root->FindParent()->GetRight(TNull);
                }
                current_root = current_root->FindParent();
                delete [] deleting_ptr->FindKey();
                delete deleting_ptr;
            }
        }
        delete TNull;
    } 
    
    Node<T1,T2>* Search(T1 key) {
        Node<T1,T2> *x = Root;
        while (x != TNull && Equal_strings(key, x->FindKey()) != 0) { // 
            if (Equal_strings(key, x->FindKey()) == -1) {
                x = x->FindLeft();
            }
            else {
                x = x->FindRight();
            }
        }
        if (x == TNull) {
            return nullptr;
        }
        return x;
    }
    
    void LeftRotation(Node<T1,T2>* x) {
        Node<T1,T2> *y = x->FindRight();  // у is instally the right node of x
        x->GetRight(y->FindLeft());  // Turning the left node of y into the right node of x
        if (y->FindLeft() != TNull) {
            y->FindLeft()->GetParent(x);
        }
        y->GetParent(x->FindParent()); // The parent of y became the patent of x
        if (x->FindParent() == TNull) {
            Root = y;
        }
        else if (x == x->FindParent()->FindLeft()) {
            x->FindParent()->GetLeft(y);
        }
        else {
            x->FindParent()->GetRight(y);
        }
        y->GetLeft(x); // x becomes the left child of y
        x->GetParent(y);
    }

    void RightRotation(Node<T1,T2>* x) {
        Node<T1,T2> *y = x->FindLeft(); // y is instally the left node of x
        x->GetLeft(y->FindRight()); // Turning the right node of y into the left node of x
        if (y->FindRight() != TNull) {
            y->FindRight()->GetParent(x);
        }
        y->GetParent(x->FindParent()); // The parent of y became the patent of x
        if (x->FindParent() == TNull) {
            Root = y;
        }
        else if (x == x->FindParent()->FindRight()) {
            x->FindParent()->GetRight(y);
        }
        else {
            x->FindParent()->GetLeft(y);
        }
        y->GetRight(x); // x becomes the right child of y
        x->GetParent(y);
    }
    
    void Fixup(Node<T1,T2>* x) {
        while (x->FindParent()->FindColor() == RED) {
            if (x->FindParent() == x->FindParent()->FindParent()->FindLeft()) {
                Node<T1,T2> *y;
                y = x->FindParent()->FindParent()->FindRight();
                if (y->FindColor() == RED) {
                    x->FindParent()->GetColor(BLACK);
                    y->GetColor(BLACK);
                    x->FindParent()->FindParent()->GetColor(RED);
                    x = x->FindParent()->FindParent();
                }
                else {
                    if (x == x->FindParent()->FindRight()) {
                        x = x->FindParent();
                        LeftRotation(x);
                    }
                    x->FindParent()->GetColor(BLACK);
                    x->FindParent()->FindParent()->GetColor(RED);
                    RightRotation(x->FindParent()->FindParent());
                }
            }
            else {
                Node<T1,T2> *y;
                y = x->FindParent()->FindParent()->FindLeft();
                if (y->FindColor() == RED) {
                    x->FindParent()->GetColor(BLACK);
                    y->GetColor(BLACK);
                    x->FindParent()->FindParent()->GetColor(RED);
                    x = x->FindParent()->FindParent();
                }
                else {
                    if (x == x->FindParent()->FindLeft()) {
                        x = x->FindParent();
                        RightRotation(x);
                    }
                    x->FindParent()->GetColor(BLACK);
                    x->FindParent()->FindParent()->GetColor(RED);
                    LeftRotation(x->FindParent()->FindParent());
                }
            }
        }
        Root->GetColor(BLACK); 
    }

    bool Insert(Node<T1, T2>* insertable_root) {
        Node<T1, T2> *parent_root = TNull;
        Node<T1,T2> *current_root = Root;
        while (current_root != TNull && Root != nullptr) {
            parent_root = current_root;
            int strings_comparison = Equal_strings(insertable_root->FindKey(), current_root->FindKey());
            if (strings_comparison != 0) { 
                if (strings_comparison == -1) {
                    current_root = current_root->FindLeft();
                }
                else {
                    current_root = current_root->FindRight();
                }
            }
            else {
                return 1;
            }
        }
        insertable_root->GetParent(parent_root);
        if (parent_root == TNull) {
            Root = insertable_root;
        }
        else if (Strings_compare(insertable_root->FindKey(), parent_root->FindKey()) == 0) {
            parent_root->GetLeft(insertable_root);
        }
        else {
            parent_root->GetRight(insertable_root);
        }
        insertable_root->GetLeft(TNull);
        insertable_root->GetRight(TNull);
        insertable_root->GetColor(RED);
        Fixup(insertable_root);
        return 0;
    }

    Node<T1,T2> *TreeMinimum(Node<T1,T2> *x) {
        while (x->FindLeft() != TNull) {
            x = x->FindLeft();
        }
        return x;
    }

    void Transplant(Node<T1,T2> *u, Node<T1,T2> *v) {
        if (u->FindParent() == TNull) {
            Root = v;
        }
        else if (u == u->FindParent()->FindLeft()) {
            u->FindParent()->GetLeft(v);
        }
        else {
            u->FindParent()->GetRight(v);
        }
        v->GetParent(u->FindParent());
    }

    void DeleteFixup(Node<T1,T2> *x) {
        while (x != Root && x->FindColor() == BLACK) {
            if (x == x->FindParent()->FindLeft()) {
                Node<T1,T2> *y = x->FindParent()->FindRight();
                if (y->FindColor() == RED) {
                    y->GetColor(BLACK);
                    x->FindParent()->GetColor(RED);
                    LeftRotation(x->FindParent());
                    y = x->FindParent()->FindRight();
                }
                if (y->FindLeft()->FindColor() == BLACK && y->FindRight()->FindColor() == BLACK) {
                    y->GetColor(RED);
                    x = x->FindParent();
                }
                else {
                    if (y->FindRight()->FindColor() == BLACK) {
                        y->FindLeft()->GetColor(BLACK); 
                        y->GetColor(RED);
                        RightRotation(y);
                        y = x->FindParent()->FindRight();
                    }
                    y->GetColor(x->FindParent()->FindColor());
                    x->FindParent()->GetColor(BLACK);
                    y->FindRight()->GetColor(BLACK);
                    LeftRotation(x->FindParent());
                    x = Root;
                }
            }
            else {
                Node<T1,T2> *y = x->FindParent()->FindLeft();
                if (y->FindColor() == RED) {
                    y->GetColor(RED);
                    x->FindParent()->GetColor(RED);
                    RightRotation(x->FindParent());
                    y = x->FindParent()->FindLeft();
                }
                if (y->FindRight()->FindColor() == BLACK && y->FindLeft()->FindColor() == BLACK) {
                    y->GetColor(RED);
                    x = x->FindParent();
                }
                else {
                    if (y->FindLeft()->FindColor() == BLACK) {
                        y->FindRight()->GetColor(BLACK);
                        y->GetColor(RED);
                        LeftRotation(y);
                        y = x->FindParent()->FindLeft();
                    }
                    y->GetColor(x->FindParent()->FindColor());
                    x->FindParent()->GetColor(BLACK);
                    y->FindLeft()->GetColor(BLACK);
                    RightRotation(x->FindParent());
                    x = Root;
                }
            }
        }
        x->GetColor(BLACK);
    }

    void Delete(Node<T1,T2>* z) {
        Node<T1,T2> *y = z;
        Node<T1,T2> *x = TNull;
        NodeColor y_original_color = y->FindColor();
        if (z->FindLeft() == TNull) {
            x = z->FindRight();
            Transplant(z, z->FindRight());
        }
        else if (z->FindRight() == TNull) {
            x = z->FindLeft();
            Transplant(z, z->FindLeft());
        }
        else {
            y = TreeMinimum(z->FindRight()); // TreeMinimum(z->right)
            y_original_color = y->FindColor();
            x = y->FindRight();
            if (y->FindParent() == z) {
                x->GetParent(y);
            }
            else {
                Transplant(y, y->FindRight());
                y->GetRight(z->FindRight());
                y->FindRight()->GetParent(y);
            }
            Transplant (z, y);
            y->GetLeft(z->FindLeft());
            y->FindLeft()->GetParent(y);
            y->GetColor(z->FindColor());
        }
        if (y_original_color == BLACK) {
            DeleteFixup(x);
        }
        delete [] z->FindKey();
        delete z;
    }

    ~Tree() {
        AllTreeDelete();
    }
};

template <class T1, class T2>
void Load_tree(std::ifstream *File, Tree<T1,T2> *tree) {
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
    }
}

template <class T1, class T2>
void Tree_save(std::ostream &File, Tree<T1,T2> *tree, Node<T1,T2> *node) {
    if (node != tree->FindTNull()) {
        Tree_save(File, tree, node->FindLeft());
        char key [257];
        unsigned long long value = 0;
        Str_copy(node->FindKey(), key);
        value = node->FindValue();
        File.write((const char *)key, sizeof(char)*257);
        File.write((const char *)&value, sizeof(unsigned long long));
        Tree_save(File, tree, node->FindRight());
    }
}

int Menu() {
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
            Str_copy(line, line);
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
                File.exceptions(std::ofstream::badbit | std::ofstream::failbit);

                try {
                    File.open(line, std::ios_base::binary); 
                    if (!File.is_open()) {
                        throw "File with this name does not exist\n";
                    }
                    Tree_save(File, tree, tree->FindRoot());
                    File.close();
                    std::cout << "OK\n";
                }
                catch (const std::exception &exeption) {
                    std::cout << "ERROR: "  << exeption.what() << "\n";
                }
            }
            if (line[0] == 'L') {
                std::cin >> line;
                std::ifstream File;
                File.exceptions(std::ifstream::badbit);
                try {
                    File.open(line, std::ios_base::binary);
                    if (!File.is_open()) {
                        throw "File with this name does not exist\n";
                    }
                    Tree<char *, unsigned long long> *new_tree;
                    new_tree = new Tree<char *, unsigned long long>;
                    Load_tree(&File, new_tree);
                    File.close();
                    delete tree;
                    tree = new_tree;
                    std::cout << "OK\n";
                }
                catch (const char* error) {
                    std::cout << "ERROR: " << error;
                }
                catch (const std::exception &exeption) {
                    std::cout << "ERROR: " << exeption.what() << "\n";
                }
            }
        }
        else {
            Str_copy(line, line);
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

int main() {
    Menu();
}