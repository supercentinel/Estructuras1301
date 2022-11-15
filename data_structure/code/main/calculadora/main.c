#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "stack.h"

static void print_list (const List *list) {
    ListNode *node;
    int i;
    char *data;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%03c, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}

int filtrar(char c)
{
    switch (c)
    {
    case 37:
        return 0;
    break;
    case 40:
        return 0;
    break;
    case 41:
        return 0;
    break;
    case 42:
        return 0;
    break;
    case 43:
        return 0;
    break;
    case 45:
        return 0;
    break;
    case 47:
        return 0;
    break;
    case 48:
        return 1;
    break;
    case 49:
        return 1;
    break;
    case 50:
        return 1;
    break;
    case 51:
        return 1;
    break;
    case 52:
        return 1;
    break;
    case 53:
        return 1;
    break;
    case 54:
        return 1;
    break;
    case 55:
        return 1;
    break;
    case 56:
        return 1;
    break;
    case 57:
        return 1;
    break;
    case 94:
        return 0;
    break;
    default:
        return -1;
    break;
    }

}

int insert(List *infix, char *ifs)
{
    int i, sl = strlen(ifs);
    char *data;
    ListNode *node;

    node = list_head(infix);

    for (i = 0; i < sl; i++)
    {
        if(filtrar(ifs[i]) == -1) return -1;

        if((data = (char *)malloc(sizeof(char))) == NULL) return -1;

        *data = ifs[i];


        if(list_ins_next(infix, NULL, data) != 0) return 0;

    }
    
}

int infixToPosfix(List *infix, List *posfix)
{
    int i = 0, iflen = list_size(infix);

    char *data;

    Stack stack;
    ListNode *nodeif, *nodepf;

    stack_init(&stack, free);

    nodeif = list_head(infix);
    nodepf = list_head(posfix);

    for (i = 0; i < iflen; i++)
    {
        if((data = (char *)malloc(sizeof(char))) == NULL) return -1;

        data = list_data(nodeif);

        if(filtrar(data) == 1)
        {
            if(list_ins_next(posfix, NULL, data) != 0) return -1;
        }else
        {
            if((stack_push(&stack, data)) != 0) return -1;
        }

    }
    
    stack_destroy(&stack);

}

int main(int argc, char *argv[])
{
   
    List infix;

    list_init(&infix, free);

    insert(&infix, argv[1]);
    print_list(&infix);
    
    list_destroy(&infix);

    return 0;
}
