#include <stdio.h>
#include <stdlib.h>

int main()
{
    float matriz[2][3];

    int i,j;

    for(i=0;i<2;i++)
        {
            for(j=0;j<3;j++)
                {
                    printf("M[%d][%d]: ",i,j);
                    scanf("%f",&matriz[i][j]);
                }
        }

        for(i=0;i<2;i++)
            {
                for(j=0;j<3;j++)
                    {
                        printf("\t%.0f", matriz[i][j]); //usar %t siempre
                    }

                    printf("\n"); //se usa esto xq sino me los muestra en fila. MUY IMPORTANTE!!!!!!!!!!
            }


    return 0;
}
