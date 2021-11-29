#include "../inc/header.h"

void dir_output(int argc, char **argv){
    DIR *dir = NULL;
    struct dirent *dent = NULL;
    //dir = opendir(argv[1]);

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
    
    int counter_dir = 0, counter_files = 0;
    bool good;
    
    for (int i = 1; i < argc; i++){
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
        /*dir = opendir(argv[i]);         
        mx_printstr(argv[i]);
        mx_printstr(":\n");*/
        /*while((dent = readdir(dir)) != NULL) {     
            if((mx_strcmp(dent -> d_name, ".") == 0 || mx_strcmp(dent -> d_name, "..") == 0 || (*dent -> d_name) == '.' )) {
                continue;
            }                
            mx_printstr(dent -> d_name);    
            mx_printstr("\t\t");           
        }    
        mx_printstr("\n\n");      */  
    } 
    //closedir(dir);
    mx_bubble_sort(arr_dir, counter_dir);
    mx_bubble_sort(arr_files, counter_files);

//out files
    for (int i = 0; i < counter_files; i++) {
        mx_printstr(arr_files[i]);
        mx_printstr("\t");
    }
    if (counter_files != 0)
        mx_printstr("\n\n");

//out dirs
    for (int i = 0; i < counter_dir; i++)
    {
        mx_printstr(arr_dir[i]);
        mx_printstr(":\n");
        def_output(dir, dent, arr_dir[i]);
        if(i != counter_dir - 1)
            mx_printstr("\n");
    }


    /*for (int i = 2; i < argc; i++){
        dir = opendir(argv[i]);         
        mx_printstr(argv[i]);
        mx_printstr(":\n");    
        while((dent = readdir(dir)) != NULL) {                    
            mx_printstr(dent -> d_name);    
            mx_printstr("\t\t");           
        }    
        mx_printstr("\n\n");        
    }*/            
        

}

