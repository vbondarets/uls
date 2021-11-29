#include "../inc/libmx.h"

void mx_pop_front(t_list **list) 
{
    t_list *temp = NULL;
    if (list == NULL || *list == NULL)
        return;
    
    if ((*list)->next == NULL) 
    {
        free(*list);
        *list = NULL;
    } 
    else 
    {
        temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}

