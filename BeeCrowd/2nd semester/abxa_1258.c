#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct referencia
{
    char nome[51];
    char cor[25];
    char tamanho;
};

void swap(struct referencia *camisas, int n);
int mycomp(struct referencia camisa1, struct referencia camisa2);

int main()
{
    int n;
    char input_nome[51], cor[25], tamanho;

    scanf("%d", &n);
    do
    {
        struct referencia camisas[n];

        for(int i=0; i<n; i++)
        {
            scanf(" %[^\n]", input_nome);
            fflush(stdin);
            strcpy(camisas[i].nome, input_nome);

            scanf("%s %c", cor, &tamanho);
            strcpy(camisas[i].cor, cor);
            camisas[i].tamanho = tamanho;
        }

        swap(camisas, n);

        for(int i=0; i<n; i++)
        {
            printf("%s %c %s\n", camisas[i].cor, camisas[i].tamanho, camisas[i].nome);
        }

        scanf("%d", &n);
        if(n==0) break;
        
        printf("\n");
    } while(n != 0);
    
    return 0;
}

void swap(struct referencia *camisas, int n)
{
    struct referencia temp;
    int comp;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            comp = mycomp(camisas[i], camisas[j]);
            if(comp>0)
            {
                temp = camisas[i];
                camisas[i] = camisas[j];
                camisas[j] = temp;
            }
        }
    }
}

int mycomp(struct referencia camisa1, struct referencia camisa2)
{
    int nome, cor, tamanho;

    nome = strcmp(camisa1.nome, camisa2.nome);
    cor = strcmp(camisa1.cor, camisa2.cor);
    tamanho = camisa2.tamanho - camisa1.tamanho;

    if(cor!=0) return cor;
    else if(tamanho!=0) return tamanho;
    else return nome;
}