#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesvarias.h"

void fin_anormal(char *msj)
{
    if(*msj)
        printf("\n%s",msj);
    pausa("SE CANCELA EL PROCESO");
    exit(1);
}

void pausa(char *msj)
{
    if (*msj)
        printf("\n%s",msj);
    puts("\nPRESIONE -ENTER- PARA CONTINUAR...");
    fflush(stdin);
    scanf("%*c");
}

char menu(const char m[][TAM], const char *tit)
{
//  entrada: matriz de caracteres y t�tulo del menu
//  salida: opcion elegida por el usuario (CHAR)
    char op;    /* Variable que contiene la opci�n elegida por el usuario */
    op = pedir_opcion(m, tit, "Ingrese su opcion");
    while ( !strchr(m[0], op))  /* m[0] contiene las opciones,
                                se verifica s� la opci�n ingresada es v�lida */
        op = pedir_opcion(m, tit, "OPCION ERRONEA. Ingresela nuevamente");
    return op;
}

char pedir_opcion(const char m[][TAM], const char *tit, const char *msj)
{
//  Definici�n de Variables
    char op;
    int i;
//  L�gica
    system("CLS");
    printf("\n\n %s \n", tit); /* Imprime el t�tulo */
    for ( i=1 ; i <= strlen(m[0]) ; i++ )
    /* Imprime cada una de las l�neas de opciones */
        printf("\n  %c.- %s", m[0][i-1], m[i]);
    printf("\n\n  %s: ", msj);  /* Imprime mensaje de entrada */
    fflush(stdin);  /* Limpia el buffer */
    scanf("%c", &op);   /* Lee la opci�n del teclado */
    return ( aMayusc(op) ); /* Devuelve la opci�n en may�scula */
}


