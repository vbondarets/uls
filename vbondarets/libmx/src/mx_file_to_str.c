#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {
    if (filename) {
        int src = open(filename, O_RDONLY);

        if (src > 0) {
            char buff[64], *text = NULL;
            int rd = read(src, &buff, sizeof(buff));
            int count = rd;
            
            if (rd) {
                while (rd == 64) {
                    rd = read(src, &buff, sizeof(buff));
                    count += rd;
                }
                close(src);
                text = (char *)malloc(sizeof(char) * count + 1);
                src = open(filename, O_RDONLY); 
                rd = read(src, text, count);
                text[count] = '\0';
                close(src);
                return text;
            }
        }
        close(src);
    }
    return NULL;
}

