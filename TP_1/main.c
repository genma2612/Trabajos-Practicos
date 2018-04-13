#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#define clear system("cls")

int main()
{
    char seguir='s';
    int opcion=0;
    float num1=0;
    float num2=0;
    int flag1=1;
    int flag2=1;

    while(seguir=='s')
    {
        // float num1=120;
        // float num2=121;
        // printf("1- Ingresar 1er operando (A=%c)\n", (char)num1);
        // printf("2- Ingresar 2do operando (B=%c)\n", (char)num2);
        /*
        *  Este método requeriría más comprobaciones con flag para
        *  no permitir que el usuario pueda realizar operaciones con los valores
        *  120 y 121 por defecto antes de ingresar valores propios.
        */
        primeraOpcion(flag1, num1);
        segundaOpcion(flag2, num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1:
                clear;
                num1 = pedirFloat("Ingrese el 1er numero (A)\n");
                flag1 = 0;
                clear;
                break;
            case 2:
                clear;
                num2 = pedirFloat("Ingrese el 2do numero (B)\n");
                flag2 = 0;
                clear;
                break;
            case 3:
                clear;
                sumar(num1, num2);
                break;
            case 4:
                clear;
                restar(num1, num2);
                break;
            case 5:
                clear;
                dividir(num1, num2);
                break;
            case 6:
                clear;
                multiplicar(num1, num2);
                break;
            case 7:
                clear;
                factorial(num1);
                break;
            case 8:
                clear;
                todasLasOperaciones(num1, num2);
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                seguir = 'n';
        }
    }
    return 0;
}
