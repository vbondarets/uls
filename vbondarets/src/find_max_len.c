#include "../inc/header.h"

int find_max_len(char **arr, int count) {
    int max_len = 0;
    for (int i = 0; i < count; i++) {
        if (mx_strlen(arr[i]) > max_len) {
            max_len = mx_strlen(arr[i]);
        }
    }
    return max_len;
}

