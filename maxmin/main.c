#include <stdio.h>
#include <limits.h>

int main()
    {
        int i;
        int suma = 0;
        int max;
        int min;
        int flag = 0;
        float promedio;


        for(i=0; i<10;i++)
        {
            printf("Ingrese un numero:\n ");
            int aux;
            scanf("%d",&aux);
            suma=suma+aux;

        if(aux>max || flag == 0)
            {
                max = aux;
            }

        if(aux<min || flag == 0)
            {
                min = aux;
                flag = 1;
            }
        }

    promedio = (float) suma / i;

    printf("la suma es: %d\n",suma);
    printf("El maximo es: %d\n",max);
    printf("El minimo es: %d\n",min);
    printf("El promedio es: %.2f\n", promedio);

    return 0;


    }
