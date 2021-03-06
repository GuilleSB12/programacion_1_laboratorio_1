#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 2


int main()
{
    int salir = 0;
    eEmpleado gente[TAM];

    inicializarEmpleados(gente, TAM);

    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleados(gente, TAM);
            system("pause");
            break;
        case 2:
            bajaEmpleado(gente, TAM);
            system("pause");
            break;
        case 3:
            modifica(gente, TAM);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(gente, TAM);
            system("pause");
            break;
        case 5:
            printf("\nOrdenar\n\n");
            system("pause");
            break;
        case 6:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }
    }
    while(salir != 1);

    return 0;
}
