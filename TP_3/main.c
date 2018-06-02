#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "tools.h"
#define PELICULAS_CANTIDAD 30

int main()
{
    int auxiliar;
    char seguir='s';
    int opcion=0;
    EMovie arrayPeliculas[PELICULAS_CANTIDAD];
    comprobacionEinicializacion(arrayPeliculas);


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Mostrar en pantalla (comprobacion)\n");
        printf("6- Salir\n");

        opcion = ingresarIntValido("", "Opcion incorrecta\n", 1, 6);

        switch(opcion)
        {
        case 1:
            clearScreen();
            auxiliar = agregarPelicula(arrayPeliculas, PELICULAS_CANTIDAD);
            mensajeRetorno(auxiliar, "Error, no quedan espacios.\n", "Pelicula cargada correctamente.\n", " ");
            printf("\nPresione Enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 2:
            clearScreen();
            auxiliar = modificarPelicula(arrayPeliculas, PELICULAS_CANTIDAD);
            mensajeRetorno(auxiliar, "Modificacion cancelada.\n", "El ID ingresado no se encuentra.\n", "Pelicula modificada correctamente.\n");
            printf("\nPresione Enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 3:
            clearScreen();
            auxiliar = borrarPelicula(arrayPeliculas, PELICULAS_CANTIDAD);
            mensajeRetorno(auxiliar, "Borrado cancelada.\n", "El ID ingresado no se encuentra.\n", "Pelicula borrada correctamente.\n");
            printf("\nPresione Enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 4:
            clearScreen();
            generarPagina(arrayPeliculas);
            printf("Pagina generada correctamente!\n");
            printf("\nPresione Enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 5:
            clearScreen();
            mostrarCargados(arrayPeliculas, PELICULAS_CANTIDAD);
            printf("\nPresione Enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
