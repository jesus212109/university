// Escribe   una   función   que,   dado   un   vector   dinámico,   su   longitud   y   un   número   entero   (num),
// devuelva dos vectores dinámicos. Uno contendrá los elementos mayores  que  num  y otro los
// elementos   menores   o   iguales   que  num.   Implementa   un   pequeño   programa   para   probar   la
// función

//No es necesario el casting.

#include <stdio.h>
#include <stdlib.h>
#include "p2.h"

int main(){

    int *v = NULL, *vmayores = NULL, *vmenores = NULL;
    int tam, num, nmayores, nmenores;

    printf("Tamaño vector: ");
    scanf("%i",&tam);

    printf("Número para filtrar: ");
    scanf("%i",&num);

    v = malloc(sizeof(int) * tam);
    if (v == NULL){ 
        perror("\nError: no hay memoria\n");
        return -1;
    }

    rellenarVectorAleatorio(v,tam);
    printf("\nEl vector generado aleatoriamente es:\n");
    imprimirVector(v,tam);

    dividir(v,tam, num, &vmayores, &nmayores, &vmenores, &nmenores);
    printf("\nLos valores mayores al nº introducido son:\n");
    imprimirVector(vmayores, nmayores);

    free(v);
    free(vmayores);
    return 0;
}