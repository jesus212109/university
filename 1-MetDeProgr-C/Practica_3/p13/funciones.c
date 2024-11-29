// Codifica una función recursiva que permita calcular el valor de π usando la serie de Leibniz.
// Escribe un programa para probarla que pedirá al usuario que introduzca el número n de términos
// a usar en la aproximación.  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

double obtenerPI(int n){
    if( n >= 0){
        double res = 4 * ((pow((-1),n))/((2*n) + 1)) + obtenerPI(n-1);
        printf("res = %lf\n", res);
        return res;
    }else{
        return 0;
    }
}