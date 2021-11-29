#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    double res = 1;
    if (pow == 0) {
        return 1;
    }
    else if (pow > 0) {
        for (unsigned int i = 0; i < pow; i++) {
            res = res * n;
        }
        return res;
    }
    else if (pow < 0) {
        for (unsigned int i = 0; i < pow; i++) {
            res = res * 1 / n;
        }
        return res;
    }
    return res;
}

