#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "productos.h"
#include "menu.h"
#include "utn.h"

int menu()
{
    int opcion;
    int respuesta;

    printf("-----MENU-----\n\n");
    printf("1) ALTA\n");
    printf("2) MODIFICAR\n");
    printf("3) BAJA\n");
    printf("4) INFORME\n");
    printf("5) LISTAR\n");
    printf("6) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",6,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",6,1,&opcion);
    }
}

int menuModificar()
{
    int opcion;
    int respuesta;
    printf("\n-----MENU MODIFICAR-----\n\n");
    printf("1) MODIFICAR DESCRIPCION \n");
    printf("2) MODIFICAR IMPORTE\n");
    printf("3) MODIFICAR CANTIDAD\n");
    printf("4) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",4,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",4,1,&opcion);
    }
}

int menuInformar()
{
    int opcion;
    int respuesta;
    printf("\n-----MENU INFORMAR-----\n\n");
    printf("1) TOTAL Y PROMEDIO DE IMPORTES Y PRODUCTOS QUE SUPERAN PROMEDIO \n");
    printf("2) TOTAL Y PROMEDIO DE IMPORTES Y PRODUCTOS QUE NO SUPERAN PROMEDIO\n");
    printf("3) CANTIDAD DE PRODUCTOS CON MENOS DE 10 DE STOCK\n");
    printf("4) CANTIDAD DE PRODUCTOS CON MAS DE 10 DE STOCK\n");
    printf("5) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",5,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",5,1,&opcion);
    }
}

int menuListar()
{
    int opcion;
    int respuesta;
    printf("\n-----MENU LISTAR-----\n\n");
    printf("1) TODOS LOS PRODUCTOS\n");
    printf("2) PRODUCTOS CON MAYOR STOCK A 10\n");
    printf("3) PRODUCTOS CON MENOR STOCK A 10\n");
    printf("4) PRODUCTOS QUE SUPERAN EL PROMEDIO DE IMPORTES\n");
    printf("5) PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE IMPORTES\n");
    printf("6) PROVEEDORES CON 10 O MAS PRODUCTOS\n");
    printf("7) PRODUCTOS PROVISTOS POR CADA PROVEEDOR\n");
    printf("8) PRODUCTOS DE UN PROVEEDOR\n");
    printf("9) PROVEEDOR CON MAS PRODUCTOS Y SUS PRODUCTOS\n");
    printf("10) PROVEEDOR CON MENOS PRODUCTOS Y SUS PRODUCTOS\n");
    printf("11) PROVEEDOR CON PRODUCTO MAS CARO Y PRODUCTO\n");
    printf("12) PROVEEDOR CON PRODUCTO MAS BARATO Y PRODUCTO\n");
    printf("13) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",13,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",13,1,&opcion);
    }
}
