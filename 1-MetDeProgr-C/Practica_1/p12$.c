// Escribe un programa que, utilizando estructuras, funciones y aritmética de punteros permita
// leer un vector de fracciones y multiplicar todas las fracciones del vector. Para ello se recomienda
// implementar las siguientes funciones:
// ◦ Una función para leer una fracción (numerador y denominador)
// ◦ Una función para imprimir una fracción (numerador y denominador)
// ◦ Multiplicar dos fracciones devolviendo por referencia la fracción resultado
#include <stdio.h>
#include "p12.h"

void leerFraccion(struct fraccion* ptra){
    int aux1,aux2;
    printf("\nEl numerador es = ");
    scanf("%i", &aux1);
    ptra->numerador=aux1;
    printf("y el denominador es = ");
    scanf("%i", &aux2);
    ptra->denominador=aux2;
}

void imprimirFraccion(struct fraccion a){
    printf("\nEl numerador es = %i y su denominador = %i \n\n", a.numerador, a.denominador);
}

void multiplicarFracciones(struct fraccion a, struct fraccion b, struct fraccion* res){
    res->denominador = (a.denominador)*(b.denominador);
    res->numerador = (a.numerador)*(b.numerador);
}