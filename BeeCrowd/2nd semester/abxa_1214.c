// Date: 28.3.2023

#include <stdio.h>
#include <stdlib.h>

float media(int n, int vetor[n]);

int main()
{
    int c, n, i, j=0;

    scanf("%d", &c);

    while(j<c)
    {
        scanf("%d", &n);

        int vetor[n];
        float soma=0, cont=0;

        // for(i=0; i<n; i++){
        //     scanf("%d", &vetor[i]);
        //     soma+=vetor[i];
        // }

        soma = media(n, vetor);

        for(i=0; i<n; i++)
        {
            if(vetor[i]>soma) cont++;
        }

        printf("%.3f%c\n", (cont/n)*100, '%');
        /* poderia ser: printf("%.3f%%\n", (cont/n)*100);*/
        j++;
    }

    return 0;
}

float media(int n, int vetor[n])
{
    float soma;

    for(int i=0; i<n; i++)
    {
        scanf("%d", &vetor[i]);
        soma+=vetor[i];
    }

    soma = soma/n;

    return soma;
}