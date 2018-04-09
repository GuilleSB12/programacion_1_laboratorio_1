#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char palabra[20];

    printf("\nIngrese un texto: ");
    fflush(stdin);
    scanf("%s", palabra);

    printf("Dale Boca %s", palabra);

    return 0;

}

