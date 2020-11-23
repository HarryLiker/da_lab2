#pragma once

namespace NPair {
    template<class T1, class T2>
    class TPair {
    public:
        T1 Key; // Ключ
        T2 Value; // Значение
        TPair() {}
        TPair(T1 k, T2 v): Key(k), Value(v) {}

        void GetKey(T1 key) {
            Key = new char [257];
            for (int i = 0; (i < 257 && key[i] != '\0'); i++) {
                Key[i] = key[i];
            }
        }

        ~TPair() {
            delete [] Key;
        }
    };
} // namespace NPair