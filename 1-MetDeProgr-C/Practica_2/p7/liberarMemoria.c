#include <stdio.h>
#include <stdlib.h>
#include "p7.h"

/**
  @file Practica_7
  @author Jesús Fernández López
  @brief  Este programa simplemente genera una matriz con valores aleatorios
  @date  20/03/2023
  @version 1.0.0
*/


/**
  @fn void liberarMemoria(float ***matriz, int nFil)
  @brief Libera la asignación de memoria en el heap
  @param matriz es la ariable que usaremos para reservar la memoria y formar la propia matriz
  @param nFil Nº de filas
  @return nada
*/
void liberarMemoria(float ***matriz, int nFil){
    free((*matriz)[0]);
    free (*matriz);
    *matriz == NULL; 
}