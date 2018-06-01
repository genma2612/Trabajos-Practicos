#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "tools.h"

#define PELICULAS_CANTIDAD 9


int agregarPelicula(EMovie* pLista, int cantidad)
{
    char portadaGenerica[]= {"https://k62.kn3.net/158083771.jpg"};
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[512];
    int puntaje;
    char linkImagen[256];
    int indice;
    int retorno=-1;
    int auxiliar;
    indice = buscarEspacio(pLista, cantidad);
    if(indice == -1)
    {
        return retorno;
    }
    ingresarStringValidaPass("Ingrese el nombre de la pelicula (max.50):\n", "Error, ingrese caracteres validos.\n", "El nombre puede contener 50 caracteres max.\n", titulo, 50);
    ingresarStringValidaPass("Ingrese el genero: (max.20):\n", "Error, ingrese caracteres validos.\n", "El genero puede contener 20 caracteres max.\n", genero, 20);
    duracion = ingresarIntValido("Ingrese la duracion (de 30 minutos a 210 minutos):\n", "Ingrese solo numeros, en el rango valido (de 30 minutos a 210 minutos):\n", 30, 210);
    ingresarStringValidaPass("Ingrese una descripcion: (max.512 caracteres):\n", "Error, ingrese caracteres validos.\n", "La descripcion puede contener 512 caracteres max.\n", descripcion, 512);
    puntaje = ingresarIntValido("Ingrese un puntaje de 0 a 100\n", "Error, ingrese solo numeros. El puntaje debe ser de 0 a 100: \n", 0, 100);
    ingresarStringValidaURL("Ingrese la URL de la portada (max. 512)\n", "Error, ingrese caracteres validos, sin espacios: (max. 512)\n", "URL demasiado larga, max. 512:\n", linkImagen, 512);
    auxiliar = strlen(linkImagen);
    if(auxiliar==0)
    {
        strcpy(linkImagen, portadaGenerica);
    }
    retorno = ingresoEstructura(pLista, cantidad, titulo, genero, duracion, descripcion, puntaje, linkImagen, indice);
    generarPagina(pLista);
    actualizarArchivo(pLista);
    return retorno;
}

int modificarPelicula(EMovie* pLista, int cantidad)
{
    char portadaGenerica[]= {"https://k62.kn3.net/158083771.jpg"};
    int auxiliar;
    int retorno=-1;
    int indice;
    char menu[]= {"1-Titulo\
                \n2-Genero\
                \n3-Duracion\
                \n4-Descripcion\
                \n5-Puntaje\
                \n6-URL de portada\
                \n7-Salir\
                \n"};
    mostrarCargados(pLista, cantidad);
    auxiliar = ingresarIntValido("\nIngrese la ID a modificar o 0 para cancelar\n", "Opcion incorrecta. Ingrese una ID del listado o 0 para cancelar\n", 0, 9999);
    if(!auxiliar)
    {
        return retorno;
    }
    indice = buscarIndiceDeId(pLista, cantidad, auxiliar);
    if(indice < 0)
    {
        retorno = 0;
        return retorno;
    }
    clearScreen();
    printf("%s: ",(pLista+indice)->titulo);
    auxiliar = ingresarIntValido("Confirmar la modificacion (1-Si 2-No):\n", "Opcion incorrecta (1-Si 2-No):\n", 1, 2);
    if(auxiliar == 2)
    {
        return retorno;
    }
    retorno = 1;
    clearScreen();
    do
    {
        printf("%s",menu);
        auxiliar = ingresarIntValido("Elija una opcion:\n", "Elija una opcion valida (1-7)\n", 1, 7);
        switch(auxiliar)
        {
        case 1:
            clearScreen();
            ingresarStringValida("Ingrese el nombre de la pelicula (max.50):\n", "Error, ingrese caracteres validos.\n", "El nombre puede contener 50 caracteres max.\n", (pLista+indice)->titulo, 50);
            break;
        case 2:
            clearScreen();
            ingresarStringValida("Ingrese el genero: (max.20):\n", "Error, ingrese caracteres validos.\n", "El genero puede contener 20 caracteres max.\n", (pLista+indice)->genero, 20);
            break;
        case 3:
            clearScreen();
            (pLista+indice)->duracion = ingresarIntValido("Ingrese la duracion (de 30 minutos a 210 minutos):\n", "Ingrese solo numeros, en el rango valido (de 30 minutos a 210 minutos):\n", 30, 210);
            break;
        case 4:
            clearScreen();
            ingresarStringValida("Ingrese una descripcion: (max.512 caracteres):\n", "Error, ingrese caracteres validos.\n", "La descripcion puede contener 512 caracteres max.\n", (pLista+indice)->descripcion, 512);
            break;
        case 5:
            clearScreen();
            (pLista+indice)->puntaje = ingresarIntValido("Ingrese un puntaje de 0 a 100\n", "Error, ingrese solo numeros. El puntaje debe ser de 0 a 100: \n", 0, 100);
            break;
        case 6:
            clearScreen();
            ingresarStringValidaURL("Ingrese la URL de la portada (max. 512)\n", "Error, ingrese caracteres validos, sin espacios: (max. 512)\n", "URL demasiado larga, max. 512:\n", (pLista+indice)->linkImagen, 512);
            auxiliar = strlen((pLista+indice)->linkImagen);
            if(auxiliar==0)
            {
                strcpy((pLista+indice)->linkImagen, portadaGenerica);
            }
            break;
        case 7:
            break;
        }
        clearScreen();
    }
    while(auxiliar != 7);
    generarPagina(pLista);
    actualizarArchivo(pLista);
    return retorno;
}

