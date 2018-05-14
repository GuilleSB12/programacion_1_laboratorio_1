#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codigoProd;
    char descripcion [50];
    int importe;
    int cantidad;
    int estado;

}EProducto;

void alta (EProducto[], int CANT);
void inicializarProducto (EProducto vec[], int codigoProd);
void baja (EProducto[], int CANT);
int buscarproducto (EProducto[], int codigoProd, int CANT);
int buscarLibre (EProducto[], int codigoProd);
void modificar (EProducto[], int CANT);
void informar (EProducto[], int CANT);
void listar (EProducto[], int CANT);
void mostrarProducto (EProducto);
//void mostrarPersonas(EProducto vec[], int CANT);

#endif // FUNCIONES_H_INCLUDED
