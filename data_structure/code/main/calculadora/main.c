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
        fprintf(stdout, "list.node[%03d]= %s, %p -> %p \n", i, data, node, node->next);

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
    //mod
    case 37:
        return 2;
    break;
    //parentesis(
    case 40:
        return 4;
    break;
    //parentesis)
    case 41:
        return 5;
    break;
    //*
    case 42:
        return 2;
    break;
    //+
    case 43:
        return 1;
    break;
    //-
    case 45:
        return 1;
    break;
    // a/b
    case 47:
        return 2;
    break;
    //digitos
    case 48:
        return 0;
    break;
    case 49:
        return 0;
    break;
    case 50:
        return 0;
    break;
    case 51:
        return 0;
    break;
    case 52:
        return 0;
    break;
    case 53:
        return 0;
    break;
    case 54:
        return 0;
    break;
    case 55:
        return 0;
    break;
    case 56:
        return 0;
    break;
    case 57:
        return 0;
    break;
    //digitos
    //pow
    case 94:
        return 3;
    break;
    default:
        return -1;
    break;
    }

}

int insert(List *infix, char *ifs)
{
    int i, f = 0, sl = strlen(ifs);
    char *data, temp[2];
    ListNode *node;

    //iteramos sobre la entrada ifs
    for (i = 0; i < sl; i++)
    {
        //si no es ni digito ni operador se corta;
        if(filtrar(ifs[i]) == -1);
        //es un digito
        if(filtrar(ifs[i]) == 0)
        {
            if (f == 0)
            {
                if((data = (char *)malloc(sizeof(char) * 2)) == NULL) return -1;
                *data = ifs[i];
                data[1] = '\0';
            }
            
            f = 1;
            //si el siguiente caracter es un operador o el nulo entonces se inserta en la lista
            if ((filtrar(ifs[i+1]) > 0) || (ifs[i+1] == '\0'))
            {
                f = 0;
                //si es el primer elemento
                if (list_size(infix) == 0)
                {
                    if(list_ins_next(infix, NULL, data) != 0) return -1;
                    continue;
                }

                node = list_tail(infix);

                if(list_ins_next(infix, node, data) != 0) return -1;
            }else// si no, es otro digito. En tal caso concatenar
            {
                if((data = (char *)realloc(data, sizeof(char) * strlen(data))) == NULL) return -1;
                
                temp[0] = ifs[i+1];

                strcat(data, temp);
                continue;
            }

        }else//si no lo es es un operador o parentesis
        {
            if((data = (char *)malloc(sizeof(char) * 2)) == NULL) return -1;

            *data = ifs[i];
            data[1] = '\0';
            node = list_tail(infix);

            if(list_ins_next(infix, node, data) != 0) return -1;
        }
    }

}

int infixToPosfix(List *infix, List *posfix)
{
    int i, iflen = list_size(infix);

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

        if(filtrar(*data) == 0)
        {
            if(list_ins_next(posfix, NULL, data) != 0) return -1;
        }else
        {
            if((stack_push(&stack, data)) != 0) return -1;
        }
        
        nodeif = list_next(nodeif); 

    }
    
    stack_destroy(&stack);

}

int main(int argc, char *argv[])
{
   
    List infix, posfix;

    list_init(&infix, free);
    list_init(&posfix, free);



    insert(&infix, argv[1]);
    fprintf(stdout, "Lista en infijia\n");
    print_list(&infix);

    //infixToPosfix(&infix, &posfix);

    //fprintf(stdin, "\nLista en posfija\n");

    //print_list(&posfix);

    
    list_destroy(&infix);
    list_destroy(&posfix);

    return 0;
}
