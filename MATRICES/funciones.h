#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void alta(EProducto prod[]);

typedef struct
{
    char descripcion[50];
    int cantidad;
    float importe;
    int codigo;
    int estado;

}EProducto;

/*typedef struct
{
    char descripcion[50];
    int cantidad;
    float importe;
    int estado;

}EModificar;*/



#endif // FUNCIONES_H_INCLUDED
