#include <stdio.h>
#include <string.h>

int main()
{
    char frase[51], ch;

    while((ch = getchar()) != EOF)
    {
        int i=0;

        while(ch!='\n')
        {
            frase[i]= ch;
            i++;
            ch = getchar();
        }
        frase[i]= '\0';

        int tamanho = strlen(frase), contI=0, contB=0;

        for(int j=0; j<tamanho; j++)
        {
            switch(frase[j])
            {
                case '_':
                    if(contI==0)
                    {
                        printf("<i>");
                        contI++;
                    }else
                    {
                        printf("</i>");
                        contI=0;
                    }
                break;
                case '*':
                    if(contB==0)
                    {
                        printf("<b>");
                        contB++;
                    }else
                    {
                        printf("</b>");
                        contB=0;
                    }
                break;
                default:
                    putchar(frase[j]);
                break;
            }
        }
        putchar('\n');
    }
    return 0;
}