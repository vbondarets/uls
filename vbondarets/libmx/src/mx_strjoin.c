#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (!s1 && !s2)
        return NULL;
    else if (!s1)
        return mx_strdup(s2);
    else if (!s2)
        return mx_strdup(s1);
    
    char *copy = NULL;
    copy = mx_strnew(mx_strlen(s1)+mx_strlen(s2)+1);
    copy = mx_strcpy(copy, s1);
    copy = mx_strcat(copy, s2);
    return copy;
}

