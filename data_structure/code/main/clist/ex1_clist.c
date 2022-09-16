#include <stdio.h>
#include <stdlib.h>

#include "clist.h"

static void print_clist(const CList *clist)
{
    CListNode *node;
    int *data, i = 0;

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

        if(i > clist_size(clist)-1)
            break;
        else
            node = clist_next(node);
    }
    
    return;
}

int main(int argc, char *argv[])
{
    CList clist;
    CListNode *node;

    char *nc, *nc2;
    int *data, i, s = 0;

    if(argc < 3) return 1;

    nc = argv[1];
    nc2 = argv[2];

    //Lista Inicializada
    clist_init(&clist, free);
    printf("lista circular inicializada\n");

    for (int i = 0; i < 10; i++)
    {
        if((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

       *data = i;
       
        if(i == 0) 
        {
            if(clist_ins_next(&clist, NULL, data) != 0) return 1;
            node = clist_head(&clist);
            continue;
        }

        node = clist_next(node);

        if(clist_ins_next(&clist, node, data) != 0) return 1;

    }

    print_clist(&clist);

    //Removiendo cabeza de la lista
    node = clist_head(&clist);
    data = clist_data(node);
    i = 0;

    fprintf(stdout, "Removiendo cabeza de la lista:\nCabeza[%03d] = %d, %p -> %p\n", i, *data, node, node->next);

    for (i = 0; i < clist_size(&clist) - 1; i++)
    {
        node = clist_next(node);
    }

    if(clist_rem_next(&clist, node, (void**)data) != 0) return 1;

    print_clist(&clist);

    //Removiendo el cuarto nodo
    node = clist_head(&clist);

    for (i = 0; i < 3; i++)
    {
        node = clist_next(node);
    }

    data = clist_data(node);

    fprintf(stdout, "Removiendo el cuarto nodo:\nNodo[%03d] = %d, %p -> %p\n", i, *data, node, node->next);

    node = clist_head(&clist);
    for (i = 0; i < 2; i++)
    {
        node = clist_next(node);
    }

    if(clist_rem_next(&clist, node, (void**)data) != 0) return 1;

    print_clist(&clist);
    
    //Insertando numero de cuenta antes de la cabeza

    node = clist_head(&clist);

    if((data = malloc(sizeof(int))) == NULL) return 1;

    *data = atoi(nc);

    for (i = 0; i < clist_size(&clist) - 1; i++)
    {
        node = clist_next(node);
    }

    if(clist_ins_next(&clist, node, data) != 0) return 1;

    fprintf(stdout, "Anadiendo el primer numero de cuenta antes de la cabeza:\nNodo[%03d] = %d, %p -> %p\n", i+1, *data, node, node->next);

    print_clist(&clist);
    
    //Insertando 4 nodo. Que? No se. En el cuarto nodo? Tampoco lo se
    node = clist_head(&clist);

    for (i = 0; i < 2; i++)
    {
        node = clist_next(node);
    }

    if((data = malloc(sizeof(int))) == NULL) return 1;

    *data = 42069;

    if(clist_ins_next(&clist, node, data) != 0) return 1;

    fprintf(stdout, "Insertando cuarto nodo:\nNodo[%03d] = %d, %p -> %p\n", i+1, *data, node, node->next);
    
    print_clist(&clist);

    //Insertando la suma de la sumatoria del primer numero de cuenta mas el segundo numero de cuenta. Donde? no lo se, a la mitad
    i = 0;
    while (nc[i] != '\0')
    {
        s += (nc[i] - '0');
        i++;
    }

    if((data = malloc(sizeof(int))) == NULL) return 1;

    *data = s + atoi(nc2);

    node = clist_head(&clist);

    for (i = 0; i < (clist_size(&clist) / 2) - 1; i++)
    {
        node = clist_next(node);
    }
    
    if(clist_ins_next(&clist, node, data) != 0) return 1;

    fprintf(stdout, "Insertando la suma de la sumatoria del primer numero de cuenta mas el segundo numero de cuenta a la mitad:\nNodo[%03d] = %d, %p -> %p\n", i+1, *data, node, node->next);
    
    print_clist(&clist);

    clist_destroy(&clist);
    
    return 0;
}
