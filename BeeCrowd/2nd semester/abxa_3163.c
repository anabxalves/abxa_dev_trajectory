// Date: 11.5.2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 6
#define qty 4

struct order
{
    char id[MAX];
    struct order* next;
};

void insertGate(char idPlane[MAX], struct order ** gate);
void takeOff(int qtd[qty], struct order **n, struct order **e, struct order **s, struct order **w);
int mostPlanes(int qtd[qty]);
int totPlanes(int qtd[qty]);

int main()
{
    char input[MAX];
    int gate = 0, cont[qty]={0,0,0,0};
    struct order *north = NULL, *south = NULL, *east = NULL, *west = NULL;
    
    scanf("%s", input);

    while(strcmp(input, "0") != 0)
    {
        if(input[0] == '-')
        {
            gate = abs(atoi(input));
            // definição do portão
        }
        else
        {
            switch (gate)
            {
                case 1:
                // maior prioridade
                    insertGate(input, &west);
                    cont[0]++;
                    break;
                case 2:
                // 3º prioridade
                    insertGate(input, &south);
                    cont[1]++;
                    break;
                case 3:
                // 2º prioridade
                    insertGate(input, &north);
                    cont[2]++;
                    break;
                case 4:
                // ultima prioridade
                    insertGate(input, &east);
                    cont[3]++;
                    break;
            }
        }

        scanf("%s", input);
    }
    
    takeOff(cont, &north, &east, &south, &west);

    free(north);
    free(east);
    free(south);
    free(west);

    return 0;
}

void insertGate(char idPlane[MAX], struct order ** gate)
{
    if(*gate == NULL)
    {
        *gate = (struct order *)malloc(sizeof(struct order));
        strcpy((*gate)->id, idPlane);
        (*gate)->next = NULL;
    }
    else
    {
        struct order *n = *gate;
        
        while(n->next != NULL) n = n->next;

        n->next = (struct order *)malloc(sizeof(struct order));
        strcpy(n->next->id, idPlane);
        n->next->next = NULL;
    }
}

void takeOff(int qtd[qty], struct order **n, struct order **e, struct order **s, struct order **w)
{
    struct order *pN = *n;
    struct order *pE = *e;
    struct order *pS = *s;
    struct order *pW = *w;

    int takeoffWaves = mostPlanes(qtd);
    int totalPlanes = totPlanes(qtd);
    int contPlanes = 0;

    for(int i = 0; i<takeoffWaves; i++)
    {
        if(pW != NULL)
        {
            contPlanes++;
            if(contPlanes == totalPlanes) printf("%s\n", pW->id);
            else printf("%s ", pW->id);
            pW = pW->next;
        }
        if(pN != NULL)
        {
            contPlanes++;
            if(contPlanes == totalPlanes) printf("%s\n", pN->id);
            else printf("%s ", pN->id);
            pN = pN->next;
        }
        if(pS != NULL)
        {
            contPlanes++;
            if(contPlanes == totalPlanes) printf("%s\n", pS->id);
            else printf("%s ", pS->id);
            pS = pS->next;
        }
        if(pE != NULL)
        {
            contPlanes++;
            if(contPlanes == totalPlanes) printf("%s\n", pE->id);
            else printf("%s ", pE->id);
            pE = pE->next;
        }
    }
}

int mostPlanes(int qtd[qty])
{
    int most = -1;

    for(int i = 0; i<qty; i++)
    {
        if(qtd[i]>most) most = qtd[i];
    }
    return most;
}

int totPlanes(int qtd[qty])
{
    int sum = 0;

    for(int i = 0; i<qty; i++)
    {
        sum += qtd[i];
    }
    return sum;
}