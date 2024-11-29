#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int tam = 6;
    int v[6] = {3,5,2,8,0,1};

    ordenarVector(v,tam,&ascendente);
    printf("Los elementos del vector son:\n");
    mostrarVector(v,tam);

    ordenarVector(v,tam,&descendente);
    printf("Los elementos del vector son:\n");
    mostrarVector(v,tam);


    return 0;
}