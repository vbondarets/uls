#include "../inc/header.h"

int max_bytes(char **arr_files, int count, char *path) {
    int max = 0;
    for (int i = 0; i < count; i++)
    {
        char *path_temp = mx_strdup(path);
        //path_temp = mx_strjoin(path_temp, "/");
        path_temp = mx_strjoin(path_temp, arr_files[i]);

        struct stat buf;
        lstat(path_temp, &buf);
        if (buf.st_size > max)
            max = buf.st_size;
        mx_strdel(&path_temp);
    }
    return max;
}

