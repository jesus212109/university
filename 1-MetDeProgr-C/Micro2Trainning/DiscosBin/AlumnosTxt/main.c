#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]){
    if( argc != 2){
        perror("ERROR: Se debe llamar al programa y al nombre del fichero\n");
        return -1;
    }
    char *nombreFichero = argv[1];
    eliminarX(nombreFichero);
} 