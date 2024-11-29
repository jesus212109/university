#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int * reservarMemoria(int tam)
{
    int * v = NULL;
    v = (int *)malloc(sizeof(int)*tam);
    if(v==NULL)
    {
        printf("Error al reservar memoria\n");
        exit(-1);
    }
    return v;
}

void liberarMemoria(int * *vector)
{
    free(*vector);
    (*vector)=NULL;
}

void rellenarVector(int *v,int tam)
{
    printf("Procedemos a rellenar el vector:\n");
    for(int i=0;i<tam;i++)
    {
        printf("Introduce un número: ");
        scanf("%d",&v[i]);
    }
}

void mostrarVector(int *v,int tam)
{
    printf("Procedemos a mostrar el vector:\n");
    for(int i=0;i<tam;i++)
    {
        printf("%d\n",v[i]);
    }
}

void ordenarVector(int * v, int tam, int (*nombreFuncion)(int a, int b))
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if((*nombreFuncion)(v[i],v[j])==1)
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
    if(a>b)
    {
        return 1;
    }
    return 0;
}

int descendente(int a, int b)
{
    if(a<b)
    {
        return 1;
    }
    return 0;
}