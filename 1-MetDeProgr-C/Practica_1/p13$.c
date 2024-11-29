// Un proyecto informático requiere trabajar con vectores de números enteros generados de
// manera aleatoria. Para hacer más rápido el acceso, han decidido crear dos índices que les
// permitan recorrer solamente los divisibles por 3 o los elementos impares. Un índice, es un vector
// de punteros, que almacena la dirección de los elementos que se quieren recorrer. Escribe un
// programa que:
// •Rellene un vector de enteros con números aleatorios (en un rango fijado por el usuario).
// •Imprima el vector completo.
// •Cree un índice con las direcciones de los elementos impares del vector original.
// •Cree un índice con las direcciones de los divisibles por 3 que hay en el vector original.
// •Imprima, usando los índices, los elementos impares y los divisibles por 3.
// Implementa, al menos, las funciones: rellenarVectorAleatorio, imprimirVector, crearndiceImpares,
// crearIndicesDivisibles, imprimeIndice.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p13.h"

void rellenarVectorAleatorio(int *v, int n){
    time_t t;
    srand((unsigned)time(&t));

    for(int i = 0; i < n; i++){
        v[i] = rand()%30;
    }
}

void imprimirVector(int *v, int n){
    for(int i = 0; i < n; i++){  printf("\nEl elemento %i del vector es: %i",i ,*(v+i)); }
    printf("\n\n");
}

void crearIndiceImpares(int v[], int n, int *vImp[], int *nImp){
    (*nImp) = 0;
    for (int i=0; i<n ;i++){
        if(v[i] %2!= 0){
            vImp[(*nImp)] = &v[i];  //vImp+*nImp = v+i;
            (*nImp)++;
        }
        
    }
}

void crearIndicesDivisibles(int v[],int n, int *vDiv[], int* nDiv){
    (*nDiv) = 0;
    for( int i = 0; i < n ; i++) {
        if(v[i] %3 == 0){
            vDiv[(*nDiv)] = &v[i];  //vDiv+*nDiv = v+i;
            (*nDiv)++;
        }
    }
}

void imprimeIndice(int *vImp[], int n){
    for(int i = 0; i < n; i++){  printf("\nEl elemento %i del indice es: %i",i ,*vImp[i]); }
    printf("\n\n");
}