#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void transform1to9(int x, int y, int** p);
void analyseSurround(int x, int y, int** p);
void myPrint(int x, int y, int** p);
void myFree(int x, int** p);

int main()
{
    int n, m;   // n = linhas     m = colunas
    int** matriz;
    
    while(scanf("%d %d", &n, &m)!=EOF)
    {    
        matriz = (int **)calloc(n, sizeof(int*));
        for(int i=0; i<n; i++)
        {
            matriz[i] = (int*)calloc(m, sizeof(int));
            for(int j=0; j<m; j++)
            {
                int temp;
                scanf("%d", &temp);
                matriz[i][j] = temp;
            }
        }

        transform1to9(n, m, matriz);
        analyseSurround(n, m, matriz);
        myPrint(n, m, matriz);
        myFree(n, matriz);
    }

    return 0;
}

void transform1to9(int x, int y, int** p)
{
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(p[i][j] == 1)
            {
                p[i][j] = 9;
            }
        }
    }
}

void analyseSurround(int x, int y, int** p)
{
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(p[i][j] == 9) continue;

            if (i == 0)
            {
                if(i != (x-1))
                {
                    if(p[i+1][j] == 9) p[i][j]++;
                }

            }
            else if (i == (x-1))
            {
                if(p[i-1][j] == 9) p[i][j]++;
            }
            else
            {
                if(p[i+1][j] == 9) p[i][j]++;
                if(p[i-1][j] == 9) p[i][j]++;
            }

            if(j == 0)
            {
                if(p[i][j+1] == 9) p[i][j]++;

            }
            else if (j == (y-1))
            {
                if(p[i][j-1] == 9) p[i][j]++;

            }
            else
            {
                if(p[i][j+1] == 9) p[i][j]++;
                if(p[i][j-1] == 9) p[i][j]++;
            }
        }
    }
}

void myPrint(int x, int y, int** p)
{
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            printf("%d", p[i][j]);
        }
        printf("\n");
    }
}

void myFree(int x, int** p)
{
    for(int i=0; i<x; i++)
    {
        free(p[i]);
    }

    free(p);
}