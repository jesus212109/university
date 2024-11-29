#include <stdio.h>
#include "p7.h"

/**
  @fn void imprimeMatriz (float **matriz, int nFil, int nCol)
  @brief Imprime todos los elementos de la matriz
  @param matriz es la ariable que usaremos para reservar la memoria y formar la propia matriz
  @param nFil Nº de filas
  @param nCol Nº de columnas
  @return nada
*/
void imprimeMatriz (float **matriz, int nFil, int nCol){
     for(int i = 0; i < nFil; i++){
        for( int j = 0; j < nCol; j++){
            printf("\nEl contenido de la matriz en la posición [%i][%i] es : %f", i, j, matriz[i][j]);
        }
        printf("\n");
    }
}