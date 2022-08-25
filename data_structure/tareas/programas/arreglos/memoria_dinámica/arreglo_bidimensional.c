#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int f, c,i = 0, j = 0, noCn[14];
    char noC[21];
    
    printf("Numero de cuenta: ");
    fflush(stdin);
    fgets(noC, 20, stdin);
    noC[strcspn(noC, "\n")] = '\0';

    while(noC[i] != '\0')
    {
        if(noC[i] == '0')
        {
            j++;
            i++;
        }else
        {
            noCn[i-j] = noC[i] - '0';
            i++;
        }
    }

    f = i - j;
 
    int **arr = calloc(f, sizeof(int *));
    for (i = 0; i < f; i++)
    {
        c = noCn[i];
        arr[i] = calloc(c, sizeof(int));
    }

    for (i = 0; i < f; i++)
    {
        c = noCn[i];
        for (j = 0; j < c; j++)
        {
            arr[i][j] = c;
            printf("|%d|", arr[i][j]);
        }
        printf("\n");

        arr[i] = NULL;
        free(arr[i]); 
    }

    arr = NULL;
    free(arr);

    return 0;
}
