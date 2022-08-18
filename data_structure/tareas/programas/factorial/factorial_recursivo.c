#include <stdio.h>

unsigned long long Factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * Factorial(n -1);
}

int main(void)
{
    int n;

    scanf("%d", &n);

    printf("%llu", Factorial(n));
    
    return 0;
}
