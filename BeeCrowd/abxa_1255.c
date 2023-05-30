#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;

    scanf("%d\n", &n);

    for (int i=0; i<n; i++)
    {
        char frase[201], ch;
        int j=0;

        ch = getchar();

        while(ch!='\n')
        {
            frase[j] = ch;
            j++;
            ch = getchar();
        }
        frase[j]='\0';

        int tamanho = strlen(frase);

        /* Transformando Maiúsculos em Minúsculos conforme tabela ascii */

        for (int i=0; i<tamanho; i++)
        {
            if ((frase[i]>=65 && frase[i]<=90))
            {
                frase[i] += 32;
            }  
        }

        int cont[26];   /* contador de cada letra */

        for (int i=0; i<26; i++)
        {
            cont[i] = 0;    /* garantindo que inicialize com valor 0*/
        }

        for (int i=0; i<tamanho; i++)
        {
            if ((frase[i]>=97 && frase[i]<=122))
            {
                cont[frase[i]-97]++;    /* a=0, b=1, c=2, ..., z=25 */
            }
        }

        int comp=0;

        for (int i=0; i<26; i++)
        {
            if (cont[i]>=comp)
            {
                comp = cont[i];
            }
        }

        for (int i=0; i<26; i++)
        {
            if (cont[i] == comp)
            {
                putchar(i+97);
            }
        }
        putchar('\n');
    }
    return 0;
}