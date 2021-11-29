#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int or_l = mx_strlen(s1);

    for (int i = or_l, j = 0; i < or_l + mx_strlen(s2); i++, j++)
        s1[i] = s2[j];
    s1[or_l + mx_strlen(s2)] = '\0';
    return s1;
}

