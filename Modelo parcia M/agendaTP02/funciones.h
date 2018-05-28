#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
        char nUsuario[20];
        char password[9];
        int idUsuario;
        int cantVentas;
        int estado;
}eUsuario;

typedef struct{
        int idProducto;
        int idU;
        char nombre[30];
        float precio;
        int stock;
        int cantVendida;
        int estado;
}eProd;
/*
typedef struct{
        char nUser[20];
        int idProd;
}eAux;
*/
typedef struct{
        int idUsuario;
        int idProducto;
        int calificacion;
        int estado;
}eVenta;


int menu();
int menuModificar();
int menuModPubUsu();
void inicioEstados(eUsuario variable[],eProd var[],eVenta vari[],int CANT,int MAX);
int buscarEspacio(eUsuario variable[],int CANT);
int buscarEspacioV(eVenta vari[],int MAX);
int buscarUsuario(eUsuario variable[],char codigo[],int CANT);

void mostrarUsuario(eUsuario variable);
/*void ordenar(eUsuario variable[],int CANT);*/

//opciones del menu
void alta(eUsuario variable[],int CANT);
void baja(eUsuario variable[],int CANT);
void publicarProd(eUsuario variable[],eProd var[],int CANT,int MAX);
void modPublicacion(eUsuario variable[],eProd var[],int CANT);
void cancelPub(eUsuario variable[],eProd var[],int CANT);
void modificarUsu(eUsuario variable[],int CANT);
void comprarPro(eUsuario variable[],eProd var[],eVenta vari[],int CANT,int MAX);
void listarUsu(eUsuario variable[],int CANT);
void listarPub(eProd var[],int MAX);
void listarPubUsu(eUsuario variable[],eProd var[],eVenta vari[],int codigo,int CANT,int MAX);
void mostrarProducto(eProd var);
void mostrarProductos(eProd var[],int MAX);



/*void grafico(eUsuario variable[],int CANT);*/




#endif // FUNCIONES_H_INCLUDED

