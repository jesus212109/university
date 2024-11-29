// Escribe un programa que implemente las siguientes funciones sobre matrices dinámicas y las
// llame de manera secuencial mostrando, de manera adecuada, la salida por pantalla. 
// ●float ** reservarMemoria (int nFil, int nCol).   Reserva memoria para una matriz de  nFil
// filas y nCol columna//printf("m[%d][m%d]:%d\n",i,j,*(*(matriz+i)+j));s. La reserva de memoria se realizará en un solo bloque.
// ●void rellenaMatriz (float **matriz, int nFil, int nCol).    Rellena   una   matriz   con   valores
// aleatorios en el intervalo [0, 1]. Como los elementos de la matriz están en dispuestos de
// forma consecutiva y en un único bloque en memoria, asigna la dirección almacenada en
// M[0] a un puntero V (float *V=M[0]) y recórrelos como un vector utilizando V.
// ●void imprimeMatriz (float **matriz, int nFil, int nCol).   Imprime una matriz por pantalla.
// Recorre la matriz con notación de corchetes. 
// ●float * maxFil (float **matriz, int nFil, int nCol).  Devuelve un vector dinámico con los
// máximos de cada fila.
// ●void liberarMemoria(float ***matriz, int nFil).  Libera la memoria de una matriz reservada
// dinámicamente. La función pondrá el puntero matriz a NULL antes de terminar.

#include <stdio.h>
#include <stdlib.h>
#include "p4.h"

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

    printf("\nEl vector compuesto por los mayores de cada fila:");
    vmax = maxFil(m, nFil, nCol);
    imprimirVector(vmax, nFil);

    liberarMemoria(&m, nFil);
}