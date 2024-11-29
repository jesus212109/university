// Codifica un programa que usando funciones y aritmética de punteros:
// Lea un vector de elementos tipo double (leeVector).
// Imprima los datos del vector por pantalla (escribeVector).
// Sume los elementos mayores que cero del vector (sumaPositivos).
#include <stdio.h>
#include "p10.h"

int main(){

    double v[MAX];

    leeVector(v);
    escribeVector(v);
    printf("\nLa suma de los elementos positivos es = %lf\n", sumaPositivos(v));

}