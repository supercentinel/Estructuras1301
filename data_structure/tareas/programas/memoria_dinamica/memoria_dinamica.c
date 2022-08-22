#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *p;

    p = (int*)malloc(sizeof(int));

    *p = 5040;

    printf("%d %d\n", *p, p);

    p = NULL;
    free(p); 
    
    return 0;
}
