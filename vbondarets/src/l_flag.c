#include "../inc/header.h"

void l_flag(char *path){
    int count = element_count(path);
    int max_byte;
    //mx_printint(count);
    DIR *dir1;
    bool total_need = false;
    char **arr_files = malloc(sizeof(char*) * count);
    if ((dir1 = opendir(path)) != 0) {
        total_need = true;
        //dir1 = opendir(path);
        //struct dirent *dent = NULL;
        struct dirent *dent1 = NULL;
        //char **arr_files = malloc(sizeof(char*) * count);
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
        arr_files++;
        count--;
        closedir(dir1);

        path = mx_strjoin(path, "/");
        max_byte = max_bytes(arr_files, count, path);
    }
    else {
        arr_files[0] = mx_strnew(20);
        arr_files[0] = path;
        path = "./";
        extern int max_byte_count;
        max_byte = max_byte_count;
    }
    int max_link = max_links(arr_files, count);
    //int max_byte = max_bytes(arr_files, count, path);
    //path = mx_strjoin(path, "/");
    ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    /////////Total OUTPUT
    if (total_need) {
        int blocks_count = 0;
        for(int i = 0; i < count; i++){
            struct stat statbuf;
            lstat(mx_strjoin(path, arr_files[i]), &statbuf);
            blocks_count += statbuf.st_blocks;
        }
        mx_printstr("total ");
        mx_printint(blocks_count);
        mx_printstr("\n");
    }
    for(int i = 0; i < count; i++){
        struct stat statbuf;
        struct passwd *user_name;
        struct group *group_name;
        //time_t t;
        //time(&t);
        //struct timespec
        {
            /* data */
        };
        
        lstat(mx_strjoin(path, arr_files[i]), &statbuf);

        char *file_descript = file_description(mx_strjoin(path, arr_files[i]));
        //////////drwxrwxr-x OUTPUT
        for(int n = 0; n <= 10; n++){
            mx_printchar(file_descript[n]);
        }
        mx_printstr("  ");
        //////////////// link count OUTPUT

        int link_count = statbuf.st_nlink;
        for (int j = 0; j < (mx_strlen(mx_itoa(max_link)) - mx_strlen(mx_itoa(link_count))); j++)
            mx_printstr(" ");
        mx_printint(link_count);
        /////////User name OUTPUT
        mx_printstr(" ");
        user_name = getpwuid(statbuf.st_uid);
        mx_printstr(user_name->pw_name);
        //////// Group name OUTPUT
        mx_printstr("  ");
        group_name = getgrgid(statbuf.st_gid);
        mx_printstr(group_name->gr_name);
        //////// Size OUTPUT
        mx_printstr("  ");
        int size_count = statbuf.st_size;
        for (int j = 0; j < (mx_strlen(mx_itoa(max_byte)) - mx_strlen(mx_itoa(size_count))); j++)
            mx_printstr(" ");
        mx_printint(size_count);
        //////// Time OUTPUT
        mx_printstr(" ");
        char *str_time = ctime(&statbuf.st_mtimespec.tv_sec);
        for(int t = 4; t < mx_strlen(str_time) - 9; t++){
            mx_printchar(str_time[t]);
        }
        /////// out name file
        mx_printstr(" ");
        mx_printstr(arr_files[i]);

        mx_printstr("\n");
    }
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    // output with stat
    //DIR *tempDir;
    /*for (int i = 1; i < count; i++)
    {
        //out dir or not
        if (opendir(arr_files[i]) != 0) {
            mx_printstr("d");
        }
        else {
            mx_printstr("-");
        }
        // out user permission
        


        //_______
        mx_printstr("\n");
    }
    
    //mx_printint(count);*/
    //free(dent);
    //closedir(dir);
    if (total_need) {
        arr_files--;
        count++;
    }
    for (int i = 0; i < count; i++) {
        free(arr_files[i]);
    }
    //free(arr_files);
    arr_files = NULL;

}

