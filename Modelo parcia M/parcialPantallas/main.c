#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "pantallas.h"

#define CMAX 2
#define CANT
#define MAX
#define TOP 6

eCliente cliente[]={{"23384565324","Compania de telefonos celulares",1},{"2419342525456","Proveedor de cable",1}};
ePantallaLcd pantalla[TOP];

int main()
{
    do{
        switch(menu())
        {
        case 1:
            {
                system("cls");
                altaPantalla(pantalla,TOP);
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                modificarPantalla(pantalla,TOP);
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                bajaPantalla(pantalla,TOP);
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                mostrarPantallas(pantalla,TOP);
                system("pause");
                break;
            }
        case 5:
            {
                seguir='n';
                break;
            }
        }
    }while(seguir!='n');
    return 0;
}
