#include <stdio.h>
#include <math.h>
#include "p7.h"

// Codifica una función denominada estadisticasVector que reciba un vector de enteros y calcule,
// devolviendo mediante paso de parámetros por referencia, la media, la varianza y la desviación
// típica de los datos del vector. Implementa un programa que mediante funciones lea un vector de
// enteros, lo imprima por pantalla, calcule las estadísticas y finalmente muestre los resultados.

int main(){
    int v[]={0,10,20,30,40,50,60,70,80,90}, n=10;
    float med=0, var=0, des=0;

    imprimevector( v , n);

    estadisticasVector(v, 10, &med, &var, &des);

}