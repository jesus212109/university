// Escribe un programa que lea una frase y, a partir de ella, cree un vector dinámico de cadenas
// con las diferentes palabras de la frase. A partir de este vector, el programa deberá:
// ●Calcular la longitud media de las palabras de la frase, así como la longitud mayor y menor
// (usando paso de parámetros por referencia).
// ●Construir un vector dinámico con la frecuencia de aparición de cada longitud.
// Realiza una adecuada modularización, implementando todas las funciones que sean necesarias.
// Suponer que las palabras de la frase están separadas por un único espacio en blanco. Si te resulta de
// utilidad, puedes usar la función strtok de string.h para obtener todas las palabras de la frase. Tienes
// un ejemplo de uso disponible en Moodle.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p6.h"

void longitudes(char * cad, int** longitud){
    int max = strlen(cad);
    int contpalabras=0,contletras=0;
    for (int i=0; i<max; i++){
        contletras++;  
        if(cad[i] == ' '){//cuando se acabe la palabra
            (*longitud)[contpalabras]=contletras; //guardo en un vector de int cantidad de letras en cada palabra
            contpalabras++;
            *longitud = realloc( *longitud, (contpalabras+1) * sizeof( int ) );
            contletras = 0; //inicializo la cantidad de letras de la siguiente palabra
        }
        
    }

}

void estadisticas(char **tokens, int ntokens, float *media,int *nmax, int *nmin){
    for(int i=0; i<ntokens; i++){
        longitud = strlen(tokens[i]);
        //actualizar suma,max y min
    }
    //calcular media
}