#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrarVector(int * v,int tam, int i)
{
    if(i<tam)
    {
        printf("%d\n",v[i]);
        mostrarVector(v,tam,i+1);
    }
}









