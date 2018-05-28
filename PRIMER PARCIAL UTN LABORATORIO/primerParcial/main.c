#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "productos.h"
#include "menu.h"
#include "utn.h"
#define CANT 15
#define MAXP 5
#define PMAXI 1000

int main()
{
    eProducto producto[CANT];
    eProveedor proveedor[MAXP];

    hardCode(proveedor);

    int opcion;
    do{
        switch(menu())
        {
        case 1:
            {
                system("cls");
                altaProd(producto,CANT);
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                modificarProd(producto,CANT);
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                bajaProd(producto,CANT);
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                informar(producto,CANT);
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                listar(producto,proveedor,CANT,MAXP);
                system("pause");
                break;
            }
        case 6:
            {
                opcion=6;
                break;
            }
        }
    }while(opcion!=6);
    return 0;
}
