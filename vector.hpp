#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>

template <class T>
class Vector {
private:
    int Size;
    int Capacity;
    T* Data;
public:
    Vector()
    {
        Size = 0;
        Capacity = 1;
        Data = new T[Capacity];
    }
    Vector(size_t capacity) {
        Size = 0;
        Capacity = capacity;
        Data = new T[capacity];
    }

    int FindSize() {
        return Size;
    }

    void PushBack(T elem) {
        Size++;
        if (Size <= Capacity) {
            Data[Size-1] = elem;
        }
        else {
            T *newdata = new T[Capacity*2];
            std::memcpy(newdata, Data, Capacity * sizeof(T));
            delete [] Data;
            Data = newdata;
            Data[Size-1] = elem;
            Capacity *= 2;
        }
    }

    void Print() {
        for (int i = 0; i < Size; i++) {
            std::cout << Data[i] << " ";
        }
    }

    void Clear() {
        delete [] Data;
        Capacity = 0;
        Size = 0;
        Data = nullptr;
    }

    ~Vector() {
        Clear();
    }
};