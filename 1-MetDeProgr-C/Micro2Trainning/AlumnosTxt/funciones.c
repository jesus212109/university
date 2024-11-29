#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
void eliminarX(char *fichero){
    FILE *f1, *f2;
    if((f1 = fopen(fichero, "r")) == NULL){
        printf("No ha sido posible abrir el fichero <%s>\n", fichero);
    }
    if((f2 = fopen("temp", "w")) == NULL){
        printf("No ha sido posible abrir el fichero <%s>\n", fichero);
    }
    int x, encontrado = 0;
    struct alumno aux;
    printf("Introduzca un valor de edad para eliminar los alumnos con dicha edad\n");
    scanf("%i", &x);

    while((!encontrado) && ((fscanf(f1,"%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, &aux.edad, &aux.bil)) != EOF)){
        // printf("%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, aux.edad, aux.bil);
        if(x != aux.edad){
            fprintf(f2,"%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, aux.edad, aux.bil);
        }else{
            encontrado = 1;
        }
    }
    fclose(f1);
    fclose(f2);
    if(encontrado == 1){
        printf("Se ha realizado correctamente el borrado\n");
        remove(fichero);
        rename("temp", fichero);
        }else{
            printf("No ha sido necesario realizar el borrado\n");
            remove("temp");
        }
}