#include "../inc/header.h"

bool *flags;

int main(int argc, char *argv[]) {
    //mx_printint('\0');
    DIR *dir;
    struct dirent *dent = NULL;
    dir = opendir(argv[1]);  
    if (argc == 1){
        def_output(dir, dent, "./");
    }
    else if (argc > 1 ){
        if(with_flag(argv)){
            int res;
            while((res = getopt(argc, argv, "@1AaCcfGhilmnoRrSTtu")) != -1) {
                switch (res) {
                case 'l':
                    flag_output(argc, argv);
                break;
                case '?':
                    mx_printerr("usage: uls [-ACGRSTacfhilmnortu1@] [file ...]\n");
                    exit(1);
                }
            }
            /*if(mx_strcmp(argv[1], "-l") == 0) {
                flag_output(argc, argv);
            }
            else {
                char *buf = argv[1];
                
                mx_printerr("uls: illegal option -- ");
                mx_printerr(&buf[1]);
                mx_printstr("\n");
                mx_printerr("usage: uls [-l] [file ...]\n");

            }*/
        }
        else {
            dir_output(argc, argv);   
        }  
    }

    return(argc);


}

