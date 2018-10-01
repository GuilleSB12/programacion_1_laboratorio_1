#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int menu()
{
    int opcion;

    system("cls");
    printf("---ABM Empleados---\n\n");
    printf("1-Alta\n");
    printf("2-Baja\n");
    printf("3-Modificar\n");
    printf("4-Listar\n");
    printf("5-Ordenar\n");
    printf("6-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void inicializarEmpleados(eEmpleado vec[], int tam)
{
    int i;

    for(i=0; i< tam; i++)
    {
        vec[i].isEmpty =1;
    }
}




void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int i;

    system("cls");
    printf("---Lista de Empleados---\n\n");
    printf("  Legajo  Nombre   Sexo   Sueldo   Fecha de Ingreso \n\n");
    for(i=0; i< tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
        }
    }
}



void mostrarEmpleado(eEmpleado emp)
{
    printf("  %4d     %s     %c  %10.2f \n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo );
}




int buscarLibre (eEmpleado vec[], int tam)
{
    int indice = -1;
    int i;

    for (i=0; i < tam; i++)
    {
        if (vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    int i;

    for (i=0; i < tam; i++)
    {
        if (vec[i].isEmpty == 0 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



void altaEmpleados (eEmpleado vec[], int tam)
{
    eEmpleado nuevoEmpleado;
    int legajo;
    int indice;
    int existe;

    system("cls");
    printf("---Alta empleado---\n\n");


    indice = buscarLibre (vec, tam);

    if ( indice == -1 )
    {
         printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }

    else
    {
         printf("Ingrese legajo: ");
         scanf("%d", &legajo);

         existe = buscarEmpleado (vec, tam, legajo);

         if ( existe != -1 )
         {
             printf("\nEl legajo %d ya esta dado de alta en el sistema\n", legajo);
             mostrarEmpleado(vec[existe]);
         }

         else
         {
             nuevoEmpleado.isEmpty = 0;
             nuevoEmpleado.legajo = legajo;

                   printf("Ingrese nombre: ");
                   fflush(stdin);
                   gets(nuevoEmpleado.nombre);

                   printf("Ingrese sexo: ");
                   fflush(stdin);
                   scanf("%c", &nuevoEmpleado.sexo);

                   printf("Ingrese sueldo: ");
                   scanf("%f", &nuevoEmpleado.sueldo);

                   vec[indice] = nuevoEmpleado;

         }
    }
}



void bajaEmpleado (eEmpleado vec[], int tam)
{
    int legajo;
    int existe;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("d", &legajo);

    existe = buscarEmpleado (vec, tam, legajo);

    if ( existe == -1 )
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);
        system("pause");

    }

    else
    {
        mostrarEmpleado (vec[existe]);

        printf("¿Confirma baja del empleado?: s/n");
        scanf("%c", %confirma);

        if ( )

    }

}



void modifica (eEmpleado vec[], int tam)
{

}
