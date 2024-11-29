#include <stdio.h>
#include "funciones.h"

// Codifica un programa en C que, utilizando funciones, cree un fichero texto con números enteros
// generados aleatoriamente en un intervalo especificado por el usuario. El programa le preguntará
// al usuario el nombre del fichero a crear, el número de elementos que contendrá el fichero y los
// extremos superior e inferior del intervalo.

int main(){
    char cad[100];
    int n, max;
    printf("\nIntroduzca el nombre del archivo :\n");
    scanf("%s",cad);    
    printf("\nIntroduzca la cantidad de elementos:\n");
    scanf("%i",&n); 
    printf("\nIntroduzca el valor máx para la generación de Nº:\n");
    scanf("%i",&max);

    randInt(cad ,n,max);

} 