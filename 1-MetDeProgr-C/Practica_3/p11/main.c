// Dada una cadena c, diseña una función recursiva que cuente la cantidad de veces que aparece un carácter x en c. 
// Ejemplo: para c = “elementos de programacion” y x = 'e', el resultado es 4 
#include <stdio.h>
#include "funciones.h"
int main(){

char cad[] = " Hola, muy buenas tardes, mi tita se llama Manolo";
char car = 'e';

printf(" El car %c aparece %d veces\n", car, cuenta(cad, car));
}