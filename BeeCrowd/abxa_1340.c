// Date: 5.6.2023

#include <stdio.h>
#include <stdlib.h>

struct input
{
    int value;
    struct input* next;
};

void pushStack(struct input **head, int a);
void insertQueue(struct input **head, int a);
void insertPriorQ(struct input **head, int a);
int popAll(struct input **head, int out);

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        struct input *stack = NULL;
        struct input *queue = NULL;
        struct input *priorQ = NULL;

        int inStack = 1;
        int inQueue = 1;
        int inPriorQ = 1;

        for(int i=0; i<n; i++)
        {
            int command, value;
            scanf("%d %d", &command, &value);

            if (command == 1)
            {
                pushStack(&stack, value);
                insertQueue(&queue, value);
                insertPriorQ(&priorQ, value);
            }
            else
            {
                int bufStack = popAll(&stack, value);
                if(bufStack == 0) inStack = 0;

                int bufQueue = popAll(&queue, value);
                if(bufQueue == 0) inQueue = 0;

                int bufPriorQ = popAll(&priorQ, value);
                if(bufPriorQ == 0) inPriorQ = 0;
            }
            getchar();
        }

        int anaylse = inStack + inQueue + inPriorQ;

        if(anaylse <= 0) printf("impossible\n");
        else if(anaylse > 1) printf("not sure\n");
        else
        {
            if(inStack) printf("stack\n");
            else if(inQueue) printf("queue\n");
            else if(inPriorQ) printf("priority queue\n");
        }

        struct input *temp;

        while(stack != NULL)
        {
            temp = stack;
            stack = stack->next;
            free(temp);
        }

        while (queue != NULL)
        {
            temp = queue;
            queue = queue->next;
            free(temp);
        }

        while (priorQ != NULL)
        {
            temp = priorQ;
            priorQ = priorQ->next;
            free(temp);
        }
    }
    return 0;
}

void pushStack(struct input **head, int a)
{
    struct input *new = (struct input *)malloc(sizeof(struct input));

    new->value = a;
    new->next = *head;
    *head = new; 
}

void insertQueue(struct input **head, int a)
{
    if(*head == NULL)
    { 
        *head = (struct input *)malloc(sizeof(struct input));
        (*head)->value = a;
        (*head)->next = NULL;
    }
    else
    {
        struct input *n = *head;
        
        while(n->next != NULL) n = n->next;

        n->next = (struct input *)malloc(sizeof(struct input));
        n->next->value = a;
        n->next->next = NULL;
    }
}

void insertPriorQ(struct input **head, int a)
{

    if(*head == NULL)
    { 
        *head = (struct input *)malloc(sizeof(struct input));
        (*head)->value = a;
        (*head)->next = NULL;
    }
    else
    {
        struct input *n = *head;
        if(n->value < a) pushStack(&(*head), a); 
        else
        {
            while(n->next != NULL && n->next->value > a) n = n->next;

            struct input *temp = n->next;

            n->next = (struct input *)malloc(sizeof(struct input));
            n->next->value = a;
            n->next->next = temp;
        }
    }
}

int popAll(struct input **head, int out)
{
    if(*head == NULL) return 0;

	struct input *temp = *head;
	int var = temp->value;

    *head = (*head)->next;
    
	free(temp);
    if (var == out) return 1;
    else return 0;
}
