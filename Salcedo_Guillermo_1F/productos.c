#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validaciones.h"

void inicializarProducto(EProducto vec[], int CANT)
{
    int i;

    for(i=0; i < CANT; i++)
        {
            vec[i].estado = 1;
        }
}


int buscarLibre(EProducto vec[], int CANT)
{
    int indice = -1;
    int i;

    for(i=0; i < CANT; i++)
    {
        if(vec[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarproducto (EProducto vec[], int CANT, int codigoProd)
{
    int indice = -1;
    int i;

    for(i=0; i < CANT; i++)
    {
        if(vec[i].estado == 0 && vec[i].codigoProd == codigoProd)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void mostrarProducto (EProducto vec)
{
    printf("  %d     %s     %d     %d \n", vec.codigoProd, vec.descripcion, vec.importe, vec.cantidad);
}


/*void mostrarProductos(EProducto vec[], int CANT)
{

    system("cls");

    printf("---Lista---\n\n");
    //printf("  DNI  Nombre  Edad  \n\n");

    fflush(stdin);

    EPersona aux;
    int i;
    int j;
    int flag = 0;

    for(i=1; i < CANT; i++)
    {

        for(j = CANT-1; j >= i; j--)
          {
             if(strcmp(persona[j-1].nombre, persona[j].nombre) > 0)
                {
                  aux = persona[j];
                  persona[j] = persona[j-1];
                  persona[j-1] = aux;
                  flag = 1;

                }

                fflush(stdin);
         }

         if (flag == 0)
            {
                break;
            }

    }


    for(i=0; i < CANT; i++)
        {
            if(persona[i].estado == 0)
            {
                //printf("%s\n", persona[i].nombre);
                mostrarPersona(persona[i]);
                fflush(stdin);
            }


        }

    printf("\n");

}*/




void alta(EProducto vec[], int CANT)
{
    EProducto nuevavec;
    int codigoProd;
    char descripcion [50];
    int estado;
    int importe;
    int cantidad;
    int indice;
    char auxCP[20];
    char auxCant[20];
    char auxDescr[50];
    char auxImp[120];


    system("cls");
    printf("---Alta---\n\n");

    indice = buscarLibre(vec, CANT);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta el producto.\n\n");
    }

    else
    {
        printf("Ingrese codigo del producto: ");
        scanf("%s", auxCP);


            while ( (esNumerico(auxCP) == 0))
            {
                printf("Error! Codigo Incorrecto, ingrese solo numeros!\n");
                printf("Ingrese codigo: ");
                scanf("%s", auxCP);
                fflush(stdin);
            }


        codigoProd = atoi(auxCP);

        estado = buscarproducto(vec, CANT, codigoProd);

        if(estado != -1)
            {
                printf("\nEl codigo %d ya esta dado de alta en el sistema.\n", codigoProd);
                mostrarProducto (vec[estado]);

                printf("\n");
            }

        else
            {
                   nuevavec.estado = 0;
                   nuevavec.codigoProd = codigoProd;

                   printf("Ingrese descripcion: ");
                   fflush(stdin);
                   gets(nuevavec.descripcion);
                   strcpy( auxDescr, nuevavec.descripcion);


                   while ( esSoloLetras(auxDescr) == 0 )
                   {
                       printf("Error!! Ingrese solo letras!\n");
                       printf("Ingrese descripcion: ");
                       scanf("%s", auxDescr);
                       fflush(stdin);

                   }

                   strcpy( nuevavec.descripcion, auxDescr);

                   printf("Ingrese importe: ");
                   scanf("%s", auxImp);
                   fflush(stdin);


                   while ( esNumerico(auxImp) == 0 )
                   {
                       printf("Error!! Importe incorrecto, ingrese numeros!!\n");
                       printf("Ingrese importe : ");
                       fflush(stdin);
                       scanf("%s", auxImp);
                   }

                   importe = atoi(auxImp);
                   nuevavec.importe = importe;

                   printf("Ingrese cantidad: ");
                   scanf("%s", auxCant);
                   fflush(stdin);

                   while ( esNumerico(auxCant) == 0 )
                   {
                       printf("Error!! Ingrese numeros!!\n");
                       printf("Ingrese cantidad : ");
                       fflush(stdin);
                       scanf("%s", auxCant);
                   }

                   cantidad = atoi(auxCant);
                   nuevavec.cantidad = cantidad;




                   vec[indice] = nuevavec;

                   printf("\nAlta exitosa!!!\n\n");

           }

    }

}

void modificar (EProducto vec[], int CANT)
{
    EProducto nuevavec;
    int codigoProd;
    int estado;
    int indice;
    char confirma;
    char seguir = 's';
    int opcion;
    char descripcion [50];
    int importe;
    int cantidad;
    char auxCant[20];
    char auxDescr[50];
    char auxImp[120];

    system("cls");
    printf("---Modificar productos---\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &codigoProd);

    estado = buscarproducto (vec, CANT, codigoProd);

        if(estado == -1)
        {
            printf("\nError! EL codigo no se encuentra en el sistema!\n\n");
        }

        else
        {

            mostrarProducto(vec[estado]);

            do {

                printf("\nConfirma? [s|n]: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);

                }while(confirma != 's' && confirma != 'n');



            if ( confirma == 's' )
            {

            //vec[estado].estado = 1;

             //while ( seguir == 's' )
             {
                switch ( opcion )
                {

                   case 1:
                   printf("Ingrese descripcion: ");
                   fflush(stdin);
                   gets(nuevavec.descripcion);
                   strcpy (auxDescr, nuevavec.descripcion);


                   while ( esSoloLetras(auxDescr) == 0 )
                   {
                       printf("Error!! Ingrese solo letras!\n");
                       printf("Ingrese descripcion: ");
                       scanf("%s", auxDescr);
                       fflush(stdin);

                   }

                   strcpy( nuevavec.descripcion, auxDescr);
                   break;



                   case 2:
                   printf("Ingrese importe: ");
                   scanf("%s", auxImp);
                   fflush(stdin);


                   while ( esNumerico(auxImp) == 0 )
                   {
                       printf("Error!! Importe incorrecto, ingrese numeros!!\n");
                       printf("Ingrese importe : ");
                       fflush(stdin);
                       scanf("%s", auxImp);
                   }

                   importe = atoi(auxImp);
                   nuevavec.importe = importe;
                   break;


                   case 3:
                   printf("Ingrese cantidad: ");
                   scanf("%s", auxCant);
                   fflush(stdin);

                   while ( esNumerico(auxCant) == 0 )
                   {
                       printf("Error!! Ingrese numeros!!\n");
                       printf("Ingrese cantidad : ");
                       fflush(stdin);
                       scanf("%s", auxCant);
                   }

                   cantidad = atoi(auxCant);
                   nuevavec.cantidad = cantidad;
                   break;



                   /*case 4:
                   seguir =  'n';
                   break;

                   default:
                   printf("\nOpcion incorrecta!! Ingrese opcion entre 1 y 5!");*/




                   vec[indice] = nuevavec;

                   printf("\nModificacion exitosa!!!\n\n");



                }

             }

            }



        else
            {
                printf("\nSe ha cancelado la modificacion.\n\n");
            }

        }



}



void baja(EProducto vec[], int CANT)
{
    char confirma;
    int estado;
    int codigoProd;
    char auxCP[20];

    system("cls");
    printf("---Baja---\n\n");

    printf("Ingrese codigo del producto: ");
    scanf("%s", auxCP);


        while ( (esNumerico(auxCP) == 0))
            {
                printf("Error! Codigo Incorrecto, ingrese solo numeros!\n");
                printf("Ingrese codigo: ");
                scanf("%s", auxCP);
                fflush(stdin);
            }


        codigoProd = atoi(auxCP);

    estado = buscarproducto(vec, CANT, codigoProd);

        if(estado == -1)
        {
            printf("\nEl codigo %d no se encuentra en el sistema!!\n\n", codigoProd);
        }

        else
        {
            mostrarProducto (vec[estado]);

            do {

                printf("\nConfirma baja? [s|n]: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);

                }while(confirma != 's' && confirma != 'n');

            if (confirma == 's')
                {
                    vec[estado].estado = 1;
                    printf("\nSe ha realizado la baja!!\n\n");
                }

            else
            {
                printf("\nSe ha cancelado la baja!\n\n");
            }

        }

}


void informar (EProducto vec[], int CANT)
{


}

void listar (EProducto vec[], int CANT)
{


}
