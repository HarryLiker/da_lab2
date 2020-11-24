#include "functions.hpp"

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

bool strings_compare(const char *string1, const char *string2) {
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

int equal_strings(const char *string1, const char *string2) {
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


void str_copy(const char *line, char *string) {
    int i = 0;
    while (i < 256 && line[0] != '\0') {
        string[i] = line [i];
        i++;
    }
}