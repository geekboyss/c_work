#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void destory(void *data) {
    free(data);
}

int main() {
    
    List *list = (List *)malloc(sizeof(List));
    list_init(list, &destory);
    
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    *d1 = 12;
    *d2 = 34;
    *d3 = 43;
    
    int *d4;

    list_ins_next(list, NULL, d1);
    list_ins_next(list, NULL, d2);
    list_ins_next(list, list_tail(list), d3);
    // 34 , 12, 43

    printf("%d\n", *(int *)(list->head->data));
    printf("%d\n", *(int *)(list->tail->data));
    
    list_rem_next(list, NULL, (void **)&d4);
    printf("%d\n", *d4);    

    printf("删除后 头元素: %d\n", *(int *)(list_head(list)->data));
    return 0;

}
