#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "productos.h"
#include "menu.h"
#include "utn.h"

void inicioEstados(eProducto variable[],int CANT)
{
    int i,j;
    for(i=0;i<CANT;i++)
    {
        variable[i].estado=0;
    }
}

int buscarIndice(eProducto variable[],int CANT)
{
    int i,indice=-1;
    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarProve(eProveedor var[],int MAXP)
{
    int i,flag=0;

    for(i=0;i<MAXP;i++)
    {
        if(var[i].estado==1)
        {
            printf("\n%d\t%s",var[i].codigo,var[i].descripcion);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay proveedores para mostrar\n\n");
    }
}

void hardCode(eProveedor var[])
{
    var[0].codigo=1;
    strcpy(var[0].descripcion,"Proveedor 1");
    var[0].estado=1;

    var[1].codigo=2;
    strcpy(var[1].descripcion,"Proveedor 2");
    var[1].estado=1;

    var[2].codigo=3;
    strcpy(var[2].descripcion,"Proveedor 3");
    var[2].estado=1;

    var[3].codigo=4;
    strcpy(var[3].descripcion,"Proveedor 4");
    var[3].estado=1;

    var[4].codigo=5;
    strcpy(var[4].descripcion,"Proveedor 5");
    var[4].estado=1;
}

void mostrarProd(eProducto variable)
{
    printf("\nDESCRIPCION\tIMPORTE\t\CANTIDAD\n\n");
    printf("%s\t%.2f\t%d\n",variable.descripcion,variable.importe,variable.cantidad);
}

//ENCUENTRA UN PRODUCTO
int encontrarProd(eProducto variable[],int codigo,int CANT)
{
    int i,indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].codigo==codigo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

//LISTA TODOS LOS PRODUCTOS
void listarProductos(eProducto variable[],int CANT)
{
    int i,flag=0;

    ordenarNombre(variable,CANT);

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            flag=1;
            printf("%s\t%.2f\t%d\n",variable[i].descripcion,variable[i].importe,variable[i].cantidad);
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No se ingresaron productos para mostrar\n\n");
    }
}

//ABM
void altaProd(eProducto variable[],eProveedor var[],int CANT,int MAXP,int PMAXI)
{
    int indice,idProve,auxCant;
    float auxImp;
    char auxDes[50];

    indice=buscarIndice(variable,CANT);
    if(indice==-1)
    {
        printf("\nERROR. No hay espacio para mas productos\n\n");
    }
    else
    {
            variable[indice].estado=1;
            variable[indice].codigo=indice+1;

            mostrarProve(var,MAXP);
            printf("\nIngrese ID de proveedor: ");
            fflush(stdin);
            scanf("%d",&idProve);
            while(idProve<1 || idProve>MAXP)
            {
                printf("\nERROR. Ingrese un ID de proveedor valido: ");
                fflush(stdin);
                scanf("%d",&idProve);
            }
            variable[indice].codigoProv=idProve;

            printf("\nIngrese descripcion de producto [1-49 caracteres]: ");
            fflush(stdin);
            scanf("%[^\n]",auxDes);
            while(strlen(auxDes)<1 || strlen(auxDes)>49)
            {
                printf("\nERROR. Ingrese una descripcion mas breve: ");
                fflush(stdin);
                scanf("%[^\n]",auxDes);
            }
            strcpy(variable[indice].descripcion,auxDes);

            printf("\nIngrese importe de producto: ");
            fflush(stdin);
            scanf("%f",&auxImp);
            while(auxImp<1 || auxImp>PMAXI)
            {
                printf("\nERROR. Ingrese un precio correcto [1-1000]: ");
                fflush(stdin);
                scanf("%f",auxImp);
            }
            variable[indice].importe=auxImp;

            printf("\nIngrese cantidad de productos: ");
            fflush(stdin);
            scanf("%d",&auxCant);
            while(auxCant<1 || auxCant>PMAXI)
            {
                printf("\nERROR. Ingrese una cantidad correcta [1-1000]: ");
                fflush(stdin);
                scanf("%d",auxCant);
            }
            variable[indice].cantidad=auxImp;

            printf("\nALTA EXITOSA\n\n");
        }
}

void bajaProd(eProducto variable[],int CANT)
{
    int esta,auxCod;
    char baja;


    listarProductos(variable,CANT);
    printf("\nIngrese codigo del producto: ");
    fflush(stdin);
    scanf("%d",&auxCod);
    while(auxCod<1 || auxCod>CANT)
    {
        printf("\nERROR. Ingrese un codigo de producto valido: ");
        fflush(stdin);
        scanf("%d",&auxCod);
    }
    esta=encontrarProd(variable,auxCod,CANT);
    if(esta==-1)
    {
        printf("\nERROR. No hay productos con el codigo ingresado");
    }
    else
    {
        system("cls");
        mostrarProd(variable[esta]);
        printf("\nDesea borrar el producto? [s|n]: ");
        fflush(stdin);
        scanf("%c",&baja);
        baja=tolower(baja);
        while(baja!='s' && baja!='n')
        {
            printf("\nERROR. Ingrese una opcion valida [s|n]: ");
            fflush(stdin);
            scanf("%c",&baja);
            baja=tolower(baja);
        }
        if(baja=='s')
        {
            variable[esta].estado=0;
            printf("\nBAJA EXITOSA\n\n");
        }
        else
        {
            printf("\nBAJA CANCELADA\n\n");
        }
    }
}

void modificarProd(eProducto variable[],int CANT)
{
    int auxCod, auxCant,esta;
    char seguir;
    float auxImp;
    char auxDes[50];

    listarProductos(variable,CANT);
    printf("\nIngrese codigo del producto: ");
    fflush(stdin);
    scanf("%d",&auxCod);
    while(auxCod<1 || auxCod>CANT)
    {
        printf("\nERROR. Ingrese un codigo de producto valido: ");
        fflush(stdin);
        scanf("%d",&auxCod);
    }
    esta=encontrarProd(variable,auxCod,CANT);
    if(esta==-1)
    {
        printf("\nERROR. No hay productos con el codigo ingresado");
    }
    else
    {
        do{
            mostrarProd(variable[esta]);
            switch(menuModificar())
            {
                case 1:
                {
                        printf("\nIngrese descripcion de producto [1-49 caracteres]: ");
                        fflush(stdin);
                        scanf("%[^\n]",auxDes);
                        while(strlen(auxDes)<1 || strlen(auxDes)>49)
                        {
                            printf("\nERROR. Ingrese una descripcion mas breve: ");
                            fflush(stdin);
                            scanf("%[^\n]",auxDes);
                        }
                        strcpy(variable[indice].descripcion,auxDes);
                        break;
                }
                case 2:
                {
                        printf("\nIngrese importe de producto: ");
                        fflush(stdin);
                        scanf("%f",&auxImp);
                        while(auxImp<1 || auxImp>PMAXI)
                        {
                            printf("\nERROR. Ingrese un precio correcto [1-1000]: ");
                            fflush(stdin);
                            scanf("%f",auxImp);
                        }
                        variable[indice].importe=auxImp;
                        break;
                }
                case 3:
                {
                        printf("\nIngrese cantidad de productos: ");
                        fflush(stdin);
                        scanf("%d",&auxCant);
                        while(auxCant<1 || auxCant>PMAXI)
                        {
                            printf("\nERROR. Ingrese una cantidad correcta [1-1000]: ");
                            fflush(stdin);
                            scanf("%d",auxCant);
                        }
                        variable[indice].cantidad=auxImp;
                        break;
                }
                case 4:
                {
                        seguir='n';
                        break;
                }
            }
        }while(seguir!='n');
    }
}

void informar(eProducto variable[],int CANT)
{
    do{
        switch(menuInformar())
        {
        case 1:
            {
                informarTPS(eProducto variable[],int CANT);
                break;
            }
        case 2:
            {
                informarTPB(eProducto variable[],int CANT);
                break;
            }
        case 3:
            {
                informarSB(eProducto variable[],int CANT);
                break;
            }
        case 4:
            {
                informarSM(eProducto variable[],int CANT);
                break;
            }
        case 5:
            {
                opcion=5;
                break;
            }
        }

    }while(opcion!=5);
}

void informarTPS(eProducto variable[],int CANT)
{
    int i,j,acumSupPro=0;
    float acumPrecio=0;
    int acumDiv=0;
    int flag=0;
    float promedio;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            acumPrecio=acumPrecio+variable[i].importe;
            acumDiv++;
        }
    }

    promedio=acumPrecio/acumDiv;

    for(j=0;j<CANT;j++)
    {
        if(variable[j].estado==1 && variable[j].importe>promedio)
        {
            acumSupPro++;
        }
    }

    if(flag==0)
    {
        printf("\nERROR. No hay productos para informar\n\n");
    }
    else
    {
        printf("\nIMPORTE TOTAL\tPROMEDIO\tPRODUCTOS QUE SUPERAN EL PROMEDIO\n\n");
        printf("%.2f\t%.2f\t%d",acumPrecio,promedio,acumSupPro);
    }
}

