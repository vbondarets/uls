#include "../inc/header.h"

int max_links(char **arr_files, int count) {
    int max = 0;
    for (int i = 0; i < count; i++)
    {
        struct stat buf;
        lstat(arr_files[i], &buf);
        if (buf.st_nlink > max)
            max = buf.st_nlink;
    }
    return max;
}

