#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000

struct amigo
{
    char nome[51];
    struct amigo *next;
};

void myList(char string[MAX], struct amigo **head);
void addList(struct amigo **head, char name[MAX]);
int isIn(struct amigo **head, char* string);
void combineLists(struct amigo **head, struct amigo **new, char * string);
void printList(struct amigo *head);

int main()
{
    char lista_atual[MAX], novos_amigos[MAX], separate[MAX];
    struct amigo *head = NULL, *new = NULL;
    
    scanf(" %[^\n]", lista_atual);
    myList(lista_atual, &head);

    scanf(" %[^\n]", novos_amigos);
    myList(novos_amigos, &new);

    scanf("%s", separate);

    combineLists(&head, &new, separate);
    printList(head);

    return 0;
}

void myList(char string[MAX], struct amigo **head)
{
    char* aux_str;
    int len = 0;

    aux_str = strtok(string, " ");
    while(aux_str != NULL)
    {
        addList(head, aux_str);
        len++;
        aux_str = strtok(NULL, " ");
    }
}

void addList(struct amigo **head, char name[MAX])
{
    if(*head == NULL)
    {
        *head = (struct amigo *)malloc(sizeof(struct amigo));
        strcpy((*head)->nome, name);
        (*head)->next = NULL;

    }
    else
    {
        struct amigo *n = *head;
        
        while(n->next != NULL)
        {
            n = n->next;
        }

        n->next = (struct amigo *)malloc(sizeof(struct amigo));
        strcpy(n->next->nome, name);
        n->next->next = NULL;
  }
}

int isIn(struct amigo **head, char* string)
{
    struct amigo *n = *head;

    while(n != NULL && strcmp(n->nome, string) != 0)
    {
        n = n->next;
    }

    if(n == NULL) return 1;
    else return 0;
}

void combineLists(struct amigo **head, struct amigo **new, char * string)
{
    struct amigo *n = *head;
    struct amigo *p = *new;
    struct amigo *temp;
    int cont = 1;

    if(isIn(&n, string) == 1)
    {
        while(n->next != NULL) n = n->next;
    }
    else
    {
        if(strcmp(n->nome, string) !=0)
        {
            while((strcmp(n->next->nome, string) != 0) && (n->next != NULL)) n=n->next;
        }
        else
        {
            cont=0;
        }
    }

    if(cont == 1)
    {
        temp = n->next;
        n->next = p;
    }
    else
    {
        temp = *head;
        *head = p;
    }

    while(p->next != NULL) p = p->next;

    p->next = temp;
}

void printList(struct amigo *head)
{
    struct amigo *n = head;

    while(n != NULL)
    {
        if(n->next != NULL)
        {
            printf("%s ", n->nome);
            n = n->next;
        }
        else
        {
            printf("%s", n->nome);
            n = n->next;
        }
    }
    printf("\n");
}