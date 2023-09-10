// Date: 9.3.2023

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maior(int x, int y);

int main()
{
    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    int result = maior(x,y);
    result = maior(result, z);

    printf("%d eh o maior\n", result);

    return 0;
}

int maior(int x, int y)
{
    int result = (x+y+abs(x-y))/2;
    return result;
}