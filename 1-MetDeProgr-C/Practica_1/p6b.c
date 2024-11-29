// Segunda versión: función denominada minimo_referencia
// 1. Recibe dos números num1 y num2 de tipo int pasados por valor.
// 2. Recibe otro parámetro denominado resultado de tipo int pero pasado por referencia.

#include <stdio.h>
#include "p6b.h"

int main(){
    int a, b,min;

    printf("\nIntroduzca el primer valor: \n");
    scanf("%i", &a);

    printf("\nIntroduzca el segundo valor: \n");
    scanf("%i", &b);
    
    min2(a,b,&min);
    
    printf("\nEl valor mínimo es: %i\n", min);  
}