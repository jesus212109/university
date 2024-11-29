// Codifica una función recursiva que permita sumar los dígitos de un número. Implementa un
// programa para probarla.  Ejemplo: Entrada: 124 Resultado: 7.
#include <stdio.h>
#include "funciones.h"
int main(){

    int n = 124;
    int suma = sumad(n);

    printf(" La suma de cada cifra es = %d\n", suma);

}