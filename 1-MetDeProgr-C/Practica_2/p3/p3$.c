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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p3.h"

/**
 * @fn Imprime Matriz
 * @brief  E
 * @param
 * @param
 * @param
 * @return nada
*/

int **ReservamMemoria(int nFil, int nCol){
    int **matriz;
    if((matriz=calloc(nFil,sizeof(int*))) == NULL){
        perror("ERROR al asignar memoria");
    }
    for(int i=0; i<nCol; i++){
        if((matriz[i]=calloc(nCol,sizeof(int))) == NULL){
        perror("ERROR al asignar memoria");
        }
    }

return matriz;
}

void RellenaMatriz(int **matriz, int nFil, int nCol){
    srand(time(NULL));

    for(int i=0; i<nFil;i++){
        for(int j=0; j<nCol; j++){
            *(*(matriz+i)+j) = rand()%21;
        }
    }
}

void imprimeMatriz(int **matriz, int nFil, int nCol){
    for(int i=0; i<nFil;i++){
        for(int j=0; j<nCol; j++){
            printf("m[%d][%d]:%d\n",i,j,*(*(matriz+j)+i));
        }
        printf("\n");
    }
}


int * minimoColumna(int **matriz, int nFil, int nCol){
     int *vmax, aux;
     if ( (vmax = calloc(nFil,sizeof(int))) == NULL){ 
        perror("\nError: no hay memoria\n");
    }

    for( int i=0; i<nCol; i++){
        aux = matriz[0][i];
        for( int j=0; j<nFil; j++){
            if(aux > matriz[j][i]){
                aux = matriz[j][i];
            }
        }
        vmax[i] = aux;
    }
    return vmax;
}

void liberaMemoria(int ***matriz, int nFil){
    for(int i=0; i < nFil; i++){
        free((*matriz)+i); //=(*matriz)[i]
    }
    free(*matriz);
    *matriz = NULL;   //Podemos hacer esto garcias a que hemos pasado la matriz por referencia
}