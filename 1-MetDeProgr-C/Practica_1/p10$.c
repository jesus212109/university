// Codifica un programa que usando funciones y aritmética de punteros:
// Lea un vector de elementos tipo double (leeVector).
// Imprima los datos del vector por pantalla (escribeVector).
// Sume los elementos mayores que cero del vector (sumaPositivos).
#include <stdio.h>
#include "p10.h"

void leeVector(double* v){
    for(int i=0; i < MAX; i++){
        printf("\nIntroduzca el elemento %i del vector: ",i );
        scanf("%lf", (v+i));
        printf("\n");

    }
}

void escribeVector(double v[]){
    for (int i = 0; i < MAX; i++){
        printf("\nEl elemento %i del vector es: %lf\n",i,*(v + i));
    }
}

double sumaPositivos(double v[]){
    double s=0;
    for(int i = 0; i < MAX; i++){
        if(*(v + i) > 0){
            s+=*(v + i);
        }
    }
    return s;
}