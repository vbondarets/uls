#include "../inc/header.h"

char *permissions(mode_t perm){ // доступ в формате "rwxr-r -"
    //mx_printstr("vot1\n");
    char *file_descript = mx_strnew(11);
    file_descript[0] = (perm & S_IFDIR) ? 'd' : '-';
    file_descript[1] = (perm & S_IRUSR) ? 'r' : '-';
    file_descript[2] = (perm & S_IWUSR) ? 'w' : '-';
    file_descript[3] = (perm & S_IXUSR) ? 'x' : '-';
    file_descript[4] = (perm & S_IRGRP) ? 'r' : '-';
    file_descript[5] = (perm & S_IWGRP) ? 'w' : '-';
    file_descript[6] = (perm & S_IXGRP) ? 'x' : '-';
    file_descript[7] = (perm & S_IROTH) ? 'r' : '-';
    file_descript[8] = (perm & S_IWOTH) ? 'w' : '-';
    file_descript[9] = (perm & S_IXOTH) ? 'x' : '-';
    file_descript[10] = '\0';
    return file_descript;
}

char *file_description(char *str){
    struct stat statbuf;
    lstat(str, &statbuf);
    char *file_descript = mx_strnew(11);
    file_descript = mx_strdup(permissions(statbuf.st_mode));
    //mx_strjoin(file_descript, "\t");
    //char *count = mx_itoa(statbuf.st_nlink);
    //mx_strjoin(file_descript, count);
    //#pashnevpidor 
    return file_descript;
}

