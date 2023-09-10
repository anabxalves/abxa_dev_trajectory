// Date: 7.3.2023

#include <stdio.h>
#include <math.h>

int main()
{
    int g, a, m, c;

    /*
    1º input: os 4 valores Inteiros e Positivos:
    G = nº de linhas da 1ª Matriz
    A = nº de colunas da 1ª Matriz / nº de linhas da 2ª Matriz
    M = nº de colunas da 2ª Matriz / nº de linhas da 3ª Matriz
    C = nº de colunas da 3ª Matriz
    */

    scanf("%d %d %d %d", &g, &a, &m, &c);

    int i, j, k;

    /*
    2º input: Uma matriz de tamanho g x a ('g' linhas e 'a' colunas)
    G = Linha
    A = Coluna
    */
    int matriz1[g][a];
    
    for(i=0; i<g; i++)
    {
        for(j=0; j<a; j++) scanf("%d",&matriz1[i][j]);
    }

    /*
    3º input: Uma matriz de tamanho a x m ('a' linhas e 'm' colunas)
    A = Linhas
    M = Colunas
    */
    int matriz2[a][m];

    for(i=0; i<a; i++)
    {
        for(j=0; j<m; j++) scanf("%d",&matriz2[i][j]);
    }

    /*
    4º input: Uma matriz de tamanho m x c ('m' linhas e 'c' colunas)
    M = Linhas
    C = Colunas
    */
    int matriz3[m][c];

    for(i=0; i<m; i++)
    {
        for(j=0; j<c; j++) scanf("%d",&matriz3[i][j]);
    }
    
    /*
    Multiplicação das Matrizes
    "Para que o produto exista, o número de colunas da primeira matriz tem que ser igual ao número de linhas da segunda matriz.
    Além disso, o resultado da multiplicação é uma matriz que possui o mesmo número de linhas da primeira matriz e o mesmo número de colunas da segunda matriz."
    */
   
   int matrizRes1[g][m], matrizRes2[g][c];

    for (i=0; i<g; i++)
    {
        for (j=0; j<m; j++)
        {
            matrizRes1[i][j] = 0;

            for (k=0; k<a; k++)
            {
                matrizRes1[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    for (i=0; i<g; i++)
    {
        for (j=0; j<c; j++)
        {
            matrizRes2[i][j] = 0;

            for (k=0; k<m; k++)
            {
                matrizRes2[i][j] += matrizRes1[i][k] * matriz3[k][j];
            }
        }
    }

    int digitos[c];

    for (j=0; j<c; j++)
    {
        digitos[j]= 0;

        for (i=0; i<g; i++)
        {
            if (log10(matrizRes2[i][j])+1>digitos[j])
            {
                digitos[j] = log10(matrizRes2[i][j])+1;
            }
            else continue;
        }
    }

    for (i=0; i<g; i++)
    {
        for (j=0; j<c; j++)
        {
            if(j==0)
            {
                printf("%*d", digitos[j], matrizRes2[i][j]);
            }
            else
            {
                printf(" %*d", digitos[j], matrizRes2[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}