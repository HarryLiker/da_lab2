#include "functions.hpp"

bool strings_compare(const char *string1, const char *string2) {
    int i = 0;
    while(string1[i] == string2[i]) {
        i++;
    }
    if(string1[i] < string2[i]) {
        return 0;
    }
    else if (string1[i] > string2[i]) {
        return -1;
    }
    return 1;
}

bool equal_strings(const char *string1, const char *string2) {
    int i = 0;
    while ((string1[i] == string2[i]) && (string1[i] != '\0')) {
        i++;
    }
    if (string1[i] == string2[i]) {
        return 0;
    }
    return 1;
}