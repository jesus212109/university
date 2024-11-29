#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
// Codifica un programa en C que, utilizando funciones, cree un fichero texto con números enteros
// generados aleatoriamente en un intervalo especificado por el usuario. El programa le preguntará
// al usuario el nombre del fichero a crear, el número de elementos que contendrá el fichero y los
// extremos superior e inferior del intervalo.

void randInt(char *cad, int n, int max){
    FILE* f;
    srand(time(NULL));
    int aux;

    if((f=fopen(cad, "w"))==NULL){
        printf("\nError al abrir fichero %s\n", cad);
    }   
    for(int i=0; i<n; i++){
        aux=rand()%(max+1);
        fprintf(f, "El valor Nº%i es: %i\n", i, aux);
        // fputc(' ', f);
    }  
    fclose(f);
}
