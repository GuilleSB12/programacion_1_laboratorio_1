#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
        int cuit;
        char descripcion[51];
        int estado;
}eCliente;

int menuContratar();
void contratarPantalla(ePantalla variable[],int cantidad);
int menuModContrato();
void modificarContrato(ePantalla variable[],int cantidad);
void mostrarCliente(eCliente variable[]);



#endif // CLIENTES_H_INCLUDED
