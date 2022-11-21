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
    int i, f, fp, iflen = list_size(infix);

    char *data, *datapf, *dataAux, dataAux2[1];

    Stack stack;
    ListNode *node;

    stack_init(&stack, free);

    node = list_head(infix);

    //itera sobre la lista infija
    for (i = 0; i < iflen; i++)
    {
        data = list_data(node);

        if((datapf = (char *)malloc(sizeof(char) * strlen(data))) == NULL) return -1;

        strcpy(datapf, data);

        f = filtrar(datapf[0]);

        //si es un parentesis( se introduce en el stack
        if(f == 4)
        {
            printf("parentesis en(: %d\n", i);
            if((stack_push(&stack, datapf)) != 0) return -1;
            node = list_next(node);
            //reset a la precedencia
            fp = 0;
            //printf("fp value = %d", fp);
            continue;
        }

        //cuando hay un parentesis) cerrando
        if(f == 5)
        {
            printf("parentesis en): %d\n", i);
            data = stack_peek(&stack);
            printf("popping\n");
            printf("data = %s\n", data);

            //se hace un pop al stack hasta cerrar los parentesis
            do
            {
                if(stack_pop(&stack, (void **)&data) == 0)
                {
                    //aqui el parentesis cierra y termina el loop
                    if(filtrar(data[0]) == 4)
                    {
                        free(data);
                        break;
                    }
                    if((datapf = (char *)malloc(sizeof(char) * strlen(data))) == NULL) return -1;

                    strcpy(datapf, data);

                    if(filtrar(datapf[0]) != 4)
                        if(list_ins_next(posfix, list_tail(posfix), datapf) != 0) return -1;

                    free(data);
                }
                else
                {
                    return -1;
                }
            }while (1);
            //y se continua con la iteracion
            node = list_next(node);
            //printf("fp value = %d\n", fp);
            //reset a la precedencia
            dataAux = stack_peek(&stack);
            fp = filtrar(dataAux[0]);
            continue;
        }

        //si es un numero se va a la lista
        if(f == 0)
        {
            printf("digito en: %d\n", i);
            if(list_ins_next(posfix, list_tail(posfix), datapf) != 0) return -1;
        }
        //en caso contrario es un operador y va al stack
        else
        {
            printf("operador en: %d\n", i);
            //printf("fp value = %d\n", fp);

            //si ya hay elementos en el stack se comprueba que la precedencia
            if(stack_size(&stack) > 0 && f <= fp)
            {   
                if(stack_pop(&stack, (void **)&data) == 0)
                {
                    printf("pop en: %d\n", i);
                    if((dataAux = (char *)malloc(sizeof(char) * strlen(data))) == NULL) return -1;

                    strcpy(dataAux, data);

                    if(list_ins_next(posfix, list_tail(posfix), dataAux) != 0) return -1;

                    free(data);

                    if(stack_size(&stack) != 0)
                    {
                        if(stack_pop(&stack, (void **)&data) == 0)
                        {
                            fp = filtrar(data[0]);
                            if (f <= fp)
                            {
                                printf("pop en: %d\n", i);
                                if((dataAux = (char *)malloc(sizeof(char) * strlen(data))) == NULL) return -1;
                                strcpy(dataAux, data);

                                if(list_ins_next(posfix, list_tail(posfix), dataAux) != 0) return -1;

                                free(data);
                            }
                            else
                            {
                                if((stack_push(&stack, data)) != 0) return -1;
                            }
                        }
                        else
                        {
                            return -1;
                        }
                    }
                }
                else
                {
                    return -1;
                }
            }
            //se establece la precedencia para la siguiente iteracion
            fp = f;
            if((stack_push(&stack, datapf)) != 0) return -1;
            data = stack_peek(&stack);
            printf("pushed: %s\n", data);
        }

        node = list_next(node);
    }

    //si la iteracion sobre la lista infija termino, pero el stack no esta vacio se hace un pop hasta que lo este
   while (stack_size(&stack) > 0)
   {
        if(stack_pop(&stack, (void **)&data) == 0)
        {
            if((datapf = (char *)malloc(sizeof(char) * strlen(data))) == NULL) return -1;

            strcpy(datapf, data);

            if(list_ins_next(posfix, list_tail(posfix), datapf) != 0) return -1;

            free(data);
        }
        else
        {
            return -1;
        }
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

    infixToPosfix(&infix, &posfix);

    fprintf(stdin, "\nLista en posfija\n");

    print_list(&posfix);

    
    list_destroy(&infix);
    list_destroy(&posfix);

    return 0;
}
