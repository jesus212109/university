#include "p2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dividir(int *v,int tam,int num,int **vmayores,int *nmayores, int **vmenores, int *nmenores){
   
    //1.Contar mayores a num
    *nmayores = 0;
    for (int i=0; i<tam; i++){
        if(v[i] > num) {
            (*nmayores)++;
        }else{
            (*nmenores)++;
        }
    }

    //reservar memoria y comprobar
    *vmayores = calloc( sizeof(int) , (*nmayores));
     if (*vmayores == NULL){ 
        perror("\nError: no hay memoria\n");
    }

    //Rellenar el vector de mayores con los mayores
    *nmayores = 0;
    for (int i=0; i<tam; i++){
        if(v[i] > num) {
            (*vmayores)[*nmayores] = v[i];
            (*nmayores)++;
        }
    }

//me falta por implementar el vector de menores

}

void rellenarVectorAleatorio(int *v, int n){
    time_t t;
    srand((unsigned)time(&t));

    for(int i = 0; i < n; i++){
        v[i] = rand()%RAMDOMMAX + 1;
    }
}

void imprimirVector(int *v, int n){
    for(int i = 0; i < n; i++){  printf("\nEl elemento %i del vector es: %i",i ,*(v+i)); }
    printf("\n\n");
}