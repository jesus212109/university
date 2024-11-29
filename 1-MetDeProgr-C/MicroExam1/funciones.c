#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "operacionesMicros.h"

struct persona* asignarMemoria(int n){
    struct persona* v;
    if((v = calloc(n, sizeof(struct persona))) == NULL){
        perror("\nERROR, no se ha podido reservar más memoria en el heap.\n");
    }
    return v;
}

void calculos( struct persona *v, int n, float *media, int *cont){
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma += v[i].edad;
    } *media = (float)suma/n;

    *cont = 0;
    for(int i = 0; i < n; i++){
        if(v[i].edad > 65){
            (*cont)++;
        }
    }
}

void liberarMemoria( struct persona *v){
    free(v);
    v = NULL;
}