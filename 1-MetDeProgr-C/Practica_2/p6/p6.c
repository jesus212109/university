// Escribe un programa que lea una frase y, a partir de ella, cree un vector dinámico de cadenas
// con las diferentes palabras de la frase. A partir de este vector, el programa deberá:
// ●Calcular la longitud media de las palabras de la frase, así como la longitud mayor y menor
// (usando paso de parámetros por referencia).
// ●Construir un vector dinámico con la frecuencia de aparición de cada longitud.
// Realiza una adecuada modularización, implementando todas las funciones que sean necesarias.
// Suponer que las palabras de la frase están separadas por un único espacio en blanco. Si te resulta de
// utilidad, puedes usar la función strtok de string.h para obtener todas las palabras de la frase. Tienes
// un ejemplo de uso disponible en Moodle.

//No cae en el examen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p6.h"

int main(){ //Usar strtok(cadena,delimitador);  Devuelve la dirección de un vector de carácteres dinamino(una cadena dinámica)
    char aux[100],*cad;
    int *cantidadletras;

    if((cantidadletras=calloc(1, sizeof(int))) == NULL){
        printf("\nERROR: FALTA MEMORIA\n");
    }

    printf("\nIntroduce una cadena de carácteres: \n");
    fgets(aux , 100 , stdin);
    if((cad=calloc(strlen(aux) , sizeof(cad))) == NULL){
        printf("\nERROR: FALTA MEMORIA\n");
    }
    strcpy(cad, aux); 
  
    longitudes(cad,&cantidadletras);

    getchar();
    for(int i=0; i<1; i++){ //Aquí fallo
        printf("\n\n %i \n", cantidadletras[i]);
    }

}