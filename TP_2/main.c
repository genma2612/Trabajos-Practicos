#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "tools.h"
#define SIZE 20

int main()
{
    char seguir='s';
    int opcion=0;
    int aux;
    EPersona personas[SIZE];
    inicializarPersonasEstado(personas);
    inicializarPersonasHardCode(personas);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        opcion = ingresarIntValido("Ingrese una opcion: ", "La opcion ingresada no es valida.\nIngrese una opcion: ", 1, 5);
        switch(opcion)
        {
            case 1:
                system("cls");
                aux = agregarPersona(personas);
                system("cls");
                mensajeRetorno(aux, "No quedan espacios disponibles.\n", "Ingreso cancelado.\n", "Persona agregada correctamente.\n");
                break;
            case 2:
                system("cls");
                aux = bajaDePersona(personas);
                system("cls");
                mensajeRetorno(aux, "Baja cancelada.\n", "Baja realizada correctamente.\n", "");
                break;
            case 3:
                system("cls");
                ordernarPorNombre(personas);
                mostrarListado(personas);
                printf("Presione enter para continuar...\n");
                pause();
                system("cls");
                break;
            case 4:
                system("cls");
                graficarEdades(personas);
                printf("Presione enter para continuar...\n");
                pause();
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
