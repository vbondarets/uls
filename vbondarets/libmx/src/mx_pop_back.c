#include "../inc/libmx.h"

void mx_pop_back(t_list **list) {
    if (*list == NULL) return;
    t_list *temp = *list;
    while (temp -> next -> next) 
        temp = temp -> next;
    free(temp -> next);
    temp -> next = NULL;
    temp = NULL;
}

