#include <stdio.h>
#include <stdlib.h>


int main()
{
    int nC, u, i;
    int *p = calloc(10, sizeof(int));

    if(p == NULL)
    {
        return -1;
    }
    
    for(i = 0; i < 10; i++)
    {
        p[i] = (i+1)*2;
    }
        
    for(i = 9; i >= 0; i--)
    {    
        printf("%d ", p[i]);
    }

    printf("\nNumero de cuenta: ");
    scanf("%d", &nC);

    u = nC % 10;

    p[u] = -1;

    for (i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }

    p = NULL;
    free(p);

    return 0;
}
