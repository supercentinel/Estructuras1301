/*
    cdlist.c
*/
#include <stdlib.h>
#include <string.h>

#include "cdlist.h"

/*
    Initialize the cdlist
*/
void cdlist_init (CDList *list, void (*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;
}

void cdlist_destroy (CDList *list) {
    void *data;

    while (cdlist_size(list) > 0) {
        if (cdlist_remove(list, list->head, (void **)&data) == 0 && list->destroy != NULL)
            list->destroy(data);
    }
    memset(list, 0, sizeof(CDList));
    return;
}

/*
    Insert next node at the cdlist
*/
int cdlist_ins_next (CDList *list, CDListNode *node, const void *data) {
    CDListNode *new_node;

    if ((new_node = (CDListNode *)malloc(sizeof(CDListNode))) == NULL)
        return -1;
    
    new_node->data = (void *)data;

    //The list is empty
    if(cdlist_size(list) == 0) {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
    } else {
        new_node->next = node->next;
        new_node->prev = node;

        node->next->prev = new_node;
        node->next = new_node;
    }

    list->size++;

    return 0;
}

/*
    Insert prev node at the cdlist
*/
int cdlist_ins_prev (CDList *list, CDListNode *node, const void *data) {
    CDListNode *new_node;

    //The list is empty
    if(cdlist_size(list) == 0){
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
    } else {
        new_node->next = node;
        new_node->prev = node->prev;

        node->prev->next = new_node;
        node->prev = new_node;
    }

    list->size++;

    return 0;
}

/*
    Remove node at the cldist
    **pending
*/
int cdlist_remove (CDList *list, CDListNode *node, void **data) {

    //List is empty
    if (node == NULL && cdlist_size(list) == 0)
        return -1;

    *data = node->data;

    //One node in the list
    if(node->next == node && node->prev == node) {
        list->head = NULL;
    } else {

        node->prev->next = node->next;
        node->next->prev = node->prev;

        if(node == cdlist_head(list))
            list->head = node->next;
    }

    free(node);
    list->size--;

    return 0;
}
