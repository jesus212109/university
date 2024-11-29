#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int tam = 6;
    int v[6] = {3,5,2,8,0,1};

    printf("Los datos del vector son:\n");
    mostrarVector(v,tam,0);


    return 0;
}