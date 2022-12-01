#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char const *argv[])
{
    int elmts = 10, i;
    Stack stack;
    int *data;

    printf("stack\n");

    stack_init(&stack, free);

    printf("Stacking %d elements\n", elmts);
    
    for (i = 0; i < elmts; i++)
    {
        if((data = (int *)malloc(sizeof(int))) == NULL) return -1;

        *data = i;

        stack_push(&stack, data);

        printf("Pushed: %d, stack size %d\n", i, stack_size(&stack));
    }

    printf("Peeking at stack top\n");

    data = stack_peek(&stack);

    printf("Stack top: %d\n", *data);

    elmts = 4;

    printf("Popping %d elemnts\n", elmts);

    for ( i = 0; i < elmts; i++)
    {
        if((data = (int *)malloc(sizeof(int))) == NULL) return -1;
        stack_pop(&stack, (void **)data);

        printf("popping %d\n", *data);
    }
    
    
        

    stack_destroy(&stack);

    return 0;
}
