// Crea   una   biblioteca   (libMatrices.a)   a   partir   de   las   cuatro   funciones   del   ejercicio   4
// (reservarMemoria,  liberarMemoria,  rellenaMatriz  e  imprimeMatriz)   y   su   correspondiente
// fichero de cabecera. Reproduce los resultados del ejercicio 3, pero esta vez haciendo uso de la
// biblioteca creada (por tanto sólo necesitarás un  main(), la inclusión del  .h  de la biblioteca y
// enlazar con ella). Utiliza Doxygen para documentar todas las funciones de la biblioteca.

/**
@file Practica_7
@author Jesús Fernández López
@brief  Este programa simplemente genera una matriz con valores aleatorios
@date  20/03/2023
@version 1.0.0
*/


#include <stdio.h>
#include <stdlib.h>
#include "p7.h"


int main(){
    float** m, *vmax;
    int nFil,nCol;

    printf("\nFilas para la matriz: ");
    scanf("%i",&nFil);

    printf("\nColumnas: ");
    scanf("%i",&nCol);

    m = reservarMemoria(nFil,nCol);
    rellenaMatriz(m, nFil, nCol);
    imprimeMatriz(m, nFil, nCol);

    liberarMemoria(&m, nFil);
}