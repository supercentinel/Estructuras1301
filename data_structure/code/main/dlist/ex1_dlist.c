#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

static void print_dlist(const DList *dlist)
{
    DListNode *node;
    int *data, i;

    fprintf(stdout, "El tamano de la lista es %d\n", dlist_size(dlist));
    i = 0;
    node = dlist_head(dlist);

    if(dlist_size(dlist) == 0)
    {
        fprintf(stdout, "La lista esta vacia\n");
        return;
    }

    while (1)
    {
        data = dlist_data(node);
        fprintf(stdout, "listaDoble.nodo[%03d] = %03d, %14p <- %p -> %p \n", i, *data, node->prev, node, node->next);

        i++;

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }

    return;
}

int main(int argc, char const *argv[])
{
    DList dlist;
    DListNode *node;

    int *data, i, e;

    dlist_init(&dlist, free);
    printf("Lista inicializada\n");

    node = dlist_head(&dlist);
    //node = dlist_tail(&dlist);
    for (i = 0; i < 10; i++)
    {
        
        //print_dlist(&dlist);
        
        if ((data = (int *)malloc(sizeof(int))) == NULL)
        {
            return 1;
        }

        *data = i;


        e = dlist_ins_next(&dlist, node, data);
        node = dlist_tail(&dlist);
        printf("error: %d\n", e);
        if(e != 0)
        {
            return 1;
        }
        //printf("Asignacion de %d nodo.dato\n", i);
    }

    //printf("EDED\n\n");
    
    print_dlist(&dlist);

    dlist_destroy(&dlist);

    return 0;
}
