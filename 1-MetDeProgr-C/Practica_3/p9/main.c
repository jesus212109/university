// Escribe   una   solución   recursiva   que   calcule  el   algoritmo   de  Euclides, usado para calcular el
// máximo común divisor de dos enteros. El algoritmo de Euclides se describe del siguiente modo:
// mcd(x, y) = x, si y = 0 
// mcd(x, y) = mcd (y, mod(x,y)) si y > 0
// Antes de llamar a la función, comprobar que  x >= y

#include <stdio.h>
#include "funciones.h"
int main(){
    int x, y, r;

    x = 36;
    y = 14;
    r = mcd(x,y);
    printf("El MCD (%d,%d) es %d\n", x, y, r);

    x = 28;
    y = 14;
    r = mcd(x,y);
    printf("El MCD (%d,%d) es %d\n", x, y, r);

    return 0;
}