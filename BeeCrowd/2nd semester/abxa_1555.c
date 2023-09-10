// Date: 9.3.2023

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rafael(int x, int y);
int beto(int x, int y);
int carlos(int x, int y);

int main()
{   
    int n, i=0;

    scanf("%d", &n);

    while(i<n)
    {
        int x, y;

        scanf("%d %d", &x, &y);

        int funR, funB, funC;

        funR = rafael(x,y);
        funB = beto(x, y);
        funC = carlos(x, y);

        if(funR > funB && funR > funC) printf("Rafael ganhou\n");
        else if(funB > funR && funB > funC) printf("Beto ganhou\n");
        else printf("Carlos ganhou\n");

        i++;
    }

    return 0;
}

int rafael(int x, int y)
{
    int fun = ((3*x)*(3*x)) + (y*y);
    return fun;
}

int beto(int x, int y)
{
    int fun = (2*(x*x)) + ((5*y)*(5*y));
    return fun;
}

int carlos(int x, int y)
{
    int fun = (-100*x) + (y*y*y);
    return fun;
}