#include <stdio.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc != 4)
        perror("ERROR: Debes introducir además los nombres fich1, fich2 y fich resultado\n");
    char *nombreFich1 = argv[1];
    char *nombreFich2 = argv[2];
    char *nombreFich3 = argv[3];

    unionFich(nombreFich1,nombreFich2,nombreFich3);
} 