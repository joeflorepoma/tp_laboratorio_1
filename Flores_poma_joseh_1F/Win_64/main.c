#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ESC 27

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char opcion;
    int validarRetorno;

    int validarTextoAbierto = 1;
    int validarTextoGuardado = 0;

    int validarBinarioAbierto = 1;
    int validarBinarioGuardado = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();


    system("pause");
    system("cls");

    do
    {
        printf("-------TRABAJO PRACTICO NUMERO #3-------");

        printf("\n\n");
        printf("1 - Cargar lista de empleados desde data.csv (Texto).\n");
        printf("2 - Cargar lista de empleados desde data.bin (Binario).\n");
        printf("3 - Agregar nuevo empleado.\n");
        printf("4 - Editar empleado.\n");
        printf("5 - Eliminar empleado.\n");
        printf("6 - Listar empleado.\n");
        printf("7 - Ordenar empleado.\n");
        printf("8 - Guardar lista de empleados en data.csv (Texto).\n");
        printf("9 - Guardar lista de empleados en data.csv (Binario).\n");
        printf("ESC - para Salir.\n");
        printf("\n");
        printf("\n\n");

        opcion = getch();
        switch(opcion)
        {
        case '1':
            if(validarTextoAbierto == 1)
            {
                validarRetorno = controller_loadFromText("data.csv",listaEmpleados);

                if(validarRetorno == 1)
                {
                    printf("\n-----Archivo abierto.\n\n");
                }
                else
                {
                    printf("\nError al abrir el archivo.\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\nYa se abrio ese archivo. texto!!\n\n");
            }
            validarTextoGuardado = 1;
            validarTextoAbierto++;
            break;

        case '2':
            if(validarBinarioAbierto == 1)
            {
                validarRetorno = controller_loadFromBinary("data.csv",listaEmpleados);

                if(validarRetorno == 1)
                {
                    printf("\n-----Archivo abierto.\n\n");
                }
                else
                {
                    printf("\nError al abrir el archivo.\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\nYa se abrio ese archivo. binario!!\n\n");
            }
            validarBinarioGuardado = 1;
            validarBinarioAbierto++;
            break;

        case '3':
            validarRetorno = controller_addEmployee(listaEmpleados);
            if(validarRetorno == 0)
            {
                system("cls");
                printf("\nSe agrego al empleado!\n\n");
            }
            else
            {
                printf("\nNo se agrego al empleado!\n\n");
            }
            break;

        case '4':
            controller_ListEmployee(listaEmpleados);
            validarRetorno = controller_editEmployee(listaEmpleados);
            if (validarRetorno == -1)
            {
                system("cls");
                printf("\nEl ID no existe.\n\n");
            }
            else
            {
                system("cls");
                printf("\nSe modifico con exito\n\n");
            }
            break;

        case '5':
            controller_ListEmployee(listaEmpleados);
            validarRetorno = controller_removeEmployee(listaEmpleados);
            if (validarRetorno == -1)
            {
                system("cls");
                printf("\n El ID no existe.\n\n");
            }
            else if (validarRetorno == -2)
            {
                system("cls");
                printf("\nSe ha cancelado la baja.\n\n");
            }
            else
            {
                system("cls");
                printf("\nEmpleado borrado!\n\n");
            }
            break;
        case '6':
            validarRetorno = controller_ListEmployee(listaEmpleados);
            if (validarRetorno == -1)
            {
                printf("\nNo se encontro la lista.\n\n");
            }
            else
            {
                printf("\nAqui esta la lista!\n\n");
            }
            break;
        case '7':
            validarRetorno = controller_sortEmployee(listaEmpleados);
            if (validarRetorno == -1)
            {
                printf("\nNo se encontro la lista.\n\n");
            }
            else
            {
                printf("\nLa lista esta ordenada!\n\n");
            }
            break;
        case '8':
            if (validarTextoGuardado == 1)
            {
                validarRetorno = controller_saveAsText("data.csv",listaEmpleados);
                if(validarRetorno == 1)
                {
                    printf("\nArchivo guardado.\n\n");
                }
                else
                {
                    printf("\nNo se ha podido guardar el archivo\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\nNecesita abrir primero el archivo. texto!!\n\n");
            }
            break;
        case '9':
            if (validarBinarioGuardado == 1)
            {
                validarRetorno = controller_saveAsBinary("data.bin",listaEmpleados);
                if(validarRetorno == 1)
                {
                    printf("\nArchivo guardado.\n\n");
                }
                else
                {
                    printf("\nNo se ha podido guardar el archivo\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\nNecesita abrir primero el archivo. binario!!\n\n");
            }
            break;
        case ESC:
            printf("\nSalio del programa.\n\n");
            break;
        default:
            printf("\nIngreso una opcion no valida, Ingrese de nuevo...\n\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion != ESC);
    return 0;
}
