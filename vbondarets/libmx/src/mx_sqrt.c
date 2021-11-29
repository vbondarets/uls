#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x < 0) {
        return 0;
    }
    int i = 1;
    while (i < x) {
        if (i * i == x) {
            return i;
        }
        i++;
    }
    return 0;
}

