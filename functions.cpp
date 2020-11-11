#include "functions.hpp"

bool strings_compare(char *string1, char *string2) {
    int i = 0;
    while(string1[i] == string2[i]) {
        i++;
    }
    if(string1[i] < string2[i]) {
        return 0;
    }
    return 1;
}