void informarTPB(eProducto variable[],int CANT)
{
    int i,j,acumBajPro=0;
    float acumPrecio=0;
    int acumDiv=0;
    int flag=0;
    float promedio;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            acumPrecio=acumPrecio+variable[i].importe;
            acumDiv++;
        }
    }

    promedio=acumPrecio/acumDiv;

    for(j=0;j<CANT;j++)
    {
        if(variable[j].estado==1 && variable[j].importe<promedio)
        {
            acumBajPro++;
        }
    }

    if(flag==0)
    {
        printf("\nERROR. No hay productos para informar\n\n");
    }
    else
    {
        printf("\nIMPORTE TOTAL\tPROMEDIO\tPRODUCTOS QUE NO SUPERAN EL PROMEDIO\n\n");
        printf("%.2f\t%.2f\t%d",acumPrecio,promedio,acumBajPro);
    }
}

void informarSM(eProducto variable[],int CANT)
{
    int i,acumSup=0;
    int flag=0;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && variable[i].cantidad>10)
        {
            acumSup++;
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay productos que informar\n\n");
    }
    else
    {
        printf("\nCANTIDAD DE PRODUCTOS CON MAS STOCK QUE 10");
        printf("%d",acumSup);
    }
}

void informarSB(eProducto variable[],int CANT)
{
    int i,acumBaj=0;
    int flag=0;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && variable[i].cantidad<10)
        {
            acumBaj++;
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay productos que informar\n\n");
    }
    else
    {
        printf("\nCANTIDAD DE PRODUCTOS CON MAS STOCK QUE 10");
        printf("%d",acumBaj);
    }
}

