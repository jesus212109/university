#include <stdio.h>
#include <math.h>
#include "p7.h"

void imprimevector(int v[],int n){
    for(int i=0; i<n; i++){
        printf("\nEl elemento %i del vector es: %i\n",i,v[i]);
    }
}

void estadisticasVector(int v[], int n, float *med, float *var, float *des){
    for(int i=0; i<n; i++){
        *med+=v[i];
    }*med=*med/n;

    for(int i=0; i<n; i++){
        *var+=(v[i]-*med)*(v[i]-*med);
    }*var/=n;

    *des=sqrt(*var);

    printf("\nmed=%f, var=%f, des=%f\n", *med, *var, *des);
}