#include <stdio.h>
#include "funciones.h"

// Codifica un programa en C que, utilizando funciones, abra un fichero de texto, cuyo nombre se
// pedirá al usuario, y genere un nuevo fichero llamado mayusculas-nombreFicheroDeEntrada.txt,
// que tenga el mismo contenido que el fichero original pero en mayúsculas

int main(){
    // FILE* f1, *f2;//Declaración de un fichero
    char cad1[150], cad2[300];
    printf("\nIntroduzca el nombre del archivo que se copiará en mayúsculas:\n");
    scanf("%s",cad1); 

    sprintf(cad2, "mayusculas-%s.txt", cad1); //sprintf aquí escribe en la propia cadena actualizandola más cómodamente.

    TodoMay(cad1, cad2);

} 