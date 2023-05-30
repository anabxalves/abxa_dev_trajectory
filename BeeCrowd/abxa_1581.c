#include <stdio.h>
#include <string.h>

int main()
{
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        int k, cont = 1;
        // "cont = 1" porque 1 é true, utilizei como um "boolean" 
        char lingua[20], comp[20];

        scanf("%d", &k);
        scanf("%s", comp);  // fixando a 1ª entrada como a comparação
        
        for(int j=1; j<k; j++)  // inicando o for em "j = 1" pq já teve a 1ª leitura dos idiomas (em "comp", linha 17)
        {
            scanf("%s", lingua);    

            if(strcmp(comp, lingua))    // aqui, se for igual, vai dar falso, ou seja "0" e não entrará na condição
            {   // portanto, só entrará se a comparação der um valor diferente de 0
                cont=0;     // tornando a proposição falsa
            }
        }

        if(cont) printf("%s\n", comp);  // se a proposição for verdadeira (=1), quer dizer que todos os idiomas são iguais
        else printf("ingles\n");
    }

    return 0;
}