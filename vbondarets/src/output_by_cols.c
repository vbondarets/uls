#include "../inc/header.h"

int max_len_names(char **names) {
    int max = 0;
    int temp = 0;

    for (int i = 0; names[i]; i++) {
        temp = mx_strlen(names[i]);
        if (temp > max)
            max = temp;
    }
    if (max % 8 == 0)
        max += 8;
    else
        max = 8 - (max % 8) + max;
    return max;
}

void mx_print_tab(int len, int maxlen) {
    int count = 0;
    int p;

    p = maxlen - len;
    if (p % 8 != 0)
        count = (p / 8) + 1;
    else
        count = p / 8;
    for (int i = 0; i < count; i++)
        mx_printchar('\t');
}

static void printcols(char **names, int rows, int num, int maxlen) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < num; j += rows) {
            mx_printstr(names[i + j]);
            if (names[i + j + 1] && (i + j + rows < num))
                mx_print_tab(mx_strlen(names[i + j]), maxlen);
        }
        if (i != rows - 1)
            mx_printchar('\n');
    }
}

static void print_names(char **names, int maxlen, int wincol) {
    int rows;
    int cols = (wincol / maxlen) != 0 ? wincol / maxlen : 1;
    int num = 0;

    for(;names[num]; num++) {
    }
    if (maxlen * cols > wincol && cols != 1)
        cols--;
    if (num * maxlen > wincol) {
        rows = num / cols;
        if (rows == 0 || num % cols != 0)
            rows += 1;
        printcols(names, rows, num, maxlen);
    } else
        for (int i = 0; names[i]; i++) {
            mx_printstr(names[i]);
            if (names[i + 1]) 
                mx_print_tab(mx_strlen(names[i]), maxlen);
        }
        mx_printchar('\n');
}

void mx_output_by_cols(char **names) {
    int maxlen;
    struct winsize win;

    if (!names)
        return;
    maxlen = max_len_names(names);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1))
        print_names(names, maxlen, win.ws_col);
    else
        print_names(names, maxlen, 80);
}

