#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;

    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];

    int auxReturn = -1;

    int flag = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                flag = 0;
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            printf("%s - %s - %s - %s\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

            pEmpleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    Employee *pEmpleado;

    if(pFile != NULL)
    {
        auxReturn = 0;

        while(!feof(pFile))
        {
            pEmpleado = employee_new();

            fread(pEmpleado, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployee, pEmpleado);
        }
    }

    return auxReturn;
}
