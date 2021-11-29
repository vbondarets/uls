#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *start = dst;

    while (*src) {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
    return start;
}

