#include <stdio.h>
#include "funciones.h"

// Codifica un programa en C que, utilizando funciones, calcule la media de los elementos pares
// que hay en un fichero de texto generado por el ejercicio anterior. El nombre del fichero se pasará
// como argumento en la línea de órdenes.

int main(){
    char cad[100];
    int n, max;
    float med;
    printf("\nIntroduzca el nombre del archivo :\n");
    scanf("%s",cad);    
    printf("\nIntroduzca la cantidad de elementos:\n");
    scanf("%i",&n); 
    printf("\nIntroduzca el valor máx para la generación de Nº:\n");
    scanf("%i",&max);

    randInt(cad ,n,max);

    med = medPar(cad, n);
    printf("La media de los elementos pares es = %f\n\n", med);

} 