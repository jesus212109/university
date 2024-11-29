// Dada una cadena c, diseña una función recursiva que cuente la cantidad de veces que aparece un carácter x en c. 
// Ejemplo: para c = “elementos de programacion” y x = 'e', el resultado es 4 
#include <stdio.h>
#include "funciones.h"

int cuenta( const char c[], const char car ){
    if( c[0] == '\0'){
        return 0;
    }else{
        if ( car == c[0]){
            return 1 + cuenta(c + 1, car);
        }else{
            return 0 + cuenta(c + 1, car);
        }
    }
}