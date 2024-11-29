#include <stdio.h>
#include "funciones.h"

void unionFich(char *fich1, char *fich2, char *fich3){
    FILE *f1, *f2, *f3;
    struct alumno aux;
    if((f1 = fopen(fich1, "r")) == NULL){
        perror("ERROR: No se ha podido abrir fich1");
    } else if ((f2 = fopen(fich2, "r")) == NULL){
        perror("ERROR: No se ha podido abrir fich2");
    } else if ((f3 = fopen(fich3, "w")) == NULL){
        perror("ERROR: No se ha podido abrir fich3");
    }
    while(fscanf(f1, "%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, &aux.edad, &aux.bil) != EOF){
        fprintf(f3,"%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, aux.edad, aux.bil);
    }
    while(fscanf(f2, "%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, &aux.edad, &aux.bil) != EOF){
        fprintf(f3,"%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, aux.edad, aux.bil);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);

}