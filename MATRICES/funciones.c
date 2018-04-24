#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void alta(EProducto prod[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
        {
            if(prod[i].estado == 0)
                {
                    printf("Codigo: ");
                    scanf("%d", &prod[i].codigo);

                    printf("Descripcion: ");
                    fflush(stdin);
                    scanf("%s", prod[i].descripcion);

                    printf("Importe: ");
                    scanf("%f", &prod[i].importe);

                    printf("Cantidad: ");
                    scanf("%d", &prod[i].cantidad);

                    prod[i].estado = 1;

                    break;
                }
        }
}
