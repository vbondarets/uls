#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *start = dst;

    while (len) {
        if(*src)
            *dst = *src;
        else
            *dst = '\0';        
        src++;
        dst++;
        len--;
    }
    return start;
}

