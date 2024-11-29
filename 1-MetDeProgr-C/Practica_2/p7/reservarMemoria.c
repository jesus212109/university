#include <stdio.h>
#include <stdlib.h>
#include "p7.h"

/**
  @fn  float ** reservarMemoria (int nFil, int nCol)
  @brief La función genera la reserva en bloque de una matriz dinámica en el heap un devuelve su diección
  @param nFil Nº de filas
  @param nCol Nº de columnas
  @return Devuelve la dirección de la reserva de la matriz dinámica de tipo float
*/
float ** reservarMemoria (int nFil, int nCol){
    float** m;  //matriz

   
    if ( (m = calloc(nFil, sizeof(float*))) == NULL){ 
        perror("\nError: no hay memoria\n");
    }

    if ( (m[0] = calloc( nFil*nCol, sizeof(float) ) ) == NULL){ 
        perror("\nError: no hay memoria\n");
    }

    for( int i=1; i<nFil; i++){
        m[i] = m[i-1] + nCol;
    }
    
    return (m);
}