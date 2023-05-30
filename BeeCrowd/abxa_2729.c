#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000

int myLen(char string[MAX]);
int noRepeat(char string[MAX], char **elements, int size);
void myOrder(int n, char** elements);
void myPrint(int n, char** elements);
void myFree(int x, char** p);

int main()
{
    int n, len, bool;
    char input[MAX], input_copy[MAX], *aux;
    char **elementos;

    scanf("%d\n" , &n);

    for(int i=0; i < n; i++)
    {
        fgets(input, MAX, stdin);
        strcpy(input_copy, input);

        len = myLen(input_copy);

        elementos = (char**)malloc(len*sizeof(char*));

        for(int i=0; i<len; i++)
        {
            elementos[i] = (char*)malloc(sizeof(input)*sizeof(char));
        }
        
        int count_aux = 0;

        aux = strtok(input, " ");
        while(aux != NULL)
        {
            bool = noRepeat(aux, elementos, len);

            if(bool != 1)
            {
                strcpy(elementos[count_aux], aux);
                count_aux++;
            }
            aux = strtok(NULL, " ");
        }

        myOrder(count_aux, elementos);
        myPrint(count_aux, elementos);
        myFree(count_aux, elementos);
    }

    return 0;
}

int myLen(char string[MAX])
{
    char* aux_str;
    int len = 0;

    aux_str = strtok(string, " ");
    while(aux_str != NULL)
    {
        len++;
        aux_str = strtok(NULL, " ");
    }

    return len;
}

int noRepeat(char string[MAX], char** elements, int size)
{
    int value = 0;

    for(int i=0; i<strlen(string); i++)
    {
        if(string[i] == '\n') string[i] = 0;
    }

    for(int i=0; i<size; i++)
    {
        if(strcmp(string, elements[i]) == 0) value=1;
    }

    return value;
}

void myOrder(int n, char** elements)
{
    char aux[MAX];
    int i=1, j;

    while (i < n)
    {
		j = i - 1;
        strcpy(aux, elements[i]);

		while (j >= 0 && strcmp(elements[j], aux) > 0)
		{
            strcpy(elements[j + 1], elements[j]);
			j--;
		}

        strcpy(elements[j + 1], aux);
		i++;
	}
}

void myPrint(int n, char** elements)
{
    for(int i = 0; i<n; i++)
    {
        if(i+1 == n) printf("%s", elements[i]);
        else printf("%s ", elements[i]);
    }
    printf("\n");
}

void myFree(int x, char** p)
{
    for(int i=0; i<x; i++)
    {
        free(p[i]);
    }
    free(p);
}