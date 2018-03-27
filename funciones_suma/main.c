#include <stdio.h>
#include <stdlib.h>

int suma (int num1, int num2);
int rta = 8;

int Boca = 12;

int main()
{
    int n1, n2, rta;
    printf("Ingrese un numero: ");
    scanf("%d",&n1);
    printf("Ingrese un numero: ");
    scanf("%d",&n2);

    rta = suma (n1, n2);
    printf("La suma es: %d",rta);
    return 0;

}

int suma (int num1, int num2)
{
    int rest;
    rest = num1 + num2;
    return rest;
}
