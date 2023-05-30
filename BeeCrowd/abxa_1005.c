// Date: 28.02.2023

#include <stdio.h>

int main (){
    float a, b;
    double media;

    scanf("%f", &a);
    scanf("%f", &b);

    media = ((a*3.5) + (b*7.5))/ 11;

    printf("MEDIA = %.5f\n", media);

    return 0;
}