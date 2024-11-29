/**
  @file Practica_7
  @author Jesús Fernández López
  @brief  Este programa simplemente genera una matriz con valores aleatorios
  @date  20/03/2023
  @version 1.0.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p7.h"



/**
  @fn void rellenaMatriz (float **matriz, int nFil, int nCol)
  @brief Esta función relena aleatoriamente un vector o una matriz generada en bloque
  @param matriz es la ariable que usaremos para reservar la memoria y formar la propia matriz
  @param nFil Nº de filas
  @param nCol Nº de columnas
  @return nada
*/
void rellenaMatriz (float **matriz, int nFil, int nCol){
    float *v = matriz[0];
    time_t t;
    srand((unsigned)time(&t));

    for(int i = 0; i < nFil*nCol; i++){
        v[i] = rand()%RAMDOMMAX + 1;
    }
}