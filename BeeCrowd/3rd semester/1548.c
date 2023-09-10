#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    struct student *before;
    int grade;
    struct student *next;
} Student;

void myAdd(Student **students, int nota);
void myCopy(Student *students, int lineSize, int vetorStudents[lineSize]);
int compareValues(const void *a, const void *b);
int myComp(Student *students, int lineSize, int vetorStudents[lineSize]);
void myFree(Student **list);

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        int lineSize;
        scanf("%d", &lineSize);

        Student *students = NULL;

        for(int j = 0; j < lineSize; j++)
        {
            int grade;
            scanf("%d", &grade);

            myAdd(&students, grade);
        }

        int vetorStudents[lineSize];

        myCopy(students, lineSize, vetorStudents);
        qsort(vetorStudents, lineSize, sizeof(int), compareValues);

        printf("%d\n", myComp(students, lineSize, vetorStudents));

        myFree(&students);
    }

    return 0;
}

void myAdd(Student **students, int nota)
{
    Student *new = (Student *) malloc(sizeof(Student));
    new->grade = nota;
    new->next = NULL;

    if((*students) == NULL)
    {
        new->before = NULL;
        (*students) = new;
    }
    else
    {
        Student *temp = (*students);

        while(temp->next != NULL) temp = temp->next;

        new->before = temp;
        temp->next = new;
    }
}

void myCopy(Student *students, int lineSize, int vetorStudents[lineSize])
{
    if(students != NULL)
    {
        for(int i = 0; i < lineSize; i++)
        {
            vetorStudents[i] = students->grade;

            students = students->next;
        }
    }
}

int compareValues(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int myComp(Student *students, int lineSize, int vetorStudents[lineSize])
{
    int cont = 0;

    for(int i = 0; i < lineSize; i++)
    {
        if(students->grade == vetorStudents[i]) cont++;

        students = students->next;
    }
    return cont;
}

void myFree(Student **list)
{
    if((*list) != NULL)
    {
        while((*list) != NULL)
        {
            Student *temp = *list;
            *list = (*list)->next;
            free(temp);
        }
    }
}