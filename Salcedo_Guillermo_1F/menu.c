#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int menu()
{
    int opcion;

        printf("1- ALTA\n");
        printf("2- MODIFICAR\n");
        printf("3- BAJA\n");
        printf("4- INFORMAR\n");
        printf("5- LISTAR\n\n");
        printf("6- SALIR\n");

        scanf("%d",&opcion);

        fflush(stdin);

    return opcion;
}
