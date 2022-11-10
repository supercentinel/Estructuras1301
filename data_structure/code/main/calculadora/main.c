#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 100

#include "list.h"
#include "stack.h"

char * Lectura()
{
    char str[MAX_STR];
    int i;

    fgets(str, MAX_STR-1, stdin);
    str[strcspn(str, "\n")] = 0;
    
    while (str[i] != '\0')
    {



    }
    
    return str;
}

char filtrar(char c)
{

    switch (c)
    {
    case 37:
        return c;
    break;
    case 40:
        return c;
    break;
    case 41:
        return c;
    break;
    case 42:
        return c;
    break;
    case 43:
        return c;
    break;
    case 45:
        return c;
    break;
    case 47:
        return c;
    break;
    case 48:
        return c;
    break;
    case 49:
        return c;
    break;
    case 50:
        return c;
    break;
    case 51:
        return c;
    break;
    case 52:
        return c;
    break;
    case 53:
        return c;
    break;
    case 54:
        return c;
    break;
    case 55:
        return c;
    break;
    case 56:
        return c;
    break;
    case 57:
        return c;
    break;
    case 94:
        return c;
    break;
    
    default:
    break;
    }

}

int main(int argc, char const *argv[])
{
    if(argv[1] == 'h')
    {

    }

    

    return 0;
}
