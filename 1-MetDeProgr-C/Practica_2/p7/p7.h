/**
  @file Practica_7
  @author Jesús Fernández López
  @brief  Este programa simplemente genera una matriz con valores aleatorios
  @date  20/03/2023
  @version 1.0.0
*/

#ifndef P7_H
#define P7_H

#define RAMDOMMAX 30

float ** reservarMemoria (int nFil, int nCol);
void rellenaMatriz (float **matriz, int nFil, int nCol);
void imprimeMatriz (float **matriz, int nFil, int nCol);
float * maxFil (float **matriz, int nFil, int nCol);
void imprimirVector(float *v, int n);
void liberarMemoria(float ***matriz, int nFil);



#endif