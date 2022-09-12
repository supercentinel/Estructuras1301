#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
    DList dlist;
    DListNode *node;

    int *data, i, s, j;
    char *nc, *nc2;

    nc = argv[1];
    nc2 = argv[2];

    if(argc < 3) return 1;

    dlist_init(&dlist, free);

    //Llenando la lista
    node = dlist_head(&dlist);
    for (i = 0; i < 10; i++)
    {
        
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        
        *data = i;

        if(dlist_ins_next(&dlist, node, data) != 0 )
            return 1;
        
        node = dlist_tail(&dlist);
    }

    print_dlist(&dlist);

    //Removiendo la cabeza de la lista
    i = 0;
    node = dlist_head(&dlist);
    data = dlist_data(node);

    fprintf(stdout, "\nRemoviendo cabeza:\nNodo[%03d] = %03d, %p <- %p -> %p\n", i, *data, node->prev, node, node->next);

    if(dlist_remove(&dlist, node, (void**)&data) != 0)
       return 1;

    print_dlist(&dlist);

    //Removiendo la cola de la lista
    i = dlist_size(&dlist);
    node = dlist_tail(&dlist);
    data = dlist_data(node);

    fprintf(stdout, "\nRemoviendo cola:\nNodo[%03d] = %03d, %p <- %p -> %p\n", i, *data, node->prev, node, node->next);

    if(dlist_remove(&dlist, node, (void**)&data) != 0)
        return 1;

    print_dlist(&dlist);

    /*
    node = dlist_head(&dlist);

    for(i = 0; i < 3; i++)
        node = dlist_next(node);    
    data = dlist_data(node);

    fprintf(stdout, "\nInsertando despues:\nNodo[%03d] = %03d, %p <- %p -> %p\n", i, *data, node->prev, node, node->next);

    if((data2 = (int *)malloc(sizeof(int))) == NULL)
        return 1;

    *data2 = 377;

    if(dlist_ins_next(&dlist, node, data2) != 0)
        return 1;
    
    print_dlist(&dlist);

    data2 = NULL;
    free(data2); 
    */
    //Insertando primer numero de cuenta a la mitad de la lista
    node = dlist_head(&dlist);

    j = dlist_size(&dlist)/2;

    if(j % 2 == 0) j = j - 1;

    for(i = 0; i < j; i++)
        node = dlist_next(node);

    data = dlist_data(node);
    fprintf(stdout, "\nInsertando primer numero de cuenta %s a la mitad:\nNodo[%03d] = %03d, %p <- %p -> %p\n", nc, i, *data, node->prev, node, node->next);

    if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
    *data = atoi(nc);

    if(dlist_ins_next(&dlist, node, data) != 0)
        return 1;

    print_dlist(&dlist);

    //Insertando segundo numero de cuenta en la cola de la lista
    node = dlist_tail(&dlist);
    data = dlist_data(node);
    i = dlist_size(&dlist);

    fprintf(stdout, "\nInsertando segundo numero de cuenta %s en la cola:\nNodo[%03d] = %03d, %p <- %p -> %p\n", nc2, i, *data, node->prev, node, node->next);

    if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
    *data = atoi(nc2);

    if(dlist_ins_next(&dlist, node, data) != 0)
        return 1;

    print_dlist(&dlist);

    //insertando Sumatoria de los numeros de cuenta en la cabeza    
    strcat(nc, nc2);

    i = 0;
    s = 0;
    while (nc[i] != '\0')
    {
        s += (nc[i] - '0');
        i++; 
    }
    
    i = 0;

    printf("\nLa sumatoria de los numeros de cuenta es %d", s);

    node = dlist_head(&dlist);
    data = dlist_data(node);
    
    fprintf(stdout, "\nInsertando sumatoria de los numeros de cuenta %s en la cabeza:\nNodo[%03d] = %03d, %p <- %p -> %p\n", nc2, i, *data, node->prev, node, node->next);

    if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
    *data = s;

    if(dlist_ins_prev(&dlist, node, data) != 0)
        return 1;

    print_dlist(&dlist);

    //Removiendo nodo 7 y 5
    node = dlist_head(&dlist);

    for (i = 0; i < 6; i++)
        node = dlist_next(node);
    data = dlist_data(node);
    

    fprintf(stdout, "\nRemoviendo el septimo y quinto nodo:\nNodo[%03d] = %03d, %p <- %p -> %p\n", i, *data, node->prev, node, node->next);
    
    dlist_remove(&dlist, node, (void**)&data);

    node = dlist_head(&dlist);
    
    for (i = 0; i < 4; i++)
        node = dlist_next(node);
    data = dlist_data(node);
    
    
    fprintf(stdout, "Nodo[%03d] = %03d, %p <- %p -> %p\n", i, *data, node->prev, node, node->next);

    dlist_remove(&dlist, node, (void**)&data);


    print_dlist(&dlist);
    

    //insertando 
    /*dlist_size(&dlist);
    
    node = dlist_head(&dlist);


    /*

    i = 0;
    s2 = 0;

    while (nc2[i] != '\0')
    {
        s2 += (nc2[i] - '0');
        i++; 
    }

    printf("Insertando ");

    printf("\nLa sumatoria de %s es %d\n\n", nc2, s2);
    */

    

    dlist_destroy(&dlist);

    return 0;
}
