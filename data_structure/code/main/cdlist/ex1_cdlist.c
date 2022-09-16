#include <stdio.h>
#include <stdlib.h>

#include "cdlist.h"

static void print_cdlist(const CDList *cdlist)
{
    CDListNode *node;
    int *data, i = 0;

    fprintf(stdout, "El Tamano de la lista es %d\n", cdlist_size(cdlist));
    
    node = cdlist_head(cdlist);

    if(cdlist_size(cdlist) == 0)
    {
        fprintf(stdout, "La lista esta vacia\n");
        return;
    }

    while (1)
    {
        data = cdlist_data(node);
        fprintf(stdout, "ListaCircularDoble.nodo[%03d] = %03d, %14p <- %14p -> %14p \n", i, *data, node->prev, node, node->next);

        i++;

        if(i > cdlist_size(cdlist) -1)
            break;
        else
            node = cdlist_next(node);
    }
    
    return;
}

int main(int argc, char const *argv[])
{
    CDList cdlist;
    CDListNode *node;

    int *data, i;

    cdlist_init(&cdlist, free);
    printf("Lista inicializada\n");
    print_cdlist(&cdlist);

    //LLenando la lista
    for (i = 0; i < 10; i++)
    {
        if((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        
        *data = i;

        if(i == 0)
        {
            if(cdlist_ins_next(&cdlist, NULL, data) != 0) return 1;
            node = cdlist_head(&cdlist);
            continue;
        }

        node = cdlist_next(node);

        if(cdlist_ins_next(&cdlist, node, data) != 0) return 1;
    }
    
    print_cdlist(&cdlist);

    cdlist_destroy(&cdlist);

    return 0;
}
