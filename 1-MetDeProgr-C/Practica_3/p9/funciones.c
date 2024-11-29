// Escribe   una   solución   recursiva   que   calcule  el   algoritmo   de  Euclides, usado para calcular el
// máximo común divisor de dos enteros. El algoritmo de Euclides se describe del siguiente modo:
// mcd(x, y) = x, si y = 0 
// mcd(x, y) = mcd (y, mod(x,y)) si y > 0
// Antes de llamar a la función, comprobar que  x >= y
#include <stdio.h>
#include "funciones.h"

int mcd(int x, int y){  //X >= Y necesario
    if ( y == 0){
        return x;
    }else if( y > 0){
        return mcd( y , x%y );
    }
}