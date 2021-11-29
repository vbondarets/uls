#include "../inc/header.h"

void def_output(DIR *dir, struct dirent *dent, char *dir_path) {
 
    
    dir = opendir(dir_path);
    int count = 0;
    while((dent = readdir(dir)) != NULL) {
        if(dent -> d_name[0] == '.') {
        } 
        else {
            count++;
        }
    }
    free(dent);
    closedir(dir);
    DIR *dir1;
    dir1 = opendir(dir_path);
    struct dirent *dent1 = NULL;
    char **arr_files = malloc(sizeof(char*) * ++count);
    for (int i = 0; i < count; i++)
    {
        arr_files[i] = mx_strnew(20);
    }
    int i = 0;
    while((dent1 = readdir(dir1)) != NULL) {
        if(dent1 -> d_name[0] == '.') {
        } 
        else {
            //mx_printstr("vot\n");
            arr_files[i] = mx_strdup(dent1 -> d_name);
            i++;
        }
    }
    mx_bubble_sort(arr_files, count);

    //struct winsize w;
    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   //int max_len = find_max_len(arr_files, count);
    //int cols = w.ws_col / (max_len + 3);
    //mx_printint(cols);
    //mx_printstr("\n");
    //mx_printint(w.ws_col);
    //mx_printstr("\n");
    //mx_printstr("\n");
    arr_files++;
    count -= 1;
    if(isatty(STDOUT_FILENO)){
        /*for (int j = 1; j < count; j++) {
            mx_printstr(arr_files[j]);
            if (j != count - 1) {
                if (mx_strlen(arr_files[j]) < 8)
                    mx_printstr("\t");
                mx_printstr("\t");
            }
        }*/
        mx_output_by_cols(arr_files);
    }
    else{
        for (int j = 0; j < count; j++) {
            mx_printstr(arr_files[j]);
            if (j != count - 1) {
                mx_printstr("\n");
            }
        }
    }
    //mx_output_by_cols(arr_files);
    

    //mx_printstr("\n");
    //mx_printint(argc);
    free(dent1);
    closedir(dir1);
    //mx_printint(max_len);
    /*if (max_len < 0) {
        mx_printint(1);
    }*/
}

