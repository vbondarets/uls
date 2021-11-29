#include "../inc/header.h"

int mx_strcmp_for_it(const char *s1, const char *s2){
    while(*s1 && *s1 == *s2){
        s1++;
        s2++;
    }

    return *s1 - *s2;

}

int max_byte_count = 0;

void flag_and_dir_out(int argc, char **argv) {
    DIR *dir = NULL;
    struct dirent *dent = NULL;
    //dir = opendir("./");

    char **arr_dir = malloc(sizeof(char*) * argc);
    for (int i = 0; i < argc; i++)
    {
        arr_dir[i] = mx_strnew(20);
    }
    char **arr_files = malloc(sizeof(char*) * argc);
    for (int i = 0; i < argc; i++)
    {
        arr_files[i] = mx_strnew(20);
    }
    bool good = true;
    int counter_dir = 0, counter_files = 0;
    for (int i = 2; i < argc; i++){
        if (opendir(argv[i]) != 0) {
            arr_dir[counter_dir] = mx_strdup(argv[i]);
            counter_dir++;
        }
        else {
            dir = opendir("./");
            while ((dent = readdir(dir)) != NULL)
            {
                if (mx_strcmp_for_it(dent -> d_name, argv[i]) == 0) {
                    good = true;
                    break;
                }
                good = false;
                
            }
            closedir(dir);
            if (!good) {
                mx_printerr("uls: ");
                mx_printerr(argv[i]);
                mx_printerr(": No such file or directory\n");
                continue;
            }
            arr_files[counter_files] = mx_strdup(argv[i]);
            counter_files++;
        }
        //closedir(dir);
    } 
    mx_bubble_sort(arr_dir, counter_dir);
    mx_bubble_sort(arr_files, counter_files);

//out files
    max_byte_count = max_bytes(arr_files, counter_files, "./");
    for (int i = 0; i < counter_files; i++) {
        l_flag(arr_files[i]);
        //mx_printstr("\t");
    }
    if (counter_files != 0)
        mx_printstr("\n");

    //out dirs
    for (int i = 0; i < counter_dir; i++)
    {
        mx_printstr(arr_dir[i]);
        mx_printstr(":\n");
        l_flag(arr_dir[i]);
        if(i != counter_dir - 1)
            mx_printstr("\n");
    }
}

