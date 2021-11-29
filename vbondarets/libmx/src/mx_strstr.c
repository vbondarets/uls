#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    int offset = 0;
    
    while (offset + mx_strlen(s2) <= mx_strlen(s1)) {
        if (!mx_strncmp(s1+offset, s2, mx_strlen(s2)))
            return (char *)s1 + offset;
        offset++;
    }
    return 0;
}

