#include "../inc/libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)) {
    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
}

