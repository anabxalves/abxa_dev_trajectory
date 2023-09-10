// Date: 11.5.2023

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

struct stack
{
    int value;
    struct stack* next;
};

void push(struct stack **head);
void pop(struct stack **head);
int isEmpty(struct stack *head);

int main()
{
    char input[MAX];

    while(scanf("%s", input) != EOF)
    {    
        struct stack *chaves = NULL;

        for(int i=0; i< strlen(input); i++)
        {
            if(input[i]== '(')
            {
                push(&chaves);
            }
            else if(input[i] == ')')
            {
                if(isEmpty(chaves))
                {
                    push(&chaves);
                    break;
                }
                pop(&chaves);
            }
            else continue;
        }

        if(isEmpty(chaves)) printf("%s\n", "correct");
        else printf("%s\n", "incorrect");

        free(chaves);
    }

    return 0;
}

void push(struct stack **head)
{
    struct stack *novo = (struct stack *)malloc(sizeof(struct stack));
    novo->value = 0;
    novo->next = *head;
    *head = novo;
}

void pop(struct stack **head)
{
    struct stack *temp;
    
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

int isEmpty(struct stack *head)
{
    return head == NULL;
}