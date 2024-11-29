// Escribe un programa que implemente las siguientes funciones sobre matrices dinámicas y las
// llame de manera secuencial mostrando, de manera adecuada, la salida por pantalla. 
// ●float ** reservarMemoria (int nFil, int nCol).   Reserva memoria para una matriz de  nFil
// filas y nCol columnas. La reserva de memoria se realizará en un solo bloque.
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
#include <time.h>
#include "p4.h"

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

void rellenaMatriz (float **matriz, int nFil, int nCol){//Esto solo es posible ya que hemos hecho la reserva de la matriz en bloque
    float *v = matriz[0];
    time_t t;
    srand((unsigned)time(&t));

    for(int i = 0; i < nFil*nCol; i++){
        v[i] = rand()%RAMDOMMAX + 1;
    }
}

void imprimeMatriz (float **matriz, int nFil, int nCol){
     for(int i = 0; i < nFil; i++){
        for( int j = 0; j < nCol; j++){
            printf("\nEl contenido de la matriz en la posición [%i][%i] es : %f", i, j, matriz[i][j]);
        }
        printf("\n");
    }
}

float * maxFil (float **matriz, int nFil, int nCol){
    float *vmax, aux;
     if ( (vmax = calloc(sizeof(float), nFil)) == NULL){ 
        perror("\nError: no hay memoria\n");
    }

    for( int i=0; i<nFil; i++){
        aux = matriz[i][0];
        for( int j=0; j<nCol; j++){
            if(aux < matriz[i][j]){
                aux = matriz[i][j];
            }
        }
        vmax[i] = aux;
    }
    return vmax;
}

void imprimirVector(float *v, int n){
    for(int i = 0; i < n; i++){  printf("\nEl elemento %i del vector es: %f",i ,*(v+i)); }
    printf("\n\n");
}

void liberarMemoria(float ***matriz, int nFil){
    free((*matriz)[0]);
    free (*matriz);
    *matriz == NULL; 
}