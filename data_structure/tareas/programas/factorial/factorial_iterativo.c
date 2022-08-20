#include <stdio.h>


unsigned long long Factorial(int n, int a)
{
    if(n == 0 || n == 1)
    {
        return a;
    }

    return Factorial((n-1), a * n);

}

int main(void)
{
    int n;
    int a = 1;


    scanf("%d", &n);

    printf("%llu", Factorial(n, a));
    
    return 0;
}
