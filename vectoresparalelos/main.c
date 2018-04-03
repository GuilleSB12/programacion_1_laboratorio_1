#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int i;
    int edad [ CANT ];
    float sueldo [ CANT ];
    int legajo [ CANT ];

    for ( i = 0; i < CANT; i++ )
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo[i]);

        printf("Ingrese legajo: ");
        scanf("%d", &legajo[i]);
    }

    for ( i = 0; i < CANT; i++)
    {
        printf("%d", edad[i]);

        printf("%f", sueldo[i]);

        printf("%d", legajo[i]);
    }

    return 0;
}
