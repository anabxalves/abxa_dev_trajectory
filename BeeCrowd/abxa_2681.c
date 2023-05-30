// Date: 20.5.2023

#include <stdio.h>
#include <stdlib.h>

int hanoi(int n);
void clock(int n);

int main(){
    int n;
    scanf("%d", &n);

    int qtd = hanoi(n);
    clock(qtd);

    return 0;
}

int hanoi(int n){
    if(n == 1) return 1;
    else return 2*hanoi(n-1)+1;
}

void clock(int n){
    int h=0, m=0, s=0, resto=0;

    h = n / 3600;
    resto = n % 3600;
    m = resto / 60;
    s = resto % 60;

    printf("%.02d:%.02d:%.02d\n", h, m, s);
}