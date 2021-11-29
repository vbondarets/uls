#include "../inc/header.h"

int element_count(char *path) {
    DIR *dir;
    struct dirent *dent = NULL;
    dir = opendir(path);
    if (dir == 0)
        return 1;
    int element_count = 0;
    while((dent = readdir(dir)) != NULL) {
        if(dent -> d_name[0] == '.') {
        } 
        else {
            element_count++;
        }
    }
    free(dent);
    closedir(dir);
    return ++element_count;
}

