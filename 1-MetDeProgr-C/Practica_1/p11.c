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

int main(){
    char cad1[] = "hola me llamo jesus";
    char cad2[] = "jesus";
    //1=true     0=false
    printf("\n el resultado es: %i\n\n", es_prefijo(cad1,cad2)); //¿cad1 pref de cad2?
    printf("\n el resultado es: %i\n\n", es_prefijo(cad2,cad1)); //¿cad2 pref de cad1?

    printf("\n el resultado es: %i\n\n", es_sufijo(cad1,cad2));  //¿cad1 suf de cad2?
    printf("\n el resultado es: %i\n\n", es_sufijo(cad2,cad1));  //¿cad2 suf de cad1?
}