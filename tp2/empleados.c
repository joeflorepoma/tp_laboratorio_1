#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#include "empleados.h"
#include "utn.h"

/** \brief Inicializa el estado en un array de empleados
 * \param empleado el array donde hay que buscar
 * \param cantidad la longitud del array
 * \return devuelve void
 */

void inicializar( eEmpleado empleado[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        empleado[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param empleado el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibre(eEmpleado empleado[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(empleado[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param empleado Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param codigo Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */


int buscarEmpleadoPorId(eEmpleado empleado[], int cantidad, int identificacion)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(empleado[i].estado == 1 && empleado[i].id == identificacion)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

/** \brief funcion para mostrar un solo empleado
 * \param empleado es el array donde buscara al empleado
 * \return no devuelve nada
 */

void mostrarUnEmpleado(eEmpleado empleado)
{
    printf("\n | %6d  | %13s | %13s | %6.2f | %6d |\n", empleado.id, empleado.nombres, empleado.apellido, empleado.sueldo, empleado.sector );
}

/** \brief imprime los datos ingresados
 * \param empleado el array donde se buscara los datos
 * \param cantidad el numero de datos ingresados
 * \return no devuelve nada
 */

void mostrarEmpleados(eEmpleado empleado[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Empleados---\n\n");

    printf("\n | %6s  | %13s | %13s | %6s | %6s |\n", "Id", "Nombres", "Apellidos", "Salario", "Sector" );

    for(i=0; i < cantidad; i++)
    {
        if(empleado[i].estado != 0)
        {
            mostrarUnEmpleado(empleado[i]);
        }
    }

    system("pause");
}

/**
 * \brief Carga los valores de los empleados
 * \param empleado Es el array de empleados
 * \param espacioLibre Indica la posicion a setear
 * \param auxId  es el codigo del empleado
 * \param auxNombre nombre del empleado
 * \param auxApellido apellido del empleado
 * \param auxSector es el sector del empleado
 * \param auxSueldo es el sueldo del empleado
 * \return -
 */

void ingresoDatos(eEmpleado empleado[],int espacioLibre, int auxId,char auxNombre[],char auxApellido[], float auxSueldo,int auxSector)
{
    empleado[espacioLibre].id = auxId;
    strcpy(empleado[espacioLibre].nombres,auxNombre);
    strcpy(empleado[espacioLibre].apellido,auxApellido);
    empleado[espacioLibre].sueldo = auxSueldo;
    empleado[espacioLibre].sector = auxSector;
    empleado[espacioLibre].estado = 1;
}

/** \brief permite dar de alta a un empleado tomando datos
 * \param empleado en array donde se buscara
 * \param cantidad el numero de dato que se ingresara
 * \param identificacion el es codigo del empleado
 * \param nombre el nombre del empleado
 * \param apellido ingresara el apellido del empleado
 * \param sueldo es lo que ganara el empleado
 * \param sector el sector al cual pertenecera
 * \return no devuelve nada
 */

void ingresoEmpleado(eEmpleado empleado[], int cantidad, int identificacion, char nombre[], char apellido[], float sueldo, int sector)
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Empleados-----\t\n\n");


    espacioLibre = buscarEspacioLibre(empleado, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        identificacion = getValidInt("\nIngrese el Id. del empleado: \n", "\nIngrese solo numeros\n\n", 1, 10000);

        busqueda = buscarEmpleadoPorId(empleado, cantidad, identificacion);

        if(busqueda != -1)
        {
            printf("\nEl Id. del empleado ya existe.\n");
            printf("\n | %6s  | %13s | %13s | %6s | %6s |\n", "Id", "Nombres", "Apellidos", "Salario", "Sector" );
            mostrarUnEmpleado(empleado[busqueda]);

        }
        else
        {
            getValidString("Ingrese el nombre del empleado: \n", "\nIngrese solo caracteres.\n\n", nombre);
            getValidString("Ingrese el apellido del empleado: \n", "\nIngrese solo caracteres.\n\n", apellido);
            sueldo = getValidFloat("Ingrese el sueldo del empleado: \n", "\nIngrese numeros reales.\n\n");
            sector = getValidInt("Ingrese el sector del empleado: \n", "\nIngrese solo numeros\n\n", 1, 10000);

            ingresoDatos(empleado, espacioLibre, identificacion, nombre, apellido, sueldo, sector);

        }
    }

    system("pause");

}

/** \brief permite modificar a un empleado tomando datos
 * \param empleado en array donde se buscara
 * \param cantidad el numero de dato que se ingresara
 * \param identificacion el es codigo del empleado
 * \param nombre el nombre del empleado
 * \param apellido ingresara el apellido del empleado
 * \param sueldo es lo que ganara el empleado
 * \param sector el sector al cual pertenecera
 * \return no devuelve nada
 */

void modificarEmpleado(eEmpleado empleado[], int cantidad, int identificacion, char nombre[], char apellido[], float sueldo, int sector)
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Empleados-----\t\n\n");


    identificacion = getValidInt("\nIngrese el Id del empleado a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 10000);

    busqueda = buscarEmpleadoPorId(empleado, cantidad, identificacion);

    if(busqueda == -1)
    {
        printf("\nEl Id del empleado no se encuentra en la base de datos.\n");
    }
    else
    {
        getValidString("Re-ingrese el nombre del empleado: \n", "\nIngrese solo caracteres.\n\n", nombre);
        getValidString("Re-ingrese el apellido del empleado: \n", "\nIngrese solo caracteres.\n\n", apellido);
        sueldo = getValidFloat("Re-ingrese el sueldo del empleado: \n", "\nIngrese numeros reales.\n\n");
        sector = getValidInt("Re-ingrese el sector del empleado: \n", "\nIngrese solo numeros\n\n", 1, 10000);

        ingresoDatos(empleado, busqueda, identificacion, nombre, apellido, sueldo, sector);
    }

    system("pause");
}

/** \brief permite dar de baja a un empleado tomando datos
 * \param empleado en array donde se buscara
 * \param cantidad el numero de dato que se ingresara
 * \param identificacion el es codigo del empleado
 * \param nombre el nombre del empleado
 * \param apellido ingresara el apellido del empleado
 * \param sueldo es lo que ganara el empleado
 * \param sector el sector al cual pertenecera
 * \return no devuelve nada
 */

void bajaEmpleado(eEmpleado empleado[], int cantidad, int identificacion)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Empleados-----\t\n\n");

    identificacion = getValidInt("\nIngrese Id a dar de baja: \n", "Ingrese solo numeros.\n", 1, 10000);

    busqueda = buscarEmpleadoPorId(empleado, cantidad, identificacion);

    if(busqueda == -1)
    {
        printf("\n El Id. a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {
        printf("\n | %6s  | %13s | %13s | %6s | %6s |\n", "Id", "Nombres", "Apellidos", "Salario", "Sector" );
        mostrarUnEmpleado(empleado[busqueda]);

        do
        {
            printf("\n\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            empleado[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void listarPromTotal(eEmpleado empleado[], int cantidad)
{
    int i, j;
    float total = 0;
    float promedio = 0;
    int contador = 0;
    int contEmpleado = 0;

    eEmpleado auxEmpleado;

    for(i=0; i<cantidad-1; i++)
    {
        if(empleado[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(empleado[i].estado == 0)
            {
                continue;
            }
            if((strcmp(empleado[j].nombres, empleado[i].nombres))!=0)
            {
                if(strcmp(empleado[j].nombres, empleado[i].nombres)<0)
                {
                    auxEmpleado = empleado[j];
                    empleado[j] = empleado[i];
                    empleado[i] = auxEmpleado;
                }

            }
            else
            {
                if(empleado[j].sector>empleado[i].sector)
                {
                    auxEmpleado = empleado[j];
                    empleado[j] = empleado[i];
                    empleado[i] = auxEmpleado;
                }
            }

        }
    }

    for(i=0; i<cantidad; i++)
    {
        if(empleado[i].estado == 0)
        {
            continue;
        }

        total = total + empleado[i].sueldo;

        contador++;
    }

    promedio = total/contador;

    for(i=0; i<cantidad; i++)
    {
        if(empleado[i].estado == 0)
        {
            continue;
        }

        if(empleado[i].sueldo>promedio)
        {
            contEmpleado++;
        }
    }
    printf("\n | %6s  | %13s | %13s | %6s | %6s |\n", "Id", "Nombres", "Apellidos", "Salario", "Sector" );
    mostrarEmpleados(empleado, cantidad);
    printf("\n\t-----Los Datos de Sueldos de los Empleados-----\t\n\n");

    printf("\nEl salario total es de: %.2f pesos.\n", total);
    printf("El promedio de los salarios es de: %.2f pesos\n", promedio);
    printf("Los empleados que ganan un sueldo mayor al promedio son: %d\n\n", contEmpleado);

    system("pause");
}
