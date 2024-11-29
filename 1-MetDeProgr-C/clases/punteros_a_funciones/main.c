#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    if(argc!=3)
    {
        printf("Debe introducir el tamaño del vector\n");
        exit(-1);
    }

    int tam = atoi(argv[1]);
    int tipo_ordenacion = atoi(argv[2]);

    int * v = reservarMemoria(tam);

    rellenarVector(v,tam);

    if(tipo_ordenacion==0)
    {
        ordenarVector(v,tam,&descendente);
    }
    else
    {
        ordenarVector(v,tam,&ascendente);
    }

    mostrarVector(v,tam);

    liberarMemoria(&v);

    return 0;
}