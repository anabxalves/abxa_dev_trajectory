#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 50

typedef struct user
{
    struct user *next;
    char name[Max];
    int wordCount;
    struct user *before;
} User;

void myAdd(User **list, char name[Max]);
int myCount(char name[Max]);
int isIn(User *list, char name[Max]);
void myWinner(User *list);
void myPrint(User *list);
void bubbleSort(int n, char arr[n][Max]);
void myFree(User **list);

int main()
{
    User *friend = NULL;
    User *notFriend = NULL;
    char name[Max], choice[5];

    do
    {
        scanf("%s", name);
        if (strcmp(name, "FIM") == 0) break;

        scanf("%s", choice);

        if(strcmp(choice, "YES") == 0)
        {
            myAdd(&friend, name);
        }
        else if(strcmp(choice, "NO") == 0)
        {
            myAdd(&notFriend, name);
        }

    } while (strcmp(name, "FIM") != 0);

    myPrint(friend);
    myPrint(notFriend);
    myWinner(friend);
    
    myFree(&friend);
    myFree(&notFriend);
}

void myAdd(User **list, char name[Max]) // adds to end
{
    User *new = (User *) malloc(sizeof(User));

    if (new != NULL)
    {
        strcpy(new->name, name);
        new->wordCount = myCount(name);
        new->next = NULL;

        if((*list) == NULL)
        {
            (*list) = new;
            (*list)->before = NULL;
        }
        else
        {
            User *temp = (*list);

            if(isIn(temp, name) == 1)
            {
                while (temp->next != NULL) temp = temp->next;
                
                new->before = temp;
                temp->next = new;
            }
        }
    }
}

int myCount(char name[Max])
{
    int count = 0;

    for(int i = 0; name[i] != '\0'; i++) count++;

    return count;
}

int isIn(User *list, char name[Max])
{
    while (list != NULL)
    {
        if (strcmp(list->name, name) == 0) return 0;
        list = list->next;
    }

    return 1;
}

void myWinner(User *list)
{
    char name[Max];
    int maior = 0;

    while(list != NULL)
    {
        if(list->wordCount > maior)
        {
            strcpy(name, list->name);
            maior = list->wordCount;
        }

        list = list->next;
    }

    printf("\nAmigo do Habay:\n%s\n", name);
}

void myPrint(User *list)
{
    User *aux = list;
    int count = 0;

    while(aux != NULL)
    {
        count++;
        aux = aux->next;
    }
    
    char order[count][Max];
    aux = list;
    for(int i = 0; i < count; i++)
    {
        strcpy(order[i], aux->name);
        aux = aux->next;
    }

    bubbleSort(count, order);

    for(int i = 0; i < count; i++) printf("%s\n", order[i]);
}

void bubbleSort(int n, char arr[n][Max])
{
    for(int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (strcmp(arr[i], arr[i + 1]) > 0)
            {
                char temp[Max];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i + 1]);
                strcpy(arr[i + 1], temp);
            }
        }
    }
}

void myFree(User **list)
{
    if(*list != NULL)
    {
        while((*list)->next != NULL)
        {
            User *temp = *list;
            *list = (*list)->next;
            free(temp);
        }
        free(*list);
    }
}
