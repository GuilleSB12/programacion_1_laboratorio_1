#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;

} eEmpleado;



int menu();
void inicializarEmpleados(eEmpleado[], int);
void mostrarEmpleados(eEmpleado[], int);
void mostrarEmpleado(eEmpleado);
int buscarLibre(eEmpleado[], int);
int buscarEmpleado(eEmpleado[], int, int);
void bajaEmpleado(eEmpleado[], int);
void modifica (eEmpleado[], int);

#endif // FUNCIONES_H_INCLUDED

