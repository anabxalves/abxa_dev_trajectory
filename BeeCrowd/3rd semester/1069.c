#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

typedef struct stack
{
    struct stack *next;
} Stack;

void push(Stack **diamonds);
int pop(Stack **diamonds);
void myFree(Stack **list);

int main()
{
    int qty;
    scanf("%d", &qty);

    for(int i=0; i<qty; i++)
    {
        char frase[max];
        Stack *diamonds = NULL;

        scanf("%s[^\n]", frase);

        int cont = 0;

        for(int i=0; frase[i] != '\0'; i++)
        {
            if(frase[i] == '<') push(&diamonds);
            else if(frase[i] == '>')
            {
                if(pop(&diamonds) == 0) cont++;
            }
        }
        printf("%d\n", cont);

        myFree(&diamonds);
    }

    return 0;
}

void push(Stack **diamonds)
{
    Stack *new = (Stack *) malloc(sizeof(Stack));

    if(*diamonds == NULL) new->next = NULL;
    else new->next = (*diamonds);

    (*diamonds) = new;

}

int pop(Stack **diamonds)
{
    if((*diamonds) == NULL) return 1;
    else
    {
        Stack *temp = (*diamonds);

        (*diamonds) = (*diamonds)->next;
        free(temp);
    }
    return 0;
}

void myFree(Stack **list)
{
    if(*list != NULL)
    {
        while((*list)->next != NULL)
        {
            Stack *temp = *list;
            *list = (*list)->next;
            free(temp);
        }
        free(*list);
    }
}