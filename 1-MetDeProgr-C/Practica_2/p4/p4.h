#ifndef P4_H
#define P4_H

#define RAMDOMMAX 30

float ** reservarMemoria (int nFil, int nCol);
void rellenaMatriz (float **matriz, int nFil, int nCol);
void imprimeMatriz (float **matriz, int nFil, int nCol);
float * maxFil (float **matriz, int nFil, int nCol);
void imprimirVector(float *v, int n);
void liberarMemoria(float ***matriz, int nFil);

#endif