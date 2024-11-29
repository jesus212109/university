#include <stdio.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc != 2){
        printf("ERROR: llamada deber de tener dos argumentos <%s> y <nombre del fichero>\n", argv[0]);
    }
    char* nombreFichero = argv[1];

    int x;
    printf("Introduzca una edad para aumentar en 1 la edad de estos alumnos: ");
    scanf("%i", &x);

    aumentoX(nombreFichero, x);
}