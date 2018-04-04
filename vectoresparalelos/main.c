#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int i;
    int edad[CANT];
    float sueldo[CANT];
    int legajo[CANT];



    for ( i = 0; i < CANT; i++ )
    {
        legajo[i] = i + 1;
    }
    for ( i = 0; i < CANT; i++ )
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo[i]);
    }

    for ( i = 0; i < CANT; i++)
    {

        printf("%d\n", legajo[i]);

        printf("%d\n", edad[i]);

        printf("%.2f\n", sueldo[i]);
    }

    return 0;
}
