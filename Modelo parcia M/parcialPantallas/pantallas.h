#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED

typedef struct{
        int id;
        float precio;
        int estado;
        char tipo[4];
        char videoNombre[51];
}ePantalla;

typedef struct{
        int idPan;
        int cuitCli;
}eAux;

//inicializa las estructuras pantalla con estado=0
void inicioEstados(ePantalla variable[],int cantidad);
int menu();
int menuModificar();
void altaPatanalla(ePantalla variable[],int cantidad);
void bajaPantalla(ePantalla variable[],int cantidad);
//busca un espacio disponible y retorna el entero del indice libre
int buscarIndice(ePantalla variable[],int cantidad);
//la funcion toma un codigo y si una pantalla (con indice 1) tiene el mismo id, se retorna el indice, sino (-1)
int buscarPantallaId(ePantalla variable[],int codigo,int CANT);
//Muestra una sola pantalla seleccionada
void mostrarPantalla(ePantalla variable[]);
void mostrarPantallas(ePantalla variable[]);


#endif // PANTALLAS_H_INCLUDED
