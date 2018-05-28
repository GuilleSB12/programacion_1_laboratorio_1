#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"

#define VACIO 0
#define ALTA 1

int agregarPersona(S_Persona pPersona[],int array)
{
    int retorno = 0;
    char name[32],surname[32];
    int age;
    int i=0;
    char seguir = 's';

    do
    {
        if(i<array);
        {
            printf("Ingrese nombre: ");
            scanf("%s",name);

            printf("Ingrese apellido: ");
            scanf("%s",surname);

            printf("Ingrese edad: ");
            scanf("%d",&age);

            strcpy(pPersona[i].name,name);
            strcpy(pPersona[i].surname,surname);
            pPersona[i].age = age;
            pPersona[i].estado = ALTA;
            i++;
            printf("Desea seguir ingresando numeros?");
            fflush(stdin);
            scanf("%c",&seguir);
        }
        retorno = i;

    }while(seguir=='s');
    return retorno;
}
