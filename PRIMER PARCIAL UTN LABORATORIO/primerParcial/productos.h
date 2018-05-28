#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED


typedef struct{
        int codigo;
        int codigoProv;
        char descripcion[50];
        float importe;
        int cantidad;
        int estado;
}eProducto;

typedef struct{
        int codigo;
        char descripcion[50];
        int estado;
}eProveedor;

void mostrarProve(eProveedor var[],int MAXP);
void hardCode(eProveedor[]);

void inicioEstados(eProducto variable[],int CANT);
int buscarIndice(eProducto variable[],int CANT);
//MUESTRA UN SOLO PRODUCTO
void mostrarProd(eProducto variable);
//ENCUENTRA UN PRODUCTO
int encontrarProd(eProducto variable[],int codigo,int CANT);
//LISTA TODOS LOS PRODUCTOS
void listarProductos(eProducto variable[],int CANT);
//ABM
void altaProd(eProducto variable[],int CANT);
void bajaProd(eProducto variable[],int CANT);
void modificarProd(eProducto variable[],int CANT);
//ORDENAR ESTRUCTURAS
void ordenarNombre(eProducto variable[],int CANT);
//INFORMAR
void informar(eProducto variable[],int CANT);
void informarTPS(eProducto variable[],int CANT);
void informarTPB(eProducto variable[],int CANT);
void informarSM(eProducto variable[],int CANT);
void informarSB(eProducto variable[],int CANT);
//LISTAR
void listar(eProducto variable[],eProveedor var[],int CANT,int MAXP);
void listarProSobre10(variable,CANT);
void listarProBajo10(variable,CANT);


#endif // PRODUCTOS_H_INCLUDED
