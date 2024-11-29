// Codifica   un   programa   en   C   que,   utilizando   funciones,   cree   un   fichero  binario  con   números
// enteros   generados   aleatoriamente   en   un   intervalo   especificado   por   el   usuario.   El   programa
// guardará los números en un vector dinámico antes de volcarlo a disco. El programa recibirá 4
// parámetros   como   argumentos   en  la   línea   de   órdenes:   nombre   del   fichero   a   crear,   número   de
// elementos que contendrá el fichero y los extremos superior e inferior del intervalo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void randInt(char *cad, int n, int max, int min){
    FILE* f;
    srand(time(NULL));
    int *v;

    v = (int *)malloc(n * sizeof(int));
    if (v == NULL)
    {
        printf("Error. No se pudo reservar memoria correctamente.\n");
        exit(-1);
    }

    if((f=fopen(cad, "wb"))==NULL){
        printf("\nError al abrir fichero %s\n", cad);
    }   
    for(int i=0; i<n; i++){
        v[i] = min + (rand()%(max-min +1));
    }  fwrite(v, sizeof(int) , n, f);

    free(v);
    v=NULL;
    fclose(f);
}