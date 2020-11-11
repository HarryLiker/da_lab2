#include <iostream>
#include <cstring>

template<class T1, class T2>
class Node {
private:
    T1 Key = nullptr;
    T2 Value;
    Node *Left;
    Node *Right;
    Node *Parent;
public:
    Node() {}
    // Node(T1 key, T2 value): Key(key), Value(value), Left(nullptr), Right(nullptr) {}
    void GetKey(T1 key) {
        Key = new char [256];
        for (int i = 0; i < 256; i++) {
            Key[i] = key[i];
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
    void GetParent(Node* node) {
        Parent = node;
    }
    Node* FindParent() {
        return Parent;
    }
    ~Node() {}
};

template <class T1, class T2>
class Tree {
private:
    Node<T1, T2> *Root;
public:
    Tree() {}
    void AddInTree(T1 key, T2 value) {
        Node<T1, T2>* current_node = Root;
        static int bl_height = 0;
        if(bl_height == 0) {
            Root->GetKey(key);
            Root->GetValue(value);
        }
        else {
            Node<T1, T2>* parent_ptr = nullptr;
            while (current_node != nullptr) {
                parent_ptr = current_node;
                if (key < current_node->FindKey()) {
                    current_node = current_node->FindLeft();
                }
                else {
                    current_node = current_node->FindRight();
                }
            }
            current_node = new Node <T1, T2>;
            current_node->GetKey(key);
            current_node->GetValue(value);
            current_node->GetParent(parent_ptr);
        }
    }
    ~Tree() {}
};



/*
template<class T1, class T2>
class RBTree {
private:
    T1 Key;
    T2 Value;
    RBTree<T1,T2> *Right = nullptr;
    RBTree<T1,T2> *Left = nullptr;
    RBTree<T1,T2> *Parent = nullptr;
    int BlackHeight = 0;
    bool Color = 0; // 0 - black, 1 - red
public:
    RBTree() {}
    void GetKey(T1 key) {
        Key = key;
    }
    void GetParent(RBTree *parent) {
        Parent = parent;
    }
    void GetValue(T2 value) {
        Value = value;
    }
    void GetColor(bool color) {
        Color = color;
    }
    RBTree* KnowLeft() {
        return Left;
    }
    RBTree* KnowRight() {
        return Right;
    }
    RBTree* KnowParent() {
        return Parent;
    }
    T1 KnowKey() {
        return Key;
    }
    T2 KnowValue() {
        return Value;
    }
    void PrintData() {
        std::cout << Key << " " << Value << "\n";
    }
    void AddInTree(T1 key, T2 value) {
        static int bl_height = 0;
        if(bl_height == 0) {
            Key = key;
            Value = value;
            Color = 0;
            bl_height += 1;
        }
        else {
            RBTree *current_root = this;
            RBTree *parent_ptr = nullptr;
            while (current_root != nullptr) {
                parent_ptr = current_root;
                if (key < current_root->KnowKey()) {
                    current_root = current_root->KnowLeft();
                }
                else {
                    current_root = current_root->KnowRight();
                }
            }
            current_root = new RBTree;
            current_root->GetParent(parent_ptr);
            current_root->GetKey(key);
            current_root->GetValue(value);
            current_root->GetColor(1);
        }
    }
    ~RBTree() {}
};
*/