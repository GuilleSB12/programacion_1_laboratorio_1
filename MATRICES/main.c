#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define CANT 50


int main()
{

    char seguir='s';
    int opcion=0;

    EProducto prod[CANT];

    while(seguir=='s')
        {
            printf("1- Dar de alta el producto.\n");
            printf("2- Modificar\n");
            printf("3- Dar de baja el producto.\n");
            printf("4- Listar \n");
            printf("5- Salir\n");

            scanf("%d",&opcion);

            switch(opcion)
                {
                    case 1: alta(prod);
                        break;

                    case 2:
                        break;

                    case 3:
                        break;

                    case 4:
                        break;

                    case 5:
                        seguir = 'n';
                        break;
                }
        }

    return 0;

}
