#pragma once

template<class T1, class T2>
class TPair {
private:
    T1 Key;
    T2 Value;
public:
    TPair() {}
    TPair(T1 key, T2 value): Key(key), Value(value) {}
    void GetKey(T1 key) {
        Key = key;
    }
    void GetValue(T2 value) {
        Value = value;
    }
    T1 FindKey() {
        return Key;
    }
    T2 FindValue() {
        return Value;
    }
    ~TPair() {}
};