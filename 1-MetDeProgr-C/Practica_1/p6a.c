// 1. Recibe dos números a y b de tipo int pasados por valor.
// 2. Devuelve como resultado el mínimo de los números a y b pasados como parámetros.

#include <stdio.h>
#include "p6a.h"

int main(){
    int a, b,min;

    printf("\nIntroduzca el primer valor: \n");
    scanf("%i", &a);

    printf("\nIntroduzca el segundo valor: \n");
    scanf("%i", &b);
    
    min=min1(a,b);
    
     printf("\nEl valor mínimo es: %i\n", min);  
    //  porque al terminar se me imprime por pantalla un % si no termino con un \n?
}