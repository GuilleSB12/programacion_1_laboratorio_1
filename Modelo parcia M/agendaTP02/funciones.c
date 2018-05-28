#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int menu()
{
    int opcion;

    printf("-----MENU PRINCIPAL-----\n\n");
    printf("\n1) Alta usuario\n");
    printf("\n2) Modificar usuario\n");
    printf("\n3) Baja de usuario\n");
    printf("\n4) Publicar producto\n");
    printf("\n5) Mostrar producto\n");
    printf("\n6) Cancelar publicacion\n");
    printf("\n7) Comprar producto\n");
    printf("\n8) Listar publicaciones de usuario\n");
    printf("\n9) Listar publicaciones\n");
    printf("\n10) Listar usuarios\n");
    fflush(stdin);
    printf("\nOpcion: ");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>10)
    {
        printf("\nError. Ingrese opcion valida: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    return opcion;
}

int menuModificar()
{
     int opcion;

    printf("\n-----MENU MODIFICAR-----\n\n");
    printf("\n1) Modificar nombre de usuario\n");
    printf("\n2) Modificar password\n");
    printf("\n3) Salir\n");
    fflush(stdin);
    printf("\nOpcion: ");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>3)
    {
        printf("\nError. Ingrese opcion valida: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    return opcion;
}

int menuModPubUsu()
{
    int opcion;
    printf("\n----MODIFICAR PUBLICACION----\n\n");
    printf("1) Modificar nombre de producto\n");
    printf("2) Modificar precio\n");
    printf("3) Modificar stock");
    printf("4) Salir\n\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    while(opcion<1 || opcion>4)
    {
        printf("\n\nERROR. Ingrese una opcion valida: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    return opcion;
}


void inicioEstados(eUsuario variable[],eProd var[],eVenta vari[],int CANT,int MAX)
{
    int i,j;

    for(i=0;i<CANT;i++)
    {
        variable[i].estado=0;
        variable[i].cantVentas=0;
    }
    for(j=0;i<MAX;j++)
    {
        vari[j].estado=0;
        var[j].estado=0;

    }
}

int buscarEspacioU(eUsuario variable[],int CANT)
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

int buscarEspacioP(eProd var[],int MAX)
{
    int i,indice=-1;

    for(i=0;i<MAX;i++)
    {
        if(var[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarEspacioV(eVenta vari[],int MAX)
{
    int i,indice=-1;

    for(i=0;i<MAX;i++)
    {
        if(vari[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarUsuario(eUsuario variable[],char codigo[],int CANT)
{
    int i,indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && strcmp(variable[i].nUsuario,codigo)==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarProducto(eProd var)
{
    printf("\nID PRODUCTO\tPRODUCTO\t\tPRECIO\tSTOCK\n\n");
    printf("\n%d\t%s\t\t%.2f\t%d\n\n");
}

void mostrarProductos(eProd var[],MAX);
{
    for(i=0;i<MAX;i++)
    {
        if(var[i].estado==1)
        {
            printf("\nID PRODUCTO\tPRODUCTO\t\tPRECIO\tSTOCK\n\n");
            printf("\n%d\t%s\t\t%.2f\t%d\n\n");
        }
    }
}

void mostrarUsuario(eUsuario variable)
{
    printf("USUARIO\t\t\t\n\n");
    printf("%s\t\t\t\n",variable.nUsuario);
}

void alta(eUsuario variable[],int CANT)
{
    int indice,esta;
    char codigo[20];

    indice=buscarEspacio(variable,CANT);
    if(indice==-1)
    {
        printf("\nERROR. No hay mas espacio disponible\n\n");
    }
    else
    {
        printf("\nNombre usuario [hasta 19 caracteres]: ");
        fflush(stdin);
        scanf("%s",codigo);
        while(strlen(codigo)>19)
        {
            printf("\nERROR. Ingrese un nombre de usuario mas corto: ");
            fflush(stdin);
            scanf("%s",codigo);
        }

        esta=buscarUsuario(variable,codigo,CANT);
        if(esta!=-1)
        {
            printf("\nERROR. Nombre de usuario ya utilizado\n\n");
        }
        else
        {
            variable[indice].estado=1;
            variable[indice].idUsuario=indice+1;
            strcpy(variable[indice].nUsuario,codigo);
            printf("\nPassword [1-8 caracteres]: ");
            fflush(stdin);
            scanf("%[^\n]",variable[indice].password);
            while(strlen(variable[indice].password)>8)
            {
                printf("\nERROR. Ingrese un password mas corto: ");
                fflush(stdin);
                scanf("%[^\n]",variable[indice].password);
            }
            printf("\n\nALTA EXITOSA\n\n");
        }
    }
}

void baja(eUsuario variable[],int CANT)
{
    int esta,intentos=3;
    char baja;
    char codigo[20];

    printf("\nIngrese el nombre de usuario: ");
    fflush(stdin);
    scanf("%[^\n]",codigo);
    while(strlen(codigo)>20 && intentos>0)
    {
        intentos--;
        printf("\nERROR. Ingrese un nombre de usuario valido: ");
        fflush(stdin);
        scanf("%[^\n]",codigo);
    }
    if(intentos==0)
    {
        printf("\nERROR. Supero el numero de intentos\n\n");
        break;
    }
    esta=buscarDni(variable,codigo,CANT);
    if(esta==-1)
    {
        printf("\nERROR. No hay ninguna persona con ese DNI\n");
    }
    else
    {
        system("cls");
        mostrarUsuario(variable[esta]);
        printf("\n\nDesea borrar este usuario? [s|n]: \n");
        fflush(stdin);
        scanf("%c",&baja);
        baja=tolower(baja);
        while(baja!='s' && baja!='n')
        {
            printf("\nERROR. Ingrese una opcion valida: ");
            fflush(stdin);
            scanf("%c",&baja);
        }
        if(baja=='s')
        {
            variable[esta].estado=0;
            printf("\n\nBAJA EXITOSA\n\n");
        }
        else
        {
            printf("\n\nBAJA CANCELADA\n\n");
        }
    }
}

void modificarUsu(eUsuario variable[],int CANT)
{
    char codigo[20];
    char auxP[9];
    int esta,opcion=0;
    int intentos=3;

    printf("\nIngrese nombre de usuario: ");
    fflush(stdin);
    scanf("%[^\n]",codigo);
    while(strlen(codigo)>20 && intentos>0)
    {
        intentos--;
        printf("\nERROR. Ingrese un nombre de usuario valido: ");
        fflush(stdin);
        scanf("%[^\n]",codigo);
    }
    if(intentos==0)
    {
        printf("\nERROR. Supero el numero de intentos\n\n");
    }

    esta=buscarUsuario(variable,codigo,CANT);

    if(esta==-1)
    {
        printf("\nERROR. No hay ninguna usuario con ese nombre\n");
    }
    else
    {
        intentos=3;
        printf("\nIngrese password: ");
        scanf("%[^\n]",auxP);
        while(strcmp((variable[esta].password,auxP)<0 || strcmp(variable[esta].password,auxP)>0) && intentos>0)
        {
            intentos--;
            printf("\nERROR. Ingrese password correcta: ");
            scanf("%[^\n]",auxP);
        }
        if(strcmp((variable[esta].password,auxP)==0 && intentos>0)
           {
             do{
                    system("cls");
                    mostrarUsuario(variable[esta]);
                    switch(menuModificar())
                    {
                        case 1:
                        {
                            printf("\nNuevo nombre de usuario: ");
                            fflush(stdin);
                            scanf("%[^\n]",variable[esta].nUsuario);
                            while(strlen(variable[esta].nUsuario)>19)
                            {
                                printf("\nERROR. Ingrese un nombre mas corto: ");
                                fflush(stdin);
                                scanf("%[^\n]",variable[esta].nUsuario);
                            }
                            break;
                        }
                        case 2:
                        {
                            printf("\nNuevo password: ");
                            fflush(stdin);
                            scanf("%[^\n]",variable[esta].password);
                            while(strlen(variable[esta].password)>8)
                            {
                                printf("\nERROR. Ingrese un password mas corto: ");
                                fflush(stdin);
                                scanf("%[^\n]",variable[esta].password);
                            }
                            break;
                        }
                        case 3:
                        {
                        opcion=4;
                            break;
                        }
                    }

                }while(opcion!=4);
           }
           else
           {
               printf("\nERROR. Supero el numero de intentos\n\n");
           }
    }
}

void publicarProd(eUsuario variable[],eProd var[],int CANT)
{
    char auxU[20];
    char auxP[9];
    int esta,indice,intentos=3;

    printf("Usuario: ");
    fflush(stdin);
    scanf("%[^\n]",auxU);
    while((strlen(auxU)>8) && intentos>0)
    {
        intentos--;
        printf("\nERROR. Ingrese correctamente el nombre de usuario: ");
        fflush(stdin);
        scanf("%[^\n]",auxU);
    }
    esta=buscarUsuario(variable,auxU,CANT)
    if(esta==-1)
    {
        printf("\nERROR. Usuario incorrecto\n\n");
    }
    else
    {
        intentos=3;
        printf("\nPassword: ");
        fflush(stdin);
        scanf("%[^\n]",auxP);
        while((strlen(auxP)>8) && intentos>0)
        {
            intentos--;
            printf("\nERROR. Ingrese password correcta: ");
            fflush(stdin);
            scanf("%[^\n]",auxP);
        }
        if(srtcmp(variable[esta].password,auxP)==0)
        {
            indice=buscarEspacioP(var,MAX);
            if(indice==-1)
            {
                printf("\nERROR. No hay mas espacio para productos\n\n");
            }
            else
            {
                printf("\n---PUBLICAR PRODUCTO---\n\n");
                printf("Nombre de producto: ");
                fflush(stdin);
                scanf("%[^\n]",var[indice].nombre);
                while(strlen(var[indice])>29)
                {
                    printf("ERROR. Ingrese un nombre mas corto: ");
                    fflush(stdin);
                    scanf("%[^\n]",var[indice].nombre);
                }
                printf("\nPrecio [1-100.000]: ");
                fflush(stdin);
                scanf("%f",var[indice].precio);
                while(var[indice].precio<1 || var[indice].precio>100000)
                {
                    printf("\nERROR. Ingrese un precio dentro de los limites[1-100.000]: ");
                    fflush(stdin);
                    scanf("%f",var[indice].precio);
                }
                printf("\nStock [1-1000]: ");
                fflush(stdin);
                scanf("%d",var[indice].stock);
                while(var[indice].stock<1 || var[indice].stock>1000)
                {
                    printf("\nERROR. Ingrese un precio dentro de los limites[1-1000]: ");
                    fflush(stdin);
                    scanf("%d",var[indice].precio);
                }
                var[indice].idProducto=indice+1;
                var[indice].estado=1;
                var[indice].idU=variable[esta].idUsuario;
                printf("\n\nPUBLICACION EXITOSA\n\n");
            }
        }
        else
        {
            printf("\nERROR. Supero el numero de intentos\n\n");
        }
    }
}

void listar(eUsuario variable[],int CANT)
{
    int i,flag=0;

    printf("\nUSUARIO\t\tEDAD\tDNI\n\n");
    ordenar(variable,CANT);
    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            printf("%s\t%d\t%s\n",variable[i].nUsuario,variable[i].***,variable[i].***);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No se ingresaron personas\n\n");
    }
}

void modPublicacion(eUsuario variable[],eProd var[],eAux vari[],int CANT)
{
    int esta,auxIdP,i,indice,codigo,intentos=3;
    char codigo[20];
    char auxPass[9];

    printf("\nNombre de usuario: ");
    scanf("%[^\n]",codigo);

    esta=buscarUsuario(variable,codigo,CANT);

    if(esta==-1)
    {
        printf("\nUsuario no encontrado\n");
    }
    else
    {
        printf("\nPassword: ");
        scanf("%s",auxPass);
        while((!strcmp(variable[esta].password,auxPass)==0) && intentos>0)
        {
            intentos--;
            printf("\nERROR. Ingrese password correcta: ");
            scanf("%s",auxPass);
        }
        codigo=variable[esta].idUsuario;
        if(strcmp(variable[esta].password,auxPass)==0 && intentos>0)
        {
            printf("----PUBLICACIONES DE %s----\n\n",variable[esta].nombre);
            printf("\nID PRODUCTO\tPRODUCTO\tPRECIO\tCANTIDAD VENDIDA\tSTOCK\n\n");
            listarPubUsu(variable,var,vari,codigo,CANT,MAX);
            printf("\nID de publicacion a modificar: ");
            fflush(stdin);
            scanf("%d",&auxIdP);
            while(auxIdP<1 || auxIdP>MAX)
            {
                printf("\nERROR. Ingrese un ID correcto: ");
                fflush(stdin);
                scanf("%d",&auxIdP);
            }
            for(i=0;i<MAX;i++)
            {
                if(auxIdP==var[i].idProducto)
                {
                    indice=i;
                    break;
                }
            }
            do{
                mostrarProducto(var[i]);
                switch(menuModPubUsu())
                {
                case 1:
                    {
                        printf("Nombre de producto: ");
                        fflush(stdin);
                        scanf("%[^\n]",var[indice].nombre);
                        while(strlen(var[indice].nombre)>29)
                        {
                            printf("\nERROR. Reingrese el nombre de producto [MAX 30 caracteres]: ");
                            fflush(stdin);
                            scanf("%[^\n]",var[indice].nombre);
                        }
                        break;
                    }
                case 2:
                    {
                        printf("Precio: ");
                        fflush(stdin);
                        scanf("%f",var[indice].precio);
                        while(var[indice].precio<1 || var[indice].precio>100000)
                        {
                            printf("\nERROR. Reingrese el precio del producto [MIN: 1 || MAX 100000]: ");
                            fflush(stdin);
                            scanf("%f",var[indice].precio);
                        }
                        break;
                    }
                case 3:
                    {
                        printf("Stock: ");
                        fflush(stdin);
                        scanf("%d",var[indice].stock);
                        while(var[indice].stock<1 || var[indice].stock>100)
                        {
                            printf("\nERROR. Reingrese el precio del producto [MIN: 1 || MAX 100]: ");
                            fflush(stdin);
                            scanf("%d",var[indice].stock);
                        }
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
        else
        {
            printf("\nERROR. Excedio el  numero de intentos");
        }
    }
}

void cancelPub(eUsuario variable[],eProd var[],eAux vari[],int CANT)
{
    int esta,auxIdP,i,indice,intentos=3;
    char codigo[20];
    char auxPass[9];
    char borrar;


    printf("\nNombre de usuario: ");
    scanf("%[^\n]",codigo);

    esta=buscarUsuario(variable,codigo,CANT);

    if(esta==-1)
    {
        printf("\nUsuario no encontrado\n");
    }
    else
    {
        printf("\nPassword: ");
        scanf("%s",auxPass);
        while((!strcmp(variable[esta].password,auxPass)==0) && intentos>0)
        {
            intentos--;
            printf("\nERROR. Ingrese password correcta: ");
            scanf("%s",auxPass);
        }
        if(strcmp(variable[esta].password,auxPass)==0 && intentos>0)
        {
            printf("----PUBLICACIONES DE %s----\n\n",variable[esta].nombre);
            printf("\nID PRODUCTO\tPRODUCTO\tPRECIO\tCANTIDAD VENDIDA\tSTOCK\n\n");
            listarPubUsu(variable,var,vari,CANT,MAX);
            printf("\nID de publicacion a modificar: ");
            fflush(stdin);
            scanf("%d",&auxIdP);
            while(auxIdP<1 || auxIdP>MAX)
            {
                printf("\nERROR. Ingrese un ID correcto: ");
                fflush(stdin);
                scanf("%d",&auxIdP);
            }
            for(i=0;i<MAX;i++)
            {
                if(auxIdP==var[i].idProducto)
                {
                    indice=i;
                    break;
                }
            }
            printf("\nDesea borrar el producto?[s|n]: ");
            fflush(stdin);
            scanf("%c",&borrar);
            borrar=tolower(borrar);
            while(borrar!='s' && borrar!='n')
            {
                printf("\nERROR. Ingrese una opcion valida: ");
                fflush(stdin);
                scanf("%c",&borrar);
            }
            if(borrar=='s')
            {
                printf("\nPRODUCTO BORRADO\n\n");
                var[indice].estado=0;
            }
            else
            {
                printf("\nBAJA CANCELADA\n\n");
            }
        }
        else
        {
            printf("\nERROR. Se excedio en el numero de intentos\n\n");
        }
    }
}

void comprarPro(eUsuario variable[],eProd var[],eAux vari[],int CANT,int MAX)
{
    int auxIdP,i,indice,indiceV;
    char comprar;

    listarPub(var,MAX);
    printf("\nIngrese ID de producto a comprar: ");
    fflush(stdin);
    scanf("%d",&auxIdP);
    for(i=0;i<MAX;i++)
    {
        if(var[i].idProducto==auxIdP)
        {
            indice=i;
            break;
        }
    }
    system("cls");
    mostrarProducto(var[indice]);
    printf("\nDesea comprar el producto? [s|n]: ");
    fflush(stdin);
    scanf("%c",&comprar);
    comprar=tolower(comprar);
    while(comprar!='s' && comprar!='n')
    {
        printf("\nERROR. Ingrese una opcion valida [s|n]: ");
        fflush(stdin);
        scanf("%c",&comprar);
    }
    if(comprar=='s')
    {
        printf("\nCalifique al vendedor [1-10]: ");
        fflush(stdin);
        scanf("%d",&califica);
        while(califica<1 || califica>10)
        {
            printf("\nERROR. Ingrese una calificacion valida [1-10]: ");
            fflush(stdin);
            scanf("%d",&califica);
        }
        var[indice].stock--;
        indiceV=buscarEspacioV(vari[],MAX);
        if(indiceV==-1)
        {
            printf("\nERROR. Se alcanzo el tope de ventas\n\n");
        }
        else
        {
            variable[].cantVendida
            vari[indiceV].idUsuario=var[indice].idU;
            vari[indiceV].idProducto=var[indice].idProducto;
            vari[indiceV].calificacion=califica;
            vari[indiceV].estado=1;
            printf("\nCOMPRA EXITOSA\n\n");
        }
    }
    else
    {
        printf("\nCOMPRA CANCELADA\n\n");
    }
}

void listarUsu(eUsuario variable[],int CANT)
{
    int i,flag=0;

    printf("NOMRE DE USUARIO\tCALIFICACION PROMEDIO\n\n");

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            flag=1;
            printf("%s\t%.2f\n\n"); //ARREGLAR LAS CALIFICACIONES EN COMPRAS
        }
    }
    if(flag==0)
    {
        printf("\nNO HAY USUARIOS PARA LISTAR\n\n");
    }
}

void listarPub(eProd var[],int MAX)
{
    int i;

    for(i=0;i<MAX;i++)
    {
        if(var[i].estado==1)
        {
            printf("%d\t\%s\t%.2f\t%d\n\n",var[i].idProducto,var[i].nombre,var[i].precio,var[i].stock);
        }
    }
}
void listarPubUsu(eUsuario variable[],eProd var[],eVenta vari[],int codigo,int CANT,int MAX)
{
    int i;

    for(i=0;i<MAX;i++)
    {
        if(var[i].idU==codigo && var[i].estado==1)
        {
            printf("%d\t%s\t%.2f\t%d\t%d",var[i].idProducto,var[i].nombre,var[i].precio,var[i].CANTIDADVENDIDA,var[i].stock);
        }
    }
}