int borrarPelicula(EMovie* pLista, int cantidad)
{
    int auxiliar;
    int retorno=-1;
    int indice;
    mostrarCargados(pLista, cantidad);
    auxiliar = ingresarIntValido("\nIngrese la ID a borrar o 0 para cancelar:\n", "Opcion incorrecta. Ingrese una ID del listado o 0 para cancelar\n", 0, 9999);
    if(!auxiliar)
    {
        return retorno;
    }
    indice = buscarIndiceDeId(pLista, cantidad, auxiliar);
    if(indice < 0)
    {
        retorno = 0;
        return retorno;
    }
    clearScreen();
    printf("%s: ",(pLista+indice)->titulo);
    auxiliar = ingresarIntValido("Confirmar el borrado? (1-Si 2-No):\n", "Opcion incorrecta (1-Si 2-No):\n", 1, 2);
    if(auxiliar == 2)
    {
        retorno = -1;
        return retorno;
    }
    (pLista+indice)->estado = 0;
    retorno = 1;
    generarPagina(pLista);
    actualizarArchivo(pLista);
    return retorno;
}

int inicializacionPeliculas(EMovie* pLista, int cantidad)
{
    int i;
    int retorno=-1;
    if(pLista != NULL && cantidad > 0)
    {
        for(i=0; i<cantidad; i++)
        {
            (pLista+i)->estado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int ingresoEstructura(EMovie* pLista, int cantidad, char titulo[], char genero[], int duracion, char descripcion[], int puntaje, char linkImagen[], int indice)
{
    int retorno=-1;
    int idAux;
    if(pLista != NULL && cantidad > 0)
    {
        idAux = generarIdDisponible(pLista, cantidad);
        strcpy((pLista+indice)->titulo,titulo);
        strcpy((pLista+indice)->genero,genero);
        (pLista+indice)->duracion = duracion;
        strcpy((pLista+indice)->descripcion,descripcion);
        (pLista+indice)->puntaje = puntaje;
        strcpy((pLista+indice)->linkImagen,linkImagen);
        (pLista+indice)->idPelicula = idAux;
        (pLista+indice)->estado = 1;
        retorno=0;
    }
    return retorno;
}

int buscarIndiceDeId(EMovie* pLista, int cantidad, int idABuscar)
{
    int i;
    int retorno=-1;
    if(pLista != NULL && cantidad > 0)
    {
        for(i=0; i<cantidad; i++)
        {
            if((pLista+i)->idPelicula == idABuscar)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void primerHC(EMovie* pLista, int cantidad)
{
    ingresoEstructura(pLista, cantidad, "Sweet and Lowdown", "Comedy", 95, "In the 1930s, jazz guitarist Emmet Ray idolizes Django Reinhardt, faces gangsters and falls in love with a mute woman.", 90, "https://ia.media-imdb.com/images/M/MV5BMjE2MzA5MDQ4NV5BMl5BanBnXkFtZTgwNjI4ODQxMDE@._V1_UX182_CR0,0,182,268_AL_.jpg", 0);
    ingresoEstructura(pLista, cantidad, "Eternal Sunshine of the Spotless Mind", "Sci-Fi", 108, "When their relationship turns sour, a young couple undergoes a medical procedure to have each other erased from their memories.", 90, "https://ia.media-imdb.com/images/M/MV5BMTY4NzcwODg3Nl5BMl5BanBnXkFtZTcwNTEwOTMyMw@@._V1_UX182_CR0,0,182,268_AL_.jpg", 1);
    ingresoEstructura(pLista, cantidad, "Ghost World","Comedy", 111, "With only the plan of moving in together after high school, two unusually devious friends seek direction in life.", 90, "https://ia.media-imdb.com/images/M/MV5BMTI5MDg2ODA2M15BMl5BanBnXkFtZTYwNDAzMjk2._V1_UX182_CR0,0,182,268_AL_.jpg", 2);
    ingresoEstructura(pLista, cantidad, "Toy Story", "Comedy", 81, " A cowboy doll is profoundly threatened and jealous when a new spaceman figure supplants him as top toy in a boy's room.", 90, "https://ia.media-imdb.com/images/M/MV5BMDU2ZWJlMjktMTRhMy00ZTA5LWEzNDgtYmNmZTEwZTViZWJkXkEyXkFqcGdeQXVyNDQ2OTk4MzI@._V1_UX182_CR0,0,182,268_AL_.jpg", 3);
    ingresoEstructura(pLista, cantidad, "Amelie", "Romance", 122, "Amelie is an innocent and naive girl in Paris with her own sense of justice. She decides to help those around her and, along the way, discovers love.", 83, "https://ia.media-imdb.com/images/M/MV5BNDg4NjM1YjMtYmNhZC00MjM0LWFiZmYtNGY1YjA3MzZmODc5XkEyXkFqcGdeQXVyNDk3NzU2MTQ@._V1_UX182_CR0,0,182,268_AL_.jpg", 4);
    ingresoEstructura(pLista, cantidad, "Fahrenheit 451", "Sci-Fi", 111, "In an oppressive future, a fireman whose duty is to destroy all books begins to question his task.", 90, "https://ia.media-imdb.com/images/M/MV5BMjI3MzI3MjQ2OF5BMl5BanBnXkFtZTgwMTI4ODYxMTE@._V1_UX182_CR0,0,182,268_AL_.jpg", 5);
    ingresoEstructura(pLista, cantidad, "American Graffiti", "Drama", 95, "A couple of high school grads spend one final night cruising the strip with their buddies before they go off to college.", 90, "https://ia.media-imdb.com/images/M/MV5BMjI5NjM5MjIyNF5BMl5BanBnXkFtZTgwNjg2MTUxMDE@._V1_UX182_CR0,0,182,268_AL_.jpg", 6);
    ingresoEstructura(pLista, cantidad, "The Karate Kid", "Action", 108, " A martial arts master agrees to teach karate to a bullied teenager. ", 90, "https://ia.media-imdb.com/images/M/MV5BNTkzY2YzNmYtY2ViMS00MThiLWFlYTEtOWQ1OTBiOGEwMTdhXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_UX182_CR0,0,182,268_AL_.jpg", 7);
    ingresoEstructura(pLista, cantidad, "The Terminator","Sci-Fi", 111, "A seemingly indestructible android is sent from 2029 to 1984 to assassinate a waitress, whose unborn son will lead humanity in a war against the machines, while a soldier from that war is sent to protect her at all costs.", 90, "https://ia.media-imdb.com/images/M/MV5BODE1MDczNTUxOV5BMl5BanBnXkFtZTcwMTA0NDQyNA@@._V1_UX182_CR0,0,182,268_AL_.jpg", 8);
}

int buscarEspacio(EMovie* pLista, int cantidad)
{
    int i;
    int retorno=-1;
    if(pLista != NULL && cantidad > 0)
    {
        for(i=0; i<cantidad; i++)
        {
            if((pLista+i)->estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int generarIdDisponible(EMovie* pLista, int cantidad)
{
    int i;
    int ultmaId=0;
    int retorno=-1;
    if(pLista != NULL && cantidad > 0)
    {
        for(i=0; i<cantidad; i++)
        {
            if((pLista+i)->estado == 1)
            {
                if((pLista+i)->idPelicula > ultmaId)
                {
                    ultmaId = (pLista+i)->idPelicula;
                }
            }
        }
        retorno = ultmaId+1;
    }
    return retorno;
}

void mostrarCargados(EMovie* pLista, int cantidad)
{
    int i;
    if(pLista != NULL && cantidad > 0)
    {
        printf("TITULO                              GENERO                  ID\n");
        printf("****************************************************************\n");
        for(i=0; i<cantidad; i++)
        {
            if((pLista+i)->estado == 1)
            {
                printf("%-20.30s %21.20s %19d\n", (pLista+i)->titulo, (pLista+i)->genero, (pLista+i)->idPelicula);
            }
        }
    }
}

// ARCHIVOS

void comprobacionEinicializacion(EMovie* pLista)
{
    int i;
    FILE* binario;
    if((binario=fopen("peliculas.dat","rb"))==NULL)
    {
        if((binario=fopen("peliculas.dat","wb"))!=NULL)
        {
            inicializacionPeliculas(pLista, PELICULAS_CANTIDAD);
            primerHC(pLista, PELICULAS_CANTIDAD);
            for(i=0; i<PELICULAS_CANTIDAD; i++)
            {
                if((pLista+i)->estado == 1)
                {
                    fwrite((pLista+i), sizeof(EMovie),1, binario);
                }
            }
            fclose(binario);
        }
        else
        {
            printf("\nERROR. No se puede abrir.\n");
        }
        fclose(binario);
    }

    if((binario=fopen("peliculas.dat","rb"))!=NULL)
    {
        for(i=0; i<PELICULAS_CANTIDAD; i++)
        {
            fread((pLista+i), sizeof(EMovie),1, binario);
        }
    }
    else
    {
        printf("No se puede acceder al archivo binario.\n");
    }
}

void actualizarArchivo(EMovie* pLista)
{
    int i;
    FILE* binario;
    if((binario=fopen("peliculas.dat","wb"))!=NULL)
    {
        for(i=0; i<PELICULAS_CANTIDAD; i++)
        {
            if((pLista+i)->estado == 1)
            {
                fwrite((pLista+i), sizeof(EMovie),1, binario);
            }
        }
        fclose(binario);
    }
    else
    {
        printf("\nERROR. No se puede abrir.\n");
    }
    fclose(binario);
}

void generarPagina(EMovie lista[])
{
    int i;
    FILE* f;
    f = fopen("Peliculas.html", "w");
    if(f!=NULL)
    {
        fprintf(f, "<!DOCTYPE html>\
                    \n<!-- Template by Quackit.com -->\
                    \n<html lang='en'>\
                    \n<head>\
                    \n    <meta charset='utf-8'>\
                    \n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
                    \n    <meta name='viewport' content='width=device-width, initial-scale=1'>\
                    \n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
                    \n    <title>Lista peliculas</title>\
                    \n    <!-- Bootstrap Core CSS -->\
                    \n    <link href='css/bootstrap.css' rel='stylesheet'>\
                    \n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
                    \n    <link href='css/custom.css' rel='stylesheet'>\
                    \n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
                    \n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
                    \n    <!--[if lt IE 9]>\
                    \n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
                    \n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
                    \n    <![endif]-->\
                    \n</head>\
                    \n<body>\
                    \n    <div class='container'>\
                    \n        <div class='row'>\
                    \n\
                    \n\
                    \n			<!-- Repetir esto para cada pelicula -->\
                    \n");
        for(i=0; i<PELICULAS_CANTIDAD; i++)
        {
            if(lista[i].estado == 1)
            {
                fprintf(f, "            <article class='col-md-4 article-intro'>\
                \n                <a href='#'>\
                \n                    <img class='img-responsive img-rounded' src='%s' alt=''>\
                \n                </a>\
                \n                <h3>\
                \n                    <a href='#'>%s</a>\
                \n                </h3>\
                \n				<ul>\
                \n					<li>Genre: %s</li>\
                \n					<li>Score: %d</li>\
                \n					<li>Lenght: %d</li>\
                \n				</ul>\
                \n                <p>%s</p>\
                \n            </article>\
                \n", lista[i].linkImagen, lista[i].titulo, lista[i].genero, lista[i].duracion, lista[i].puntaje, lista[i].descripcion);
            }
        }
        fprintf(f, "            <!-- Repetir esto para cada pelicula -->\
                \n \
                \n			\
                \n        </div>\
                \n        <!-- /.row -->\
                \n    </div>\
                \n    <!-- /.container -->\
                \n    <!-- jQuery -->\
                \n    <script src='js/jquery-1.11.3.min.js'></script>\
                \n    <!-- Bootstrap Core JavaScript -->\
                \n    <script src='js/bootstrap.min.js'></script>\
                \n	<!-- IE10 viewport bug workaround -->\
                \n	<script src='js/ie10-viewport-bug-workaround.js'></script>\
                \n	<!-- Placeholder Images -->\
                \n	<script src='js/holder.min.js'></script>\
                \n</body>\
                \n</html>");
        fclose(f);
    }
}
