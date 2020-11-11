#include <iostream>

template<class T1, class T2>
class Node {
private:
    T1 Key;
    T2 Value;
    Node* Left;
    Node* Right;
    Node* Parent;
public:
    Node() {}
    void GetKey(T1 key) {
        Key = new char [256];
        for (int i = 0; i < 256; i++) { // Это работает
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
    ~Node() {}
};


template<class T1, class T2>
class Tree {
private:
    Node<T1, T2>* Root;
public:
    Tree() {}
    void GetKey(T1 key) {
        Root->GetKey(key);
    }
    void GetValue(T2 value) {
        Root->GetValue(value);
    }
    void AddInTree(T1 key, T2 value) {
        static int bl_height = 0;
        if (bl_height == 0) {
            Root = new Node<T1, T2>;
            Root->GetKey(key);
            Root->GetValue(value);
            bl_height += 1;
        }
        else {
            Node<T1, T2>* current_root;
            current_root = Root;
            Node<T1, T2>* parent_ptr;
            while(current_root != nullptr) {
                parent_ptr = current_root;
                if (key < current_root->FindKey()) {
                    current_root = current_root->FindLeft();
                }
                else {
                    current_root = current_root->FindRight();
                }
            }
            current_root = new Node<T1, T2>;
            parent_ptr->GetRight(current_root);
            current_root->GetKey(key);
            current_root->GetValue(value);
            current_root->GetParent(parent_ptr);
        }
    }
    ~Tree() {}
};