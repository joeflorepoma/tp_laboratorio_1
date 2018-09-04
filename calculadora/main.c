#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "funciones.h"

#define ESC 27

int main()
{
    float a;
    float b;

    char opcion;

    float suma;
    float resta;
    float mul;
    float div;
    int fact1;
    int fact2;


    do
    {
        menu(a,b);

        opcion =  getch();

        switch(opcion)
        {
        case '1':

            a = primerOperando();

            break;
        case '2':

            b = segundoOperando();

            break;
        case '3':
            system("cls");
            suma = sumatoria(a,b);
            resta = restar(a,b);
            mul = multiplicacion(a,b);
            div = division(a,b);
            fact1 = calcularFactorial1(a);
            fact2 = calcularFactorial2(b);

            printf("\nCalculos resalizados...\n");
            system("pause");

            break;
        case '4':

            mostrar(a, b, suma, resta, mul, div, fact1, fact2);

            break;
        case ESC:
            system("cls");
            printf("\n\nFin del programa...\n");
            break;
        }

    }
    while(opcion != ESC);

    return 0;
}
