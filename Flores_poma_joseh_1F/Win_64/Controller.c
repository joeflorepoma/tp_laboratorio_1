#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    FILE *pArchivo;

    pArchivo = fopen(path, "r");

    if(pArchivo != NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        auxReturn = 1;
    }

    fclose(pArchivo);
    return auxReturn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    FILE *pArchivo;

    pArchivo = fopen(path, "rb");

    if(pArchivo != NULL)
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        auxReturn = 1;
    }

    fclose(pArchivo);
    return auxReturn;
}

int controller_siguienteId(LinkedList* pArrayListEmployee)
{
    int id = 0;
    int idAnterior;
    int intAuxiliar;
    Employee* pEmpleado;
    int listCant;
    int i;

    if(pArrayListEmployee != NULL)
    {
        listCant = ll_len(pArrayListEmployee);
        if(listCant > 0)
        {
            for(i = 0; i<listCant; i++)
            {
                pEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado,&intAuxiliar);
                if(intAuxiliar > id)
                {
                    idAnterior = id;
                    id = intAuxiliar;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;

        }
        else
        {
            id = 1;
        }
    }
    return id;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;
    int auxReturn = -1;

    int auxId;
    char auxNombre[50];
    char auxSueldoStr[50];
    int auxSueldo;
    char auxHorasStr[50];
    int auxHoras;

    pEmpleado = employee_new();

    if(pArrayListEmployee != NULL)
    {
        auxId = controller_siguienteId(pArrayListEmployee);

        printf("Ingrese un nuevo nombre: \n");
        fflush(stdin);
        gets(auxNombre);

        while(isOnlyLetters(auxNombre) == 0)
        {
            printf("Ingrese solo letras, Intente nuevamente...\n");
            fflush(stdin);
            gets(auxNombre);
        }
        stringToUpper(auxNombre);

        printf("Ingrese un nuevo salario: \n");
        fflush(stdin);
        gets(auxSueldoStr);

        while(isNumeric(auxSueldoStr) == 0)
        {
            printf("Ingrese solo numeros, Intente nuevamente...\n");
            fflush(stdin);
            gets(auxSueldoStr);
        }
        auxSueldo = atoi(auxSueldoStr);

        printf("Ingrese las horas: \n");
        fflush(stdin);
        gets(auxHorasStr);

        while(isNumeric(auxHorasStr) == 0)
        {
            printf("Ingrese solo numeros, Intente nuevamente...\n");
            fflush(stdin);
            gets(auxHorasStr);
        }
        auxHoras = atoi(auxHorasStr);

        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, auxId);
            employee_setNombre(pEmpleado, auxNombre);
            employee_setSueldo(pEmpleado, auxSueldo);
            employee_setHorasTrabajadas(pEmpleado, auxHoras);
            ll_add(pArrayListEmployee, pEmpleado);
            auxReturn = 0;
        }

    }

    return auxReturn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;

    int auxReturn = -1;
    int i;

    char auxIdStr[10];
    int auxId;
    int busquedaId;

    char opcionStr[50];
    int auxOpcion;

    char auxNombre[50];

    char auxSueldoStr[50];
    int auxSueldo;

    char auxHorasStr[50];
    int auxHoras;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID: \n");
        fflush(stdin);
        gets(auxIdStr);

        while(isNumeric(auxIdStr))
        {
            printf("Ingrese solo numeros, Intentelo de nuevo...\n");
            fflush(stdin);
            gets(auxIdStr);
        }
        auxId = atoi(auxIdStr);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado, &busquedaId);

            if(busquedaId == auxId)
            {
                printf("\nSeleccion que campo quiere editar: \n\n");
                printf("1 - Nombre: \n");
                printf("2- Salario: \n");
                printf("3- Horas de trabajo: \n\n");

                fflush(stdin);
                gets(opcionStr);

                while(isNumeric(opcionStr) == 0)
                {
                    printf("Ingrese solo numeros, Intentelo de nuevo...\n");
                    fflush(stdin);
                    gets(opcionStr);
                }
                auxOpcion = atoi(opcionStr);

                switch(auxOpcion)
                {
                case 1:
                    printf("Ingrese un nuevo nombre: \n");
                    fflush(stdin);
                    gets(auxNombre);

                    while(isOnlyLetters(auxNombre) == 0)
                    {
                        printf("Ingrese solo letras, Intente nuevamente...\n");
                        fflush(stdin);
                        gets(auxNombre);
                    }
                    stringToUpper(auxNombre);
                    auxReturn = 0;
                    employee_setNombre(pEmpleado, auxNombre);
                    break;
                case 2:
                    printf("Ingrese un nuevo salario: \n");
                    fflush(stdin);
                    gets(auxSueldoStr);

                    while(isNumeric(auxSueldoStr) == 0)
                    {
                        printf("Ingrese solo numeros, Intente nuevamente...\n");
                        fflush(stdin);
                        gets(auxSueldoStr);
                    }
                    auxSueldo = atoi(auxSueldoStr);
                    auxReturn = 0;
                    employee_setSueldo(pEmpleado, auxSueldo);
                    break;

                case 3:
                    printf("Ingrese las horas: \n");
                    fflush(stdin);
                    gets(auxHorasStr);

                    while(isNumeric(auxHorasStr) == 0)
                    {
                        printf("Ingrese solo numeros, Intente nuevamente...\n");
                        fflush(stdin);
                        gets(auxHorasStr);
                    }
                    auxHoras = atoi(auxHorasStr);
                    auxReturn = 0;
                    employee_setHorasTrabajadas(pEmpleado, auxHoras);
                    break;

                default:
                    printf("\nIngrese una opcion valida.\n\n");
                }

            }
        }
    }

    return auxReturn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;

    int auxReturn = -1;
    char auxIdStr[10];
    int auxId;
    int busquedaId;

    int i;
    int contador = 0;
    int confirmar;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID: \n");
        fflush(stdin);
        gets(auxIdStr);

        while(isNumeric(auxIdStr))
        {
            printf("Ingrese solo numeros, Intentelo de nuevo...\n");
            fflush(stdin);
            gets(auxIdStr);
        }
        auxId = atoi(auxIdStr);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado, &busquedaId);

            if(busquedaId == auxId)
            {
                contador++;

                if(confirmar == 1)
                {
                    printf("\n¿Esta seguro de remover al empleado? (1 - confirmas)\n");
                    printf("1 - Si.\n");
                    printf("2 - No.\n");
                    scanf("%d", &confirmar);
                }
                else
                {
                    printf("\n¿Esta seguro de remover al empleado? (2 - confirmas)\n");
                    printf("1 - Si.\n");
                    printf("2 - No.\n");
                    scanf("%d", &confirmar);
                }

                switch(confirmar)
                {
                case 1:
                    employee_delete(pEmpleado);
                    ll_remove(pArrayListEmployee, i);
                    auxReturn = 0;
                    break;

                case 2:
                    auxReturn = -2;
                    break;

                default:
                    printf("\nIngrese una opcion valida.\n");
                    auxReturn = -2;
                    break;
                }
            }
        }
    }

    contador = 0;
    return auxReturn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;

    int auxReturn = -1;
    int i;

    char nombre[50];
    int id;
    int sueldo;
    int horas;

    if(pArrayListEmployee != NULL)
    {
        auxReturn = 0;
        printf("\n\nId  \t\t   NOMBRE \t\t SUELDO \t\tHORAS \n\n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getNombre(pEmpleado, nombre);
            employee_getId(pEmpleado, &id);
            employee_getSueldo(pEmpleado, &sueldo);
            employee_getHorasTrabajadas(pEmpleado, &horas);
            printf("\n");
            printf("%d -- %20s %20d %20d \n", id, nombre, sueldo, horas);
        }

    }

    return auxReturn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL)
    {
        employee_ordenarEmpleado(pArrayListEmployee);
        auxReturn = 0;
    }

    return auxReturn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmpleadoAux;

    int auxReturn = -1;
    int i;

    int* auxId;
    char* auxNombre;
    int* auxSalario;
    int* auxHoras;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        auxReturn = 1;
        auxId = malloc(sizeof(int));
        auxNombre = malloc(sizeof(char)*100);
        auxSalario = malloc(sizeof(int));
        auxHoras = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            pEmpleadoAux = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleadoAux,auxId);
            employee_getSueldo(pEmpleadoAux,auxSalario);
            employee_getNombre(pEmpleadoAux, auxNombre);
            employee_getHorasTrabajadas(pEmpleadoAux,auxHoras);
            fprintf(pArchivo,"%d,%s,%d,%d\n",*auxId,auxNombre,*auxSalario,*auxSalario);
        }

        free(auxNombre);
        free(auxId);
        free(auxSalario);
        free(auxHoras);
        fclose(pArchivo);
    }
    return auxReturn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmpleadoAux;

    int auxReturn = -1;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        auxReturn = 1;
        pArchivo = fopen(path,"wb");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmpleadoAux, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
    }
    return auxReturn;
}

