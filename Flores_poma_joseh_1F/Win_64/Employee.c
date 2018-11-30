#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Employee.h"

Employee* employee_new()
{
    Employee *nuevoEmpleado;

    nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char *sueldoStr)
{
    Employee *nuevoEmpleado;
    nuevoEmpleado = employee_new();

    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;

    auxId = atoi(idStr);
    auxHorasTrabajadas = atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldoStr);

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setId(nuevoEmpleado, auxId);
        employee_setNombre(nuevoEmpleado, nombreStr);
        employee_setHorasTrabajadas(nuevoEmpleado, auxHorasTrabajadas);
        employee_setSueldo(nuevoEmpleado, auxSueldo);
    }

    return nuevoEmpleado;

}

void employee_delete(Employee *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this, int id)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        if(id > 0)
        {
            this->id = id;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_getId(Employee* this, int* id)
{
    int auxReturn = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int auxReturn = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int auxReturn = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int auxReturn = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_ordenarEmpleado(LinkedList* pArrayListEmployee)
{
    char opcion;
    int auxReturn = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\n---------SELECCION COMO QUIERE ORDENAR LA LISTA--------\n\n");
        printf("1 - Ordenar por NOMBRE. \n");
        printf("2 - Ordenar por SALARIO. \n");
        printf("3 - Ordenar HORAS TRABAJADAS. \n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            printf("\nOrdenando los datos...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
            break;
        case '2':
            printf("\nOrdenando los datos...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
            break;
        case '3':
            printf("\nOrdenando los datos...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
            break;
        default:
            printf("\nopcion no valida.");

        }

        auxReturn = 0;
    }

    return auxReturn;
}

int employee_ordenarPorSueldo(void* var1, void* var2)
{
    int sueldo1;
    int sueldo2;
    int auxReturn = 0;

    employee_getSueldo(var1, &sueldo1);
    employee_getSueldo(var2, &sueldo2);

    if(sueldo1 > sueldo2)
    {
        auxReturn = 1;
    }
    else if(sueldo1 < sueldo2)
    {
        auxReturn = -1;
    }

    return auxReturn;
}


int employee_ordenarPorNombre(void* var1, void* var2)
{
    char nombre1[50];
    char nombre2[50];
    int auxReturn = 0;

    employee_getNombre(var1, nombre1);
    employee_getNombre(var2, nombre2);

    if(strcmp(nombre1, nombre2) > 0)
    {
        auxReturn = 1;
    }
    else if(strcmp(nombre1, nombre2) < 0)
    {
        auxReturn = -1;
    }

    return auxReturn;
}

int employee_ordenarPorHoras(void* var1, void* var2)
{
    int horas1;
    int horas2;
    int auxReturn = 0;

    employee_getHorasTrabajadas(var1, &horas1);
    employee_getHorasTrabajadas(var2, &horas2);

    if(horas1 > horas2)
    {
        auxReturn = 1;
    }
    else if(horas1 < horas2)
    {
        auxReturn = -1;
    }

    return auxReturn;
}

