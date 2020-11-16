#include <iostream>
#include "functions.hpp"

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
        while (x != TNull && equal_strings(key, x->FindKey()) == 1) { // 
            if (strings_compare(key, x->FindKey()) == 0) {
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
        Node<T1,T2> *y = x->FindRight();
        x->GetRight(y->FindLeft());
        if (y->FindLeft() != TNull) {
            y->FindLeft()->GetParent(x);
        }
        y->GetParent(x->FindParent());
        if (x->FindParent() == TNull) {
            Root = y;
        }
        else if (x == x->FindParent()->FindLeft()) {
            x->FindParent()->GetLeft(y);
        }
        else {
            x->FindParent()->GetRight(y);
        }
        y->GetLeft(x);
        x->GetParent(y);
    }

    void RightRotation(Node<T1,T2>* x) {
        Node<T1,T2> *y = x->FindLeft();
        x->GetLeft(y->FindRight());
        if (y->FindRight() != TNull) {
            y->FindRight()->GetParent(x);
        }
        y->GetParent(x->FindParent());
        if (x->FindParent() == TNull) {
            Root = y;
        }
        else if (x == x->FindParent()->FindRight()) {
            x->FindParent()->GetRight(y);
        }
        else {
            x->FindParent()->GetLeft(y);
        }
        y->GetRight(x);
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



    void Insert(T1 key, T2 value) {
        Node<T1, T2>* current_root;
        if (Root == nullptr) {
            Root = new Node<T1, T2>;
            Root->GetKey(key);
            Root->GetValue(value);
            Root->GetColor(BLACK);
        }
        else {
            current_root = Root;
            Node<T1, T2>* parent_ptr;
            while(current_root != nullptr) {
                parent_ptr = current_root;
                if (strings_compare(key, current_root->FindKey()) == 0) {
                    current_root = current_root->FindLeft();
                }
                else {
                    current_root = current_root->FindRight();
                }
            }
            current_root = new Node<T1, T2>;
            if (strings_compare(key, parent_ptr->FindKey()) == 0) {
                parent_ptr->GetLeft(current_root);
            }
            else {
                parent_ptr->GetRight(current_root);
            }
            current_root->GetKey(key);
            current_root->GetValue(value);
            current_root->GetParent(parent_ptr);
            current_root->GetColor(RED);
            Fixup(current_root);
        }
    }

    void Insert2(Node<T1, T2>* z) {
        Node<T1, T2> *y = TNull;
        Node<T1,T2> *x = Root;
        while (x != TNull && Root != nullptr) {
            y = x;
            if (strings_compare(z->FindKey(), x->FindKey()) == 0) {
                x = x->FindLeft();
            }
            else {
                x = x->FindRight();
            }
        }
        z->GetParent(y);
        if (y == TNull) {
            Root = z;
        }
        else if (strings_compare(z->FindKey(), y->FindKey()) == 0) {
            y->GetLeft(z);
        }
        else {
            y->GetRight(z);
        }
        z->GetLeft(TNull);
        z->GetRight(TNull);
        z->GetColor(RED);
        Fixup(z);
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
        delete z;
    }


    ~Tree() {}
};

/*

template<class T1, class T2>
void LeftRotation(Tree<T1,T2>* root, Node<T1,T2>* x) {
    Node<T1,T2>* y = x->FindRight();
    x->GetRight(y->FindLeft());
    if (y->FindLeft() != nullptr) {
        y->FindLeft()->GetParent(x);
    }
    if (y != nullptr) {
        y->GetParent(x->FindParent());
    }
    if (x->FindParent()) {
        if (x == x->FindParent()->FindLeft()) {
            x->FindParent()->GetLeft(y);
        }
        else {
            x->FindParent()->GetRight(y);
        }
    }
    else {
        root = y;
    }
    y->GetLeft(x);
    if (x != nullptr) {
        x->GetParent(y);
    }
}

*/

/*

template<class T1, class T2>
void RightRotation(Node<T1, T2>* root, Node<T1, T2>* x) {
    Node<T1,T2>* y = x->FindLeft();
    x->GetLeft(y->FindRight());
    if (y->FindRight() != nullptr) {
        y->FindRight()->GetParent(x);
    }
    if (y != nullptr) {
        y->GetParent(x->FindParent());
    }
    if (x->FindParent()) {
        if (x == x->FindParent()->FindRight()) {
            x->FindParent()->GetRight(y);
        }
        else {
            x->FindParent()->GetLeft(y);
        }
    }
    else {
        root = y;
    }
    y->GetRight(x);
    if (x != nullptr) {
        x->GetParent(y);
    }
}

*/


/*

template<class T1, class T2>
void Fixup(Node<T1, T2> *tree, Node<T1, T2>* x) {
    while (x->FindParent()->FindColor() == RED) {
        if (x->FindParent() == x->FindParent()->FindParent()->FindLeft()) {
            Node<T1, T2>* y;
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
                    // LEFT ROTATION (tree, x)
                    LeftRotation(tree, x);
                }
            
            x->FindParent()->GetColor(BLACK);
            x->FindParent()->FindParent()->GetColor(RED);
            // RIGHT ROTATION (tree, x->parent->parent)
            RightRotation(tree, x);
            }
        }
        else {
            Node<T1,T2>* y;
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
                    RightRotation(tree, x);
                }
                x->FindParent()->GetColor(BLACK);
                x->FindParent()->FindParent()->GetColor(RED);
                LeftRotation(tree, x->FindParent()->FindParent());
            }
        }
    }
    tree->FindRoot()->GetColor(BLACK);
}

*/