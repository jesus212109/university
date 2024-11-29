#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void mostrarVector(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", v[i]);
    }
}

void ordenarVector(int *v, int tam,int (*funcion)(int a, int b))
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if ((*funcion)(v[i],v[j])==1)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int ascendente(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    return 0;
}

int descendente(int a, int b)
{
    if (a < b)
    {
        return 1;
    }
    return 0;
}
