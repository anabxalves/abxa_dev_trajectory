// Date: 4.3.2023

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p, n;

    scanf("%d %d", &p, &n);

    int vetor[n];

    for (int i=0; i<n; i++) scanf("%d", &vetor[i]);

    int comp;

    for (int i = 1; i<n ; i++)
    {
        comp = vetor[i] - vetor[i-1];

        if(abs(comp) > p)
        {
            printf("GAME OVER\n");
            break;
        }
        else
        {
            if(i!=n-1) continue;
            else printf("YOU WIN\n");
        }
    }
    return 0;
}