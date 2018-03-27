#include <stdio.h>
#include <stdlib.h>

 main()
{
    int i;
    int valor;
    int resultado = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &valor);

    for ( i = valor ; i > 0 ; i--)
    {
        resultado = resultado * i;
    }

    printf("Valor es: %d\nEl resultado es: %d ", valor, resultado);

    return ;



}
