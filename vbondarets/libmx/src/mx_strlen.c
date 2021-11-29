#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int count = 0;
    while(s[count] != '\0') {
        count++;
    }
    return count;
}

