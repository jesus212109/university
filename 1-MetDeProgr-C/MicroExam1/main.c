#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "operacionesMicros.h"

int main(){
    struct persona *v;
    int nEle, cont;
    float media;

    printf("\nIntroduzca el nº de elementos de su vector: ");
    scanf("%i", &nEle);

    v = asignarMemoria(nEle);

    rellenarVectorStruct(v ,nEle);
    imprimirVectorStruct(v , nEle);

    calculos( v, nEle, &media, &cont);
    printf("\nLa media de la es = %f y el nº de personas de edad mayor a 65 = %i\n", media, cont);
    
    liberarMemoria(v);
}