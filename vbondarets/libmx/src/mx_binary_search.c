#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    bool b = false;
    int l = 0;
    int r = size - 1;
    int mid = 0;
    int c = 0;

    while (l <= r && b != true) {
        mid = (l + r) / 2;
        if (mx_strcmp(arr[mid], s) == 0) {
            b = true;
        }
        if (mx_strcmp(arr[mid], s) > 0) {
            r = mid - 1;
            c++;
        }
        else {
            l = mid + 1;
            c++;
        }
    }
    *count = c;
    if (b == true) {
        return mid;
    }
    else {
        *count = 0;
        return -1;
    }
}

