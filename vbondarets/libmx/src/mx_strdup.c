#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *copy = mx_strnew(mx_strlen(str));
    copy = mx_strcpy(copy, str);
    return copy;
}

