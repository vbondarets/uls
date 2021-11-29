#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"

#include <dirent.h>
#include <sys/types.h>
#include <limits.h> 
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <sys/ioctl.h>

enum description{ 
    d_dir, u_r, u_w, u_x, g_r, g_w, g_x, o_r, o_w, o_x
};

#define FLAG_SIZE 20
#define USAGE "usage: uls [-ACGRSTacfhilmnortu1@] [file ...]\n"

void flag_output(int argc, char * argv[]);
//bool *init_flags(int argc, char *argv[]);
//void default_output(DIR *, struct dirent *);
bool with_flag(char *argv[]);
//void output(bool *, int , char **, DIR *, struct dirent *);
void dir_output(int argc, char **argv);
int find_max_len(char **arr, int count);
void l_flag(char *path);
int element_count(char *path);
void def_output(DIR *dir, struct dirent *dent, char *dir_path);
char *file_description(char *str);
int max_links(char **arr_files, int count);
int max_bytes(char **arr_files, int count, char *path);
void flag_and_dir_out(int argc, char **argv);
void mx_output_by_cols(char **names);
int mx_strcmp_for_it(const char *s1, const char *s2);

#endif
