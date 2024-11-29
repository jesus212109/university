#include <stdio.h>
#include "funciones.h"

void aumentoX(char* nombreFichero, int x){
    FILE *f1, *f2;
    struct alumno aux;
    int encontrado = 0;
    if((f1 = fopen(nombreFichero, "r")) == NULL){
        perror("ERROR al abrir el fichero\n");
    }
     if((f2 = fopen("temp", "w")) == NULL){
        perror("ERROR al abrir el fichero\n");
    }

    while(fscanf(f1, "%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, &aux.edad, &aux.bil) != EOF){
        // printf("%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, aux.edad, aux.bil);
        if(x == aux.edad){
            aux.edad++;
            encontrado = 1;
        }
        fprintf(f2, "%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, aux.edad, aux.bil);
    }

    if(encontrado != 0){
        remove(nombreFichero);
        rename("temp", nombreFichero);
        printf("El fichero ha sido actualizado correctamente\n");
    }else{
        remove("temp");
        printf("El fichero NO ha sido actualizado no hay ningún alumno de %i años\n", x);
    }

    fclose(f1);
    fclose(f2);
}