void listarProSobre10(eProducto variable,int CANT)
{
    int i;
    int flag=0;

    printf("\n---PRODUCTOS CON MAS DE 10 STOCK\n");
    printf("\nDESCRIPCION\tCANTIDAD\tPRECIO\n\n");
    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && variable[i].cantidad>10)
        {
            printf("%s\t%d\t%.2f\n",variable[i].descripcion,variable[i].cantidad,variable[i].importe);
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay productos que informar\n\n");
    }
}

void listarProBajo10(eProducto variable,int CANT)
{
    int i;
    int flag=0;

    printf("---PRODUCTOS CON MENOS DE 10 STOCK");
    printf("\nDESCRIPCION\tCANTIDAD\tPRECIO\n\n");
    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && variable[i].cantidad<10)
        {
            printf("%s\t%d\t%.2f\n",variable[i].descripcion,variable[i].cantidad,variable[i].importe);
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay productos que informar\n\n");
    }
}

void listar(eProducto variable[],int CANT)
{
    int opcion;

    do{
        switch(menuListar())
        {
        case 1:
            {
                system("cls");
                listarProductos(variable,CANT);
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                listarProBajo10(variable,CANT);
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                listarProSobre10(variable,CANT);
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                system("pause");
                break;
            }
        case 6:
            {
                system("cls");
                system("pause");
                break;
            }
        case 7:
            {
                system("cls");
                system("pause");
                break;
            }
        case 8:
            {
                system("cls");
                system("pause");
                break;
            }
        case 9:
            {
                system("cls");
                system("pause");
                break;
            }
        case 10:
            {
                system("cls");
                system("pause");
                break;
            }
        case 11:
            {
                system("cls");
                system("pause");
                break;
            }
        case 12:
            {
                system("cls");
                system("pause");
                break;
            }
        case 13:
            {
                opcion=13;
                break;
            }
        }

    }while(opcion!=13);
}

//ORDENAR ESTRUCTURAS
void ordenarNombre(eProducto variable[],int CANT)
{
    int i,j;
    eProducto auxiliar;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(variable[i].importe<variable[j].importe)
                {
                    auxiliar=variable[i];
                    variable[i]=variable[j];
                    variable[j]=auxiliar;
                }

            if(variable[i].importe==variable[j].importe)
            {
                if(strcmp(variable[i].descripcion<variable[j].descripcion)>0)
                {
                    auxiliar=variable[i];
                    variable[i]=variable[j];
                    variable[j]=auxiliar;
                }
            }
        }
    }
}


