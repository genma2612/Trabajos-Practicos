#include <stdio.h>
#include "operaciones.h"

void primeraOpcion(int f1, float n1)
{
    int enteroN1=(int)n1;
    if(f1 == 1)
    {
        printf("1- Ingresar 1er operando (A=x)\n");
    }
    else if(enteroN1 == n1)
    {
        printf("1- Ingresar 1er operando (A=%d)\n", enteroN1);
    }
    else
    {
        printf("1- Ingresar 1er operando (A=%.1f)\n", n1);
    }
}

void segundaOpcion(int f2, float n2)
{
    int enteroN2=(int)n2;
    if(f2 == 1)
    {
        printf("2- Ingresar 2do operando (B=y)\n");
    }
    else if(enteroN2 == n2)
    {
        printf("2- Ingresar 2do operando (B=%d)\n", enteroN2);
    }
    else
    {
        printf("2- Ingresar 2do operando (B=%.1f)\n", n2);
    }
}

float pedirFloat(char mensaje[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    return numero;
}

void sumar(float n1, float n2)
{
    float resultado;
    int resultadoEntero;
    resultado = n1 + n2;
    resultadoEntero = (int)resultado;
    if(resultadoEntero == resultado)
    {
        printf("El resultado de la suma es: %d\n", resultadoEntero);
    }
    else
    {
        printf("El resultado de la suma es: %.1f\n", resultado);
    }
}

void restar(float n1, float n2)
{
    float resultado;
    int resultadoEntero;
    resultado = n1 - n2;
    resultadoEntero = (int)resultado;
    if(resultadoEntero == resultado)
    {
        printf("El resultado de la resta es: %d\n", resultadoEntero);
    }
    else
    {
        printf("El resultado de la resta es: %.1f\n", resultado);
    }
}

void dividir(float n1, float n2)
{
    float resultado;
    int resultadoEntero;
    if(n2 == 0)
    {
        printf("Error! No se puede dividir por 0.\n");
    }
    else
    {
        resultado = n1 / n2;
        resultadoEntero = (int)resultado;
        if(resultadoEntero == resultado)
        {
            printf("El resultado de la division es: %d\n", resultadoEntero);
        }
        else
        {
            printf("El resultado de la division es: %.1f\n", resultado);
        }
    }
}

void multiplicar(float n1, float n2)
{
    float resultado;
    int resultadoEntero;
    resultado = n1 * n2;
    resultadoEntero = (int)resultado;
    if(resultadoEntero == resultado)
    {
        printf("El resultado de la multiplicacion es: %d\n", resultadoEntero);
    }
    else
    {
        printf("El resultado de la multiplicacion es: %.1f\n", resultado);
    }
}

void factorial(float n1)
{
    int EnteroN1=(int)n1;
    long factor=1;
    float i;
    if(n1 < 1 || n1 != EnteroN1)
    {
        printf("Error! Debe ser un numero entero positivo.\n");
    }
    else
    {
        for(i = n1; i > 0; i--)
        {
            factor = factor * i;
        }
        printf("El factorial de %d es: %li\n", EnteroN1, factor);
        }
}

void todasLasOperaciones(float n1, float n2) //Llamada a las funciones de operaciones una por una.
{
    sumar(n1, n2);
    restar(n1, n2);
    dividir(n1, n2);
    multiplicar(n1, n2);
    factorial(n1);
    printf("\n");
}
