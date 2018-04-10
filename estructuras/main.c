#include <stdio.h>
#include <stdlib.h>


 int getInt (char mensaje[], char mensajeError[], int intentos, int maximo, int minimo);


int main()
{
    int info = getInt("Ingrese mensaje: ", "No es valido el mensaje!!", 1, 120, 1);

    return 0;
}

int getInt (char mensaje[], char mensajeError[], int intentos, int maximo, int minimo)
{
    int retorno = 0;

        do
        {
            printf("%s", mensaje);
            scanf("%d", &retorno);

            if (retorno < maximo && retorno >= minimo)
                {
                    break;
                }

            printf("%s", mensajeError);

            intentos--;
        }while (intentos > 0);

    return retorno;
}



