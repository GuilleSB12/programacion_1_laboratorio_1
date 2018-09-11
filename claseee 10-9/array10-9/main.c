#include <stdio.h>
#include <stdlib.h>

void mostrar ( char vec[], int TAM);

void ordenar ( char vec[], int TAM);

int main()
{

     char letras[] = {'d', 'c', 'a', 'f', 'A', 'C', 'z', 'Z' };

     mostrar (letras, 8);

     ordenar (letras, 8);

     mostrar (letras, 8);


     return 0;

}

void mostrar( char vec[], int TAM)
{
    for (int i=0; i<TAM; i++)
    {
        printf( " %c ", vec[i]);
    }

    printf("\n\n");

}

void ordenar ( char vec[], int TAM)
{
    char aux;


    for ( int i = 0; i < TAM -1; i++ )
    {
        for ( int j = i + 1; j < TAM; j++)
        {
            if ( vec[i] > vec[j]  )
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}
