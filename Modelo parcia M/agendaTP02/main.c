#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANT 100
#define MAX 1000

int main()
{
    char seguir;
    eUsuario usuario[CANT];
    eProd producto[MAX];
    eVenta venta[MAX];
    inicioEstados(usuario,producto,venta,CANT,MAX);

    do{
        system("cls");
        switch(menu())
        {
        case 1:
            {
                system("cls");
                alta(usuario,CANT);
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                modificar(usuario,CANT);
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                modificar(usuario,CANT);
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                publicarProd(usuario,producto,CANT,MAX);
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                modPublicacion(usuario,producto,CANT);
                system("pause");
                break;
            }
        case 6:
            {
                system("cls");
                cancelPub(usuario,producto,CANT);
                system("pause");
                break;
            }
        case 7:
            {
                system("cls");
                comprarPro(usuario,producto,venta,CANT,MAX);
                system("pause");
                break;
            }
        case 8:
            {
                system("cls");
                listarPubUsu(usuario,producto,venta,CANT,MAX);
                system("pause");
                break;
            }
        case 9:
            {
                system("cls");
                listarPub(usuario,producto,auxiliar,CANT);
                system("pause");
                break;
            }
        case 10:
            {
                system("cls");
                listarUsu(usuario,CANT);
                system("pause");
                break;
            }
        case 11:
            {
                seguir='n';
                break;
            }
        }
    }while(seguir=='n');
    return 0;
}
