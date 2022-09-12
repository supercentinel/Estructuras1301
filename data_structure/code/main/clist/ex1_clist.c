#include <stdio.h>
#include <stdlib.h>

#include "clist.h"

static void print_clist(const CList *clist)
{
    CListNode *node;
    int *data, i;

    fprintf(stdout, "El tamano de la lista es: %d\n", clist_size(clist));

    if(clist_size(clist) == 0)
    {
        fprintf(stdout, "La lista esta vacia\n");
        return;
    }

    node = clist_head(clist);

    while (1)
    {
        data = clist_data(node);
        fprintf(stdout, "Lista Circular.node[%03d] = %03d, %p -> %p\n", i, *data, node, node->next);
        i++;

        if(i > 2/*clist_size(clist)*/)
            break;
        else
            node = clist_next(node);
    }
    
    return;
}

int main(int argc, char const *argv[])
{
    CList clist;
    CListNode *node;

    int *data, i;

    clist_init(&clist, free);
    printf("lista circular inicializada\n");

    node = clist_head(&clist);

    data = (int *)malloc(sizeof(int));

    *data = 777;

    //clist_ins_next(&clist, NULL, data);
    //node = clist_head(&clist);
    clist_ins_next(&clist, clist.head, data);
    node = clist_next(clist.head);
    clist_ins_next(&clist, node, data);

    //node = clist_head(&clist);

    //clist_ins_next(&clist, node, data);

    /*for (i = 10; i > 0; i--)
    {
        if((data = (int *)malloc(sizeof(int))) == NULL)
        {
            return 1;
        }
        
        *data = i;

        if((clist_ins_next(&clist, node, data)) != 0)
        {
            return 1;
        }
        
        node = clist_head(&clist);


    }*/
    
    print_clist(&clist);

    clist_destroy(&clist);
    


    return 0;
}
