#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct cir
{
    int r;
    int x;
    int y;
};

struct cir makecir(struct cir circulo, int r, int x, int y)
{
    circulo.r = r;
    circulo.x = x;
    circulo.y = y;

    return circulo;
}

float dist(struct cir circulo1, struct cir circulo2)
{
    float distancia = sqrt(pow((circulo2.x-circulo1.x), 2) + pow((circulo2.y)-(circulo1.y), 2));

    return distancia;
}

int main()
{
    int r1, x1, y1, r2, x2, y2;

    while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF)
    {
        struct cir circulo1 = makecir(circulo1, r1, x1, y1);
        struct cir circulo2 = makecir(circulo2, r2, x2, y2);

        float distancia = dist(circulo1, circulo2);

        if(circulo1.r >= (distancia+circulo2.r))
        {
            printf("RICO\n");
        }
        else printf("MORTO\n");
    }
    return 0;
}