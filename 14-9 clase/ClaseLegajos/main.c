#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 1

void ordenar ( int leg[], char nombres[][20], int pp[], int sp[], float prom[], int tam );

int main()
{
    int legajos[tam];
    int pp[tam];
    int sp[tam];
    float promedios[tam];
    char nombre[tam][20];

    for ( int i = 0; i < tam; i++ )
    {
        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &legajos[i]);

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("\nIngrese primera nota: ");
        fflush(stdin);
        scanf("%d", &pp[i]);

        printf("\nIngrese segunda nota: ");
        fflush(stdin);
        scanf("%d", &sp[i]);

       promedios[i] = ( pp[i] + sp[i] ) / 2.;

    }

    for ( int i = 0; i < tam; i++ )
    {
        printf("\nLegajo  Nombre  1parcial  2parcial  promedio\n");

        printf("\n%4d  %8s  %8d  %8d  %6.2f\n", legajos[i], nombre[i], pp[i], sp[i], promedios[i]);
    }

    printf("\n\n");

    ordenar( legajos, nombre, pp, sp, promedios, tam);

    for ( int i = 0; i < tam; i++ )
    {
        printf("\nLegajo  Nombre  1parcial  2parcial  promedio\n");

        printf("\n%4d  %8s  %8d  %8d  %6.2f\n", legajos[i], nombre[i], pp[i], sp[i], promedios[i]);
    }

    printf("\n\n");



    return 0;
}

void ordenar ( int leg[], char nombres[][20], int pp[], int sp[], float prom[], int tam)
{
    int i;
    int j;
    char auxcad;
    char aux;



}
