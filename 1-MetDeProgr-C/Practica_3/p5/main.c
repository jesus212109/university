#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// Codifica   un   programa   en   C   que,   utilizando   funciones,   cree   un   fichero  binario  con   números
// enteros   generados   aleatoriamente   en   un   intervalo   especificado   por   el   usuario.   El   programa
// guardará los números en un vector dinámico antes de volcarlo a disco. El programa recibirá 4
// parámetros   como   argumentos   en  la   línea   de   órdenes:   nombre   del   fichero   a   crear,   número   de
// elementos que contendrá el fichero y los extremos superior e inferior del intervalo

int main(int argc, char *argv[]){
    if (argc != 5)
    {
        printf("El programa se debe llamar de la sigueinte forma\n");
        printf("<%s> <nombre del fichero> <numero de datos> <inferior> <superior>\n",argv[0]);
    }

    char *cad;
    int n,min,max;

    cad=argv[1];
    n=atoi(argv[2]);
    min=atoi(argv[3]);
    max=atoi(argv[4]);

    randInt(cad, n, max, min);
}