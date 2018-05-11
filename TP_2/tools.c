#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

int ingresarInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

int ingresarIntValido(char mensajeAMostrar[],char mensajeError[],int lowLimit, int hiLimit)
{
    char auxStr[256];
    int flag=1;
    int auxInt;
    auxInt = ingresarStringNumeros(mensajeAMostrar, auxStr);
    do
    {
        if(!flag)
        {
            auxInt = 0;
        }
        while(auxInt == 0)
        {
            auxInt = ingresarStringNumeros(mensajeError, auxStr);
        }
        flag = 0;
        auxInt = atoi(auxStr);
    }while(auxInt < lowLimit || auxInt > hiLimit);
    return auxInt;
}

float ingresarFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

float ingresarFloatValido(char mensajeAMostrar[],char mensajeError[],float lowLimit, float hiLimit)
{
    char auxStr[256];
    int flag=1;
    int auxInt;
    float auxFloat;
    auxInt = ingresarStringNumerosFlotantes(mensajeAMostrar, auxStr);
    do
    {
        if(!flag)
        {
            auxInt = 0;
        }
        while(auxInt == 0)
        {
            auxInt = ingresarStringNumerosFlotantes(mensajeError, auxStr);
        }
        flag = 0;
        auxFloat = atof(auxStr);
    }while(auxFloat < lowLimit || auxFloat > hiLimit);
    return auxFloat;
}

char ingresarChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    clearStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}

void ingresarString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

void ingresarStringValida(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax)
{
    int auxInt;
    char buffer[1024];
    do
    {
        auxInt = ingresarStringLetras(mensajeAMostrar,buffer);
        if(auxInt == 0)
        {
            printf ("%s",mensajeError);
            continue;
        }
        if(strlen(buffer) >= largoMax)
        {
            printf ("%s",mensajeErrorExced);
            auxInt = 0;
            continue;
        }
        strcpy(input,buffer);
    }while(auxInt == 0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ingresarStringValidaPass(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax)
{
    int auxInt;
    char buffer[1024];
    do
    {
        auxInt = ingresarStringPass(mensajeAMostrar,buffer);
        if(auxInt == 0)
        {
            printf ("%s",mensajeError);
            continue;
        }
        if(strlen(buffer) >= largoMax)
        {
            printf ("%s",mensajeErrorExced);
            auxInt = 0;
            continue;
        }
        strcpy(input,buffer);
    }while(auxInt == 0);
}

void ingresarStringValidaTelefono(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax)
{
    int auxInt;
    char buffer[1024];
    do
    {
        auxInt = ingresarStringTelefono(mensajeAMostrar,buffer);
        if(auxInt == 0)
        {
            printf ("%s",mensajeError);
            continue;
        }
        if(strlen(buffer) >= largoMax)
        {
            printf ("%s",mensajeErrorExced);
            auxInt = 0;
            continue;
        }
        strcpy(input,buffer);
    }while(auxInt == 0);
}

void ingresarStringValidaAlfa(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax)
{
    int auxInt;
    char buffer[1024];
    do
    {
        auxInt = ingresarStringAlfa(mensajeAMostrar,buffer);
        if(auxInt == 0)
        {
            printf ("%s",mensajeError);
            continue;
        }
        if(strlen(buffer) >= largoMax)
        {
            printf ("%s",mensajeErrorExced);
            auxInt = 0;
            continue;
        }
        strcpy(input,buffer);
    }while(auxInt == 0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int esPass(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < '!' || str[i] > '~'))
           return 0;
       i++;
   }
   return 1;
}

int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

int ingresarStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    ingresarString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresarStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    ingresarString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresarStringLetras(char mensaje[],char input[])
{
    char aux[256];
    ingresarString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresarStringPass(char mensaje[],char input[])
{
    char aux[256];
    ingresarString(mensaje,aux);
    if(esPass(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresarStringTelefono(char mensaje[],char input[])
{
    char aux[256];
    ingresarString(mensaje,aux);
    if(esTelefono(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresarStringAlfa(char mensaje[],char input[])
{
    char aux[256];
    ingresarString(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void clearStdin(void)
{
    setbuf(stdin,NULL);
}

void pause(void)
{
    ingresarChar("");
}

void clearScreen(void)
{
    system("cls"); //system("cls"); clear
}

void mensajeRetorno(int valor, char Mensaje1[], char Mensaje2[], char Mensaje3[])
{
    if(valor == -1)
    {
        printf("%s",Mensaje1);
    }
    else if(valor == 0)
    {
        printf("%s",Mensaje2);
    }
    else
    {
        printf("%s",Mensaje3);
    }
}
