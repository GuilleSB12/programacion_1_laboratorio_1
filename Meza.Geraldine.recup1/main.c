#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#define PERSONAS 5
int main()
{
    S_Persona people[PERSONAS];
    int i;
    int longitud;
    char apellido[32];

    longitud = agregarPersona(people,PERSONAS);

    FILE* pArchivo;

    pArchivo = fopen("bin.dat","wb");

    if(pArchivo != NULL)
    {

        for(i=0;i<PERSONAS;i++)
        {

            fwrite(people,sizeof(people),longitud, pArchivo);
        }
    }
    fclose(pArchivo);

    printf("Ingrese apellido: ");
    scanf("%s",apellido);
    pArchivo = fopen("bin.dat","rb");

    rewind(pArchivo);
    for(i=0;!feof(pArchivo);i++)
    {
        fscanf(pArchivo,apellido);

    }
    fclose(pArchivo);

    return 0;
}
