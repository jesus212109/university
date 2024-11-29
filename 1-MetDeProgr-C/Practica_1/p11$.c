// Implementa una programa que permita determinar si una cadena es prefijo o sufijo de otra.
// Utiliza la función strstr de la biblioteca <string.h> para implementar:

// -Una función que responda al siguiente prototipo: int es_prefijo(char *cadena, char
// *prefijo), que compruebe si una cadena es prefijo de otra. La función devolverá 1 si es
// prefijo y 0 en otro caso.

// -Una función que responda al siguiente prototipo: int es_sufijo(char *cadena, char *sufijo),
// que compruebe si una cadena es sufijo de otra. La función devolverá 1 si es sufijo y 0 en
// otro caso. Por simplicidad, suponer que un sufijo solo puede aparecer una vez en la cadena.
#include <stdio.h>
#include <string.h>
#include "p11.h"

int es_prefijo(char *cadena, char *prefijo){
    if(strstr(cadena, prefijo) != NULL){
        return 1;
    }else{
        return 0;
    }
}

int es_sufijo(char *cadena, char *sufijo){
     if(strstr(sufijo, cadena) != NULL){
        return 1;
    }else{
        return 0;
    }
}