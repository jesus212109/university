#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
// Codifica un programa en C que, utilizando funciones, calcule la media de los elementos pares
// que hay en un fichero de texto generado por el ejercicio anterior. El nombre del fichero se pasará
// como argumento en la línea de órdenes.

void randInt(char *cad, int n, int max){
    FILE* f;
    srand(time(NULL));
    int aux;

    if((f=fopen(cad, "w"))==NULL){
        printf("\nError al abrir fichero %s\n", cad);
    }   
    for(int i=0; i<n; i++){
        aux=rand()%(max+1);
        fprintf(f, "%i\n", aux);
    }  
    fclose(f);
}

float medPar(char *cad, int n){
    FILE* f;
    int aux, cont = 0;
    float med = 0;

    if((f=fopen(cad, "r"))==NULL){
        printf("\nError al abrir fichero %s\n", cad);
        return -1;
    }   

    for(int i=0; i<n; i++){
        fscanf(f,"%i\n", &aux);
        if(aux % 2 == 0){
            med += aux;
            cont++;
        }
    } 
    med = med/cont;
    return med;

    fclose(f);
}