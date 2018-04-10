#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre [12];
    char apellido [12];

    printf("\nIngrese nombre: ");
    fflush(stdin);
    scanf("%s[^\n]", nombre);

    printf("\nIngrese apellido: ");
    fflush(stdin);
    scanf("%s[^\n]", apellido);

    strlwr(nombre);
    strlwr(apellido);

    nombre[0] = toupper(nombre[0]);
    apellido[0] = toupper(apellido[0]);

    strcat(apellido, " ");
    strcat(apellido, nombre);

    printf("\nEl nombre completo es: %s", apellido);

    return 0;
}
