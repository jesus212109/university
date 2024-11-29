// Codifica una función recursiva que permita calcular el valor de π usando la serie de Leibniz.
// Escribe un programa para probarla que pedirá al usuario que introduzca el número n de términos
// a usar en la aproximación.  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
int main(){

int n = 150;

printf("Res = %lf\n",obtenerPI(n));

}