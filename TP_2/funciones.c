#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "tools.h"
#define SIZE 20

void inicializarPersonasEstado(EPersona lista[])
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        lista[i].estado = 0;
    }
}

void inicializarPersonasHardCode(EPersona lista[])
{
    char nombres[][50]= {"Lucas","Martin","Maria","Julia","Alexis","Ximena","Susana","Pedro","Nicolas","Jose","Ana","Laura","Raul","Catriel","Pablo"};
    int edades[15]= {40,17,32,5,10,20,27,50,13,38,11,29,33,23,25};
    int dni[15]= {25258963,44589632,28147852,50963159,48965459,42987124,36945789,22369789,48963582,25789987,47825936,34777528,31998887,40946169,38147741};
    int i;
    for(i=0; i<15; i++)
    {
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].edad = edades[i];
        lista[i].dni = dni[i];
        lista[i].estado = 1;
    }
}

int agregarPersona(EPersona lista[])
{
    int espacio;
    int campoClave;
    int retorno=-1;
    int aux;
    espacio = obtenerEspacioLibre(lista);
    if(espacio == -1)
    {
        return retorno;
    }
    do{
        aux = ingresarIntValido("Ingrese el DNI:\n", "ERROR, El DNI debe estar conformado SOLO por numeros positivos.\nIngrese el DNI:\n", 1, 100000000);
        campoClave = buscarPorDni(lista, aux);
        if(campoClave != -1)
        {
            aux = ingresarIntValido("El DNI ingresado ya esta en uso. 1-Ingresar otro. 2-Salir: ", "\nOpcion incorrecta. 1-Ingresar otro. 2-Salir: ", 1, 2);
            if(aux == 2)
            {
                retorno = 0;
                return retorno;
            }
        }
    }while(campoClave != -1);
    retorno = 1;
    lista[espacio].dni = aux;
    ingresarStringValida("Ingrese el nombre:\n", "Error, solo puede contener letras.\n", "Error, el tamano maximo es de 50 caracteres.\n", lista[espacio].nombre, 51);
    lista[espacio].edad = ingresarIntValido("Ingrese la edad (Min. 0, Max. 120):\n", "Error! (Solo puede contener numeros en el rango permitido.\nIngrese la edad (Min. 0, Max. 120)\n", 0, 120);
    lista[espacio].estado = 1;
    return retorno;
}

int obtenerEspacioLibre(EPersona lista[])
{
    int index=-1;
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(lista[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int index=-1;
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(lista[i].estado == 1 && lista[i].dni == dni)
        {
            index = i;
            break;
        }
    }
    return index;
}

int bajaDePersona(EPersona lista[])
{
    int index;
    int campoClave;
    int aux;
    int retorno=-1;
    do{
        aux = ingresarIntValido("Elija una opcion: 1-Ingresar el DNI a dar de baja. 2-Mostrar listado de DNI en base de datos. 3-Cancelar\n", "Opcion incorrecta.\n", 1, 3);
        system("cls");
        if(aux == 2)
        {
            ordernarPorNombre(lista);
            mostrarListado(lista);
        }
        if(aux == 3)
        {
            return retorno;
        }
        campoClave = ingresarIntValido("Ingrese el DNI:\n", "ERROR, El DNI debe estar conformado SOLO por numeros positivos.\nIngrese el DNI:\n", 1, 120000000);
        index = buscarPorDni(lista, campoClave);
        if(index == -1)
        {
            aux = ingresarIntValido("El DNI ingresado no se encuentra. 1-Intentar nuevamente. 2-Cancelar\n", "Opcion incorrecta.\n", 1, 2);
            if(aux == 2)
            {
                return retorno;
            }
            system("cls");
        }
    }while(index == -1);
    aux = ingresarIntValido("Confirmar la baja? 1-Si. 2-Cancelar.\n", "Opcion incorrecta.", 1, 2);
    if(aux == 2)
    {
        return retorno;
    }
    retorno = 0;
    lista[index].estado = 0;
    return retorno;
}

void ordernarPorNombre(EPersona lista[])
{
    int auxiliar;
    char auxNombre[50];
    int i;
    int j;
    for(i=0; i<SIZE-1; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            if(lista[i].estado == 1 && lista[j].estado == 1 && stricmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                strcpy(auxNombre, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxNombre);

                auxiliar = lista[i].dni;
                lista[i].dni = lista[j].dni;
                lista[j].dni = auxiliar;

                auxiliar = lista[i].edad;
                lista[i].edad = lista[j].edad;
                lista[j].edad = auxiliar;

            }
        }
    }
}

void mostrarListado(EPersona lista[])
{
    int i;
    printf("NOMBRE               DNI          EDAD\n");
    for(i=0; i<SIZE; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%-10.15s %15d %10d\n", lista[i].nombre, lista[i].dni, lista[i].edad);
        }
    }
    printf("\n");
}

void graficarEdades(EPersona lista[])
{
    int i;
    int j;
    int contador[3]={0};
    int mayor=0;
    for(i=0; i<SIZE; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad <= 18)
            {
                contador[0]++;
            }
            else if(lista[i].edad > 19 && lista[i].edad <= 35)
            {
                contador[1]++;
            }
            else
            {
                contador[2]++;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        if(contador[i] > mayor)
        {
            mayor = contador[i];
        }
    }
    printf("Menores a 18: %d, entre 19 y 35: %d y mayores de 35: %d\n", contador[0],contador[1],contador[2]);
    printf("\n");
    for(i=mayor;i>0;i--)
    {
        for(j=0;j<3;j++)
        {
            if(contador[j] >= i)
            {
                printf("  **  ");
            }
            else
            {
                printf("      ");
            }
        }
        printf("\n");
    }
    printf("< 18   19-35 >35");
    printf("\n");
    printf("\n");
}
