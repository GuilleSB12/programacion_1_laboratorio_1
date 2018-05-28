#ifndef LIBRERIAS_H_INCLUDED
#define LIBRERIAS_H_INCLUDED

typedef struct
{
        int id;
        char nombre[20];
        int estado;
}eEstructura1;

typedef struct{
        int idE1;
        int idE2;
        char nombre[20];
        int estado;
}eEstructura2;

typedef struct{
        int id1;
        int id2;
        int estado;
}eEstructura3;

void inicioEstados(eEstructura1 variable[],eEstructura2 var[],eEstructura3[],int CANT,int MAX);
int buscarIndice1(eEstructura1 variable[],int CANT);
int buscarIndice2(eEstructura2 var[],int MAX);
int buscarIndice3(eEstructura3 vari[],int MAX);
//MENU
int menu();
int menuModificar1();
int menuModificar2();
//MOSTAR 1
void mostrarE1(eEstructura1 variable);
void mostrarE2(eEstructura2 var);
//ENCONTRAR E
int encontrarE1(eEstructura1 variable[],int codigo,int CANT);
int encontrarE2(eEstructura2 var[],int codigo,int MAX);
int encontrarE3(eEstructura3 vari[],int codigo,int MAX);
//MOSTRAR +1
void listarEe1(eEstructura1 variable[],int CANT);
void listarEe2(eEstructura2 var[],int MAX);
//ALTA-BAJA-MODIFICACION E1
void altaE1(eEstructura1 variable[],int CANT);
void bajaE1(eEstructura1 variable[],int CANT);
void modificarE1(eEstructura1 variable[],int CANT);
//ALTA-BAJA-MODIFICACION E2
void altaE2(eEstructura1 variable[],eEstructura2 var[],int CANT,int MAX);
void modificarE2(eEstructura1 variable[],eEstructura2 var[],int CANT,int MAX);
void bajaE2(eEstructura1 variable[],eEstructura2 var[],int CANT,int MAX);
//COMPRAR()
void
//ORDENAR
void ordenarE1Nombre(eEstructura1 variable[],int CANT);
void ordenarE1Numero(eEstructura1 variable[],int CANT);
void ordenarE2Nombre(eEstructura2 var[],int MAX);
void ordenarE2Numero(eEstructura2 var[],int MAX);
//VALIDAR NUMERO
int getIntEntreMinMax(char mensaje[],int maximo, int minimo, int *respuesta);

#endif // LIBRERIAS_H_INCLUDED
