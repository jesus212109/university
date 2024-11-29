#include <stdio.h>
#include "funciones.h"

// Codifica   un   programa   en   C   que,   utilizando   funciones,   lea   números   enteros   desde   un   fichero
// binario generado en el ejercicio anterior, almacene sus valores en un vector dinámico y calcule la
// media de los números pares. El nombre del fichero se le preguntará al usuario.

#define TAM_MAX 50
int main()
{
    /*DECLARAMOS VARIABLES LOCALES*/
    char nombreFichero[TAM_MAX];
    int pares;
    float media;
    /*PEDIMOS LOS DATOS QUE NECESITAMOS*/
    printf("Introduzca el nombre del ficehro binario--> ");
    scanf("%s", nombreFichero);
    getchar();

    calcularMediaNumerosPares(nombreFichero, &pares, &media);
    printf("\nEl numero de pares es %i y su media es %f\n", pares, media);
}