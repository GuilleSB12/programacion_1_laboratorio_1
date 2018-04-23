#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char descripcion[51];
    float precio;
    int cantidad;
    int estado;
}EProducto;

int main()
{
    printf("Un dato del tipo char ocupa %d bytes\n\n", sizeof(char));
    printf("Un dato del tipo int ocupa %d bytes\n\n", sizeof(int));
    printf("Un dato del tipo float ocupa %d bytes\n\n", sizeof(float));
    printf("Un dato del tipo double ocupa %d bytes\n\n", sizeof(double));
    printf("Un dato del tipo void ocupa %d bytes\n\n", sizeof(void));
    printf("Un dato del tipo EProducto ocupa %d bytes\n\n", sizeof(EProducto));

    return 0;
}
