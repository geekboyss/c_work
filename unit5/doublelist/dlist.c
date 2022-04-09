/* dlist.c */
#include <stdio.h>
#include <string.h>

#include "dlist.h"

void dlist_init(DList *list, void (*destroy)(void *data))
{
    /* Initialize the list. */

    list->size = 0;
    list->destory = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void dlist_destroy(DList *list)
{
    void *data;

    while (dlist_size(list) > 0)
    {
        if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0
            && list->destory != NULL)
        {
            list->destory(data);
        }
        
    }
    memset(list, 0, sizeof(DList));
    
    

}