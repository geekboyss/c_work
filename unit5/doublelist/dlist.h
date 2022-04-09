/* dlist.h */
#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DListElmt_
{
    void *data;
    struct DListElmt_ *prev;
    struct DListElmt_ *next;
}DListElmt;

typedef struct DList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destory)(void *data);
    DListElmt *head;
    DListElmt *tail;   
} DList;

/* Public Interface */
void dlist_init(DList *list, void (*destroy)(void *data));


