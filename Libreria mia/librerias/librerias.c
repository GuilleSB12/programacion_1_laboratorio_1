#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "estructuras.h"


int getIntEntreMinMax(char mensaje[],int maximo, int minimo, int *respuesta)
{
    int retorno=0;
    int ingresoAux;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &ingresoAux);
    if(ingresoAux<minimo)
    {
        retorno = -1;
    }
    else
    {
        if(ingresoAux>maximo)
        {
            retorno = 1;
        }
        else
        {
             *respuesta=ingresoAux;
             retorno = 0;
        }
    }

    return retorno;
}

int menu()
{
    int opcion;
    int respuesta;
    printf("-----MENU-----\n\n");
    printf("1) ALTA\n");
    printf("2) BAJA\n");
    printf("3) MODIFICAR\n");
    printf("4) LISTAR\n");
    printf("5) COMPRAR\n");
    printf("6) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",6,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",6,1,&opcion);
    }
}

int menuModificar1()
{
    int opcion;
    int respuesta;
    printf("\n-----MENU MODIFICAR-----\n\n");
    printf("1) MODIFICAR \n");
    printf("2) MODIFICAR\n");
    printf("3) MODIFICAR\n");
    printf("4) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",4,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",6,1,&opcion);
    }
}

int menuModificar2()
{
    int opcion;
    int respuesta;
    printf("-----MENU MODIFICAR 2-----\n\n");
    printf("1) MODIFICAR\n");
    printf("2) MODIFICAR\n");
    printf("3) MODIFICAR\n");
    printf("4) SALIR\n");
    respuesta=getIntEntreMinMax("\nOPCION: ",4,1,&opcion);
    while(respuesta!=0)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        respuesta=getIntEntreMinMax("\nOPCION: ",6,1,&opcion);
    }
}

void inicioEstados(eEstructura1 variable[],eEstructura2 var[],eEstructura3 vari[],int CANT,int MAX)
{
    int i,j;
    for(i=0;i<CANT;i++)
    {
        variable[i].estado=0;
    }
    for(j=0;i<MAX;j++)
    {
        var[j].estado=0;
        vari[j].estado=0;
    }
}

int buscarIndice1(eEstructura1 variable[],int CANT)
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

int buscarIndice2(eEstructura2 var[],int MAX)
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

int buscarIndice3(eEstructura3 vari[],int MAX);
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

void mostrarE1(eEstructura1 variable)
{
    printf("\nNOMBRE\t\NUMERO\t\NUMERO\n\n");
    printf("%s\t%d\t%d\n",variable.NOMBRE,variable.NUMERO1,variable.NUMERO2);
}

void mostrarE2(eEstructura2 var)
{
    printf("\nNOMBRE\t\NUMERO\t\NUMERO\n\n");
    printf("%s\t%d\t%d\n",var.NOMBRE,var.NUMERO1,var.NUMERO2);
}

