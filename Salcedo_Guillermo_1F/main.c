#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "proveedor.h"
#include "menu.h"


#define CANT 3



int main()
{
    int salir = 0;

    EProducto vec [CANT];

    inicializarProducto (vec, CANT);



    do {

            switch( menu ())
            {
                case 1:
                    alta(vec, CANT);
                    break;
                case 2:
                    modificar(vec, CANT);
                    break;
                case 3:
                    baja(vec, CANT);
                    break;
                case 4:
                    informar(vec, CANT);
                    break;
                case 5:
                    listar(vec, CANT);
                    break;
                case 6:
                    printf("\nSALIR\n\n");
                    salir = 1;
                    break;

                default:
                    printf("\nOpcion Incorrecta, ingrese nuevamente opcion entre 1 y 6.\n\n");
                    system("pause");
            }
        } while ( salir != 1 );


    return 0;
}
