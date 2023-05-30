// Date: 7.3.2023

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1;
    
    while(n!=0)
    {
        scanf("%d", &n);

        if(n==0) break;

        int matriz[n][n], i, j, elemCentral, acumA, acumB;

        if (n%2 == 0) elemCentral = n/2;
        else elemCentral = (n+1)/2;

        acumA = 0;
        acumB = n-1;

        /*
        - A variável "acumA" armazena o valor no qual a varredura deverá ser inicializada.

        - Já a variável "acumB" armazena o valor no qual a varredura deverá se encerrar.
            Ela é setada em (n-1), pois, diferentemente da matemática, na programação o primeiro valor é 0, e não 1.
            Portanto, esse decremento é para garantir que se inicialize em 0, e conte "n" colunas, ao invés de percorrer até a coluna "n".
            ex: array[5] != array[i][5]
                - Enquanto o primeiro exemplo terá 5 colunas (0, 1, 2, 3, 4), o segundo terá 6 (0, 1, 2, 3, 4, 5).
        
        - Ao definir "acumA" como valor inicial de "i" e "j", e ao incrementar 1 ao final do ciclo, garantimos que não percorra linhas mais de uma vez.
        - Além disso, ao definir a parada como "acumB", decrementando 1 ao final de cada ciclo, garantimos que colunas não sejam percorridas novamente.

        - Desta forma, garantimos que os extremos sejam excluídos das próximas varreduras, a análise convergindo, a cada ciclo, ao(s) elemento(s) central(ais) da matriz[n][n].
        */

        for(int valor=1; valor <= elemCentral; valor++)
        {
            for (int i=acumA; i<=acumB; i++)
            {
                for (int j=acumA; j<=acumB; j++) matriz[i][j] = valor;
            }
            acumA++;
            acumB--;
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(j==0) printf("%3d", matriz[i][j]);
                else printf(" %3d", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}