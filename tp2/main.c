#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#include "utn.h"

#define CANT 1000
#define ESC 27

int main()
{
    eEmpleado empleados[CANT];

    int auxId = 0;
    char auxNombre[51];
    char auxApellido[51];
    float auxSueldo = 0;
    int auxSector = 0;

    inicializar(empleados, CANT);


    char opcion;

    do
    {
        system("cls");
        printf("\n-------\tABM EMPLEADOS\t-------\n");
        printf("\n1.- Alta Empleado: \n2.- Modificacion Empleado: \n3.- Baja Empleado: \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':

            ingresoEmpleado(empleados, CANT, auxId, auxNombre, auxApellido, auxSueldo, auxSector);

            break;
        case '2':

            modificarEmpleado(empleados, CANT, auxId, auxNombre, auxApellido, auxSueldo, auxSector);

            break;
        case '3':

            bajaEmpleado(empleados, CANT, auxId);

            break;
        case '4':

            listarPromTotal(empleados, CANT);

            break;
        case ESC:
            system("cls");
            printf("\n\nPrograma finalizado.\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }while(opcion != ESC);
    return 0;
}
