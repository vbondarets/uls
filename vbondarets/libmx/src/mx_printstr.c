#include "../inc/libmx.h"

void mx_printstr(const char *);

int mx_strlen(const char *s);

void mx_printstr(const char *s) {
     int len = mx_strlen(s);
     write(1, s, len);
}

