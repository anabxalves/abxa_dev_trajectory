// Date: 20.5.2023

#include <stdio.h>
#include <stdlib.h>

int fib(int n);
int d = -1;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        int fibNum;
        scanf("%d", &fibNum);

        int result = fib(fibNum);

        printf("fib(%d) = %d calls = %d\n", fibNum, d, result);

        d = -1;
    }

    return 0;
}

int fib(int n)
{
    d++;

    if (n == 0) return 0;                             
    else if (n == 1) return 1;            
    else return fib(n-1) + fib(n-2);  
}