#include <stdio.h>


int main()
{
    int nC, u, i;
    int p[10];
    
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

    return 0;
}
