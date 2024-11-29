// Escribe un programa que, utilizando estructuras, funciones y aritmética de punteros permita
// leer un vector de fracciones y multiplicar todas las fracciones del vector. Para ello se recomienda
// implementar las siguientes funciones:
// ◦ Una función para leer una fracción (numerador y denominador)
// ◦ Una función para imprimir una fracción (numerador y denominador)
// ◦ Multiplicar dos fracciones devolviendo por referencia la fracción resultado
#include <stdio.h>
#include "p12.h"

int main(){
    struct fraccion a,b,res;
    printf("\nIntroduce los datos de la fracción 1:\n");
    leerFraccion(&a);
    imprimirFraccion(a);

    printf("\nIntroduce los datos de la fracción 2:\n");
    leerFraccion(&b);
    imprimirFraccion(b);

    printf("\nEl resultado de la multiplicación de las dos fracciones anteriores es:\n");
    multiplicarFracciones(a,b,&res);
    imprimirFraccion(res);
}