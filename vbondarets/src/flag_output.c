#include "../inc/header.h"

void flag_output(int argc, char * argv[]){
    //DIR *dir;
    //struct dirent *dent = NULL;
    char *flag = argv[1];
    if(mx_strcmp(flag, "-l") == 0) {
        
        if (argc == 2) {
            l_flag("./");
        }
        else {
            flag_and_dir_out(argc, argv);
        }
        
    }
    else if(mx_strcmp(flag, "-R") == 0){
        mx_printstr("Nam pizda");
    }

//mx_printstr(&flag[0]);
//printf("\n\n\n, %d", argc);
//mx_printint(argc);
//mx_printstr(argv[0]);
}
