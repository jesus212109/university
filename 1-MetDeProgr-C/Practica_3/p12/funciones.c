// Codifica una función recursiva que permita sumar los dígitos de un número. Implementa un
// programa para probarla.  Ejemplo: Entrada: 124 Resultado: 7.
#include <stdio.h>
#include "funciones.h"

int sumad(int n){
    int resto;
    resto = n % 10;
    if (resto == 0){
        return 0;
    }else{
        n = (n - resto) / 10;
        return resto + sumad(n);
    }
}