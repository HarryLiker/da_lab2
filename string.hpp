#pragma once

#include <iostream>

namespace NString {
    class TString {
    private:
        char* String;
        size_t Size;
    public:
        TString() {
            string = new char [257];
            Size = 0;
        }

        void operator=(const TString &another_string) {
            
        }

        ~TString() {
            delete [] String;
        }
    }
}