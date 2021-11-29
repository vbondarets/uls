#include "../inc/header.h"

bool with_flag(char *argv[]) {
    if (mx_strcmp("-", argv[1]) == 0) {
        return true;
    }
    return false;
}

