// Escribe un programa que implemente las siguientes funciones sobre matrices dinámicas y las
// llame de manera secuencial mostrando, de manera adecuada, la salida por pantalla. 
// ●int ** reservarMemoria (int nFil, int nCol).  Reserva memoria para una matriz de nFil filas
// y nCol columnas. La reserva de memoria se realizará por filas.
// ●void rellenaMatriz (int **matriz, int nFil, int nCol).    Rellena   una   matriz   con   valores
// aleatorios en el intervalo [1, 20]. Usa la notación de aritmética de punteros para recorrer la
// matriz. 
// ●void imprimeMatriz (int **matriz, int nFil, int nCol).  Imprime una matriz por pantalla. Usa
// la notación de artitmética de punteros para recorrer la matriz.
// ●int * minCol (int **matriz, int nFil, int nCol).  Devuelve   un   vector   dinámico   con   los
// mínimos de cada columna.
// ●void liberarMemoria(int ***matriz, int nFil).   Libera la memoria de una matriz reservada
// dinámicamente. La función pondrá el puntero matriz a NULL antes de terminar.
/**
*@author Jesus

*/
#include <stdio.h>
#include "p3.h"

int main(){
    int nFil,nCol;
    int **matriz, *v;

    nFil=2; nCol=2;
    // printf("\nIntroduce el Nº de Filas:");
    // scanf("%i",&nFil);
    // printf("\nIntroduce el Nº de columnas:");
    // scanf("%i",&nCol);
    matriz = ReservamMemoria(nFil,nCol);

    RellenaMatriz(matriz,nFil,nCol);

    printf("La matriz generada aleatoriamente es:\n");
    imprimeMatriz(matriz,nFil,nCol);

    printf("El menor valor de cada columna es:\n");
    v = minimoColumna(matriz,nFil,nCol);
    for(int i=0; i<nCol; i++){
        printf("v[%i]: %i\n", i, v[i]);
    }

    liberaMemoria(*matriz, nFil);

}