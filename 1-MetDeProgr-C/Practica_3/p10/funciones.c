// Construye una  función recursiva  que calcule  la división entera de dos números mediante el
// método de restas sucesivas. Implementa un pequeño programa para probarla.7. Por ejemplo, si
// 28  es   el  dividendo  y  9  el   divisor,  el   programa   irá  restando   el  divisor  al dividendo  de  forma
// sucesiva, mientras el dividendo sea mayor o igual que 0. el número de veces que se haga esta
// resta será la división entera. 
//  28 – 9 = 19 > 0 (1 vez)
//  19 -9 = 10 > 0 (2 veces)
//  10 -9 = 1 > 0 (3 veces)
//  1 -9 = -8 < 0 (esta no cuenta).
//  Por tanto, la división entera es 3, ya que se han realizado 3 iteraciones.
#include <stdio.h>
#include "funciones.h"

int dividirR(int a, int b){// a debe ser > b
    
    if( a < b ){
        return 0;//falla meter un contador para el resultado.
    }else{
        return 1 + dividirR((a-b),b);
    }
}