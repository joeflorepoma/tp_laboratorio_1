#include "funciones.h"
#include "utn.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/** \brief solicita 2 operandos a y b para el menu
 * \param a sera el primer operando ingresado
 * \param b el segundo operando ingresado
 * \return no devuelve nada ya que solo mostrara el menu
 */

void menu(float a, float b)
{
    system("cls");
    printf("\n\t----CALCULADORA----\n");
    printf("\n\n1.- Ingrese 1er operando (A=%.2f): ", a);
    printf("\n2.- Ingrese 2do operando (B=%.2f): ", b);
    printf("\n3.- Calcular todas las operaciones: ");
    printf("\n4.- Informar resultados: ");
    printf("\nESC para salir...\n");
}

/** \brief funcion para guardar el primer operando y validara que solo se ingresen numeros
 * \return devuelve el dato ingresado por el usuario
 */
float primerOperando()
{
    system("cls");
    float x;
    char auxOperando1[50];
    if(!getStringNumerosFlotantes("Ingrese el primer operando: ", auxOperando1))
    {
        printf("\nIngrese solo numeros...\n");
        printf("\n");
    }

    x = atof(auxOperando1);
    system("pause");
    return x;
}

/** \brief funcion para guardar el segundo operando y validara que solo se ingresen numeros
 * \return devuelve el dato ingresado por el usuario
 */
float segundoOperando()
{
    system("cls");
    float y;
    char auxOperando2[50];
    if(!getStringNumerosFlotantes("Ingrese el segundo operando: ", auxOperando2))
    {
        printf("\nIngrese solo numeros...\n");
        printf("\n");
    }

    y = atof(auxOperando2);
    system("pause");
    return y;
}

/** \brief solicita 2 numeros al usuario y devuelve el resultado
 * \param a sera el primer operando ingresado
 * \param b sera el 2do operando ingresado
 * \return devolvera la suma de los 2 operandos
 */
float sumatoria(float a, float b)
{
    float suma;
    suma = a + b;

    return suma;

}

/** \brief solicita 2 numeros al usuario y devuelve el resultado
 * \param a sera el primer operando ingresado
 * \param b sera el 2do operando ingresado
 * \return devolvera la resta de los 2 operandos
 */
float restar(float a, float b)
{
    float resta;
    resta = a - b;

    return resta;
}

/** \brief solicita 2 numeros al usuario y devuelve el resultado
 * \param a sera el primer operando ingresado
 * \param b sera el 2do operando ingresado
 * \return devolvera la division de los 2 operandos, si el 2do operando es 0 devolvera -1
 */
float division(float a, float b)
{
    float dividir;
    if(b == 0)
    {
        return -1;//evita que se divida un numero entre 0;

    }
    else
    {

        dividir = a / b;
        return dividir;
    }


}

/** \brief solicita 2 numeros al usuario y devuelve el resultado
 * \param a sera el primer operando ingresado
 * \param b sera el 2do operando ingresado
 * \return devolvera la multiplicacion de los 2 operandos
 */
float multiplicacion(float a, float b)
{
    float multiplicar;

    multiplicar = a * b;

    return multiplicar;

}

/** \brief solicita 1 numero al usuario y devuelve el resultado
 * \param a sera el primer operando ingresado
 * \return devolvera el factorial del numero ingresado, sino devolvera -1 para indicar que se sobrepaso de uno de los criterios
 */
float calcularFactorial1(float a)
{

    int acum1 = 1;
    int i;
    int aux;

    aux = floor(a);

    for(i = aux; i>0; i--)
    {
        acum1 = acum1*i;
    }

    if(a>=16)
    {

        return -1;
    }

    return acum1;
}

/** \brief solicita 1 numero al usuario y devuelve el resultado
 * \param b sera el primer operando ingresado
 * \return devolvera el factorial del numero ingresado, sino devolvera -1 para indicar que se sobrepaso de uno de los criterios
 */
int calcularFactorial2(float b)
{

    int aux;
    int acum2 = 1;
    int j;

    aux = floor(b);

    for(j = aux; j>0; j--)
    {
        acum2 = acum2*j;
    }

    if(aux>=16)
    {
        return -1;
    }

    return acum2;
}

/** \brief solicitara los resultados de todas las operaciones realizadas y sus operando para luego mostrarlos por pantalla
 * \param a y b seran los operandos ingresados
 * \param sum, res, mul, div, factorial1 y factorial 2 seran los resultados de las operaciones ya resueltos
 * \return no devuelve nada ya que solo muestra por pantalla
 */


void mostrar(float a, float b, float sum, float res, float mul, float div, int  factorial1, int factorial2)
{
    system("cls");
    printf("\n1.-El resultado de %.2f + %.2f es: %.2f", a, b, sum);
    printf("\n2.-El resultado de %.2f - %.2f es: %.2f",a, b, res);
    if(div != -1)
    {
        printf("\n3.-El resultado de %.2f / %.2f es: %.2f",a, b, div);
    }
    else
    {

        printf("\n3.-El divisor tiene que ser distinto de 0");
    }
    printf("\n4.-El resultado de %.2f * %.2f es: %.2f",a, b, mul);


    if(factorial1 != -1 )
    {
        printf("\n5.-El factorial de %.2f: es %.2d",a, factorial1);
    }
    else
    {
        printf("\n5.-No hay suficiente memoria para culcular %.2f", a);
    }

    if(factorial2 != -1)
    {
        printf("\n6.-El factorial de %.2f: es %d\n\n",b, factorial2);
    }
    else
    {
        printf("\n6.-No hay suficiente memoria para culcular el factorial de : %.2f\n\n", b);
    }

    system("pause");
}