int encontrarE1(eEstructura1 variable[],int codigo,int CANT)
{
    int i,indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].id==codigo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int encontrarE2(eEstructura2 var[],int codigo,int MAX)
{
    int i,indice=-1;

    for(i=0;i<MAX;i++)
    {
        if(var[i].id==codigo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int encontrarE3(eEstructura3 vari[],int codigo,int MAX)
{
    int i,indice=-1;

    for(i=0;i<MAX;i++)
    {
        if(vari[i].id==codigo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void listarEe1(eEstructura1 variable[],int CANT)
{
    int i,flag=0;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            flag=1;
            printf("%s\t%d\t%d\n",variable[i].nombre,variable[i].id,variable[i].NUMERO);
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay XXX que mostrar\n\n");
    }
}

void listarEe2(eEstructura2 var[],int MAX)
{
    int i,flag=0;

    for(i=0;i<MAX;i++)
    {
        if(var[i].estado==1)
        {
            flag=1;
            printf("%s\t%d\t%d\n",var[i].NOMBRE,var[i].NUMERO1,var[i].NUMERO2);
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No hay XXX que mostrar\n\n");
    }
}

void altaE1(eEstructura1 variable[],int CANT)
{
    int esta,indice,aux1,rAux1,aux2,aux3;

    indice=buscarIndice1(variable,CANT);
    if(indice==-1)
    {
        printf("\nERROR. No hay mas espacio disponible\n\n");
    }
    else
    {
        aux1=getIntEntreMinMax("Ingrese NUMERO: ",CANT,1,&rAux1);
        while(aux1!=0)
        {
            printf("\nERROR. Ingrese NUMERO valido");
            aux1=getIntEntreMinMax("Ingrese NUMERO: ",CANT,1,&rAux1);
        }
        esta=encontrarE1(variable,rAux1,CANT)
        if(esta!=-1)
        {
            printf("\nERROR. Ya hay un XXX con ese numero||nombre\n\n");
        }
        else
        {
            variable[indice].estado=1;
            variable[indice].id=rAux1;

            printf("\nNOMBRE: ");
            fflush(stdin);
            scanf("%[^\n]",variable[indice].nombre);
            while(strlen(variable[indice].nombre)<1 || strlen(variable[indice].nombre)>19)
            {
                printf("\nERROR. Ingrese un nombre valido [1-19 caracteres]: ");
                fflush(stdin);
                scanf("%[^\n]",variable[indice].nombre);
            }


            printf("\nALTA EXITOSA\n\n");
        }
    }

}

void bajaE1(eEstructura1 variable[],int CANT)
{
    int esta,aux1,rAux1,aux2,aux3;
    char baja;

    aux1=getIntEntreMinMax("Ingrese NUMERO: ",CANT,1,&rAux1);
    while(aux1!=0)
    {
        printf("\nERROR. Ingrese NUMERO valido");
        aux1=getIntEntreMinMax("Ingrese NUMERO: ",CANT,1,&rAux1);
    }
    esta=encontrarE1(variable,rAux1,CANT)
    if(esta==-1)
    {
        printf("\nERROR. No se encontro XXX\n\n");
    }
    else
    {
        system("cls");
        mostrarE1(variable[esta]);
        printf("\nDesea borrar XXX? [s|n]: ");
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

void modificarE1(eEstructura1 variable[],int CANT)
{
    int aux1,rAux1,aux2,aux3;
    char seguir;

    listarEe1(variable,CANT);
    aux1=getIntEntreMinMax("ID de VARIABLE a MODIFICAR: ",1,CANT,&rAux1);
    while(rAux1!=0)
    {
        printf("\nERROR. Ingrese un ID valido: ");
        aux1=getIntEntreMinMax("ID de VARIABLE a MODIFICAR: ",1,CANT,&rAux1);
    }
    aux2=encontrarE1(variable,rAux1,CANT);
    do{
        switch(menuModificar1())
        {
            case 1:
            {
                break;
            }
        case 2:
            {
                break;
            }
        case 3:
            {
                break;
            }
        case 4:
            {
                seguir='n';
                break;
            }
        }

    }while(opcion!='n');
}


//ORDENA DE MANERA ASCENDENTE NOMBRE
void ordenarE1Nombre(eEstructura1 variable[],int CANT)
{
    int i,j;
    eEstructura1 auxiliar;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(strcmp(variable[i].nombre,variable[j].nombre)>0)
            {
                auxiliar=variable[i];
                variable[i]=variable[j];
                variable[j]=auxiliar;
            }
        }
    }
}

//ORDENA DESCENDENTE
void ordenarE1Numero(eEstructura1 variable[],int CANT)
{
    int i,j;
    eEstructura1 auxiliar;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(variable[i].id<variable[j].id)
            {
                auxiliar=variable[i];
                variable[i]=variable[j];
                variable[j]=auxiliar;
            }
        }
    }
}

void ordenarE2Nombre(eEstructura2 var[],int MAX)
{
    int i,j;
    eEstructura2 auxiliar;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(strcmp(var[i].nombre,var[j].nombre)>0)
            {
                auxiliar=var[i];
                var[i]=var[j];
                var[j]=auxiliar;
            }
        }
    }
}

void ordenarE2Numero(eEstructura2 var[],int MAX)
{
    int i,j;
    eEstructura2 auxiliar;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(var[i].id<var[j].id)
            {
                auxiliar=var[i];
                var[i]=var[j];
                var[j]=auxiliar;
            }
        }
    }
}
