#include <string.h>
#include <stdio.h>

int main()
{
    char frase[1000], frase2[1000], ch;

    int n;

    scanf("%d\n",&n);
    /*getchar();*/

    for(int k=0; k<n; k++)
    {
        int i=0;
        ch = getchar();

        while(ch!='\n')
        {
            frase[i] = ch;
            i++;
            ch = getchar();
        }
        frase[i]='\0';

        int tamanho = strlen(frase);

        for(int i=0;i<tamanho;i++)
        {
            if((frase[i]>='A' && frase[i]<='Z') || (frase[i]>='a'&& frase[i]<='z'))
            {
                frase[i] = frase[i] + 3;
            }
        }

        int k=0;

        for(int j=tamanho-1;j>=0;j--)
        {
            frase2[k] = frase[j];
            k++;
        }
        frase2[k] = '\0';

        for(int i=tamanho/2;i<tamanho;i++)
        {
            frase2[i] =  frase2[i] - 1;
        }
        
        printf("%s\n",frase2);

    }
    
    return 0;
}