#include <stdio.h>

unsigned long long Factorial(int n)
{
    unsigned long long factorial = n;

    if(n == 0)
    {
        return 1;
    }

    while (n != 1)
    {
        factorial = factorial * (n-1);
        n--;
    }
    
    return factorial;
}

int main(void)
{
    int n;

    scanf("%d", &n);

    printf("%llu", Factorial(n));
    
    return 0;
}
