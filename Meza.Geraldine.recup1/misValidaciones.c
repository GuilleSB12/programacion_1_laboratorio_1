#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misValidaciones.h"

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int soloNumeros(char num[])
{
    int i=0;
    int retorno = 1;
    while(num[i] != '\0')
    {
         if(num[i]<'0' || num[i]> '9')
            retorno = 0;
        i++;
    }
     return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if((str[i]!= ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            retorno = 0;
        i++;
    }

    return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf (" %s",input);
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    int x;
    getString(mensaje,aux);
    if(soloLetras(aux))
    {
        x = strlen(aux);
        strncpy(input,aux,x);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[255];
    getString(mensaje,aux);
    if(soloNumeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

