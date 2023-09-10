#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tea;
    scanf("%d", &tea);

    int answers[5], cont = 0;
    
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &answers[i]);

        if(answers[i] == tea) cont++;
    }

    printf("%d\n", cont);

    return 0;
}