#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "p8.h"
// número de dígitos, mayúsculas, minúsculas y espacios que hay en la cadena. 
void estadisticasCadena(char cad[], int *ndig, int *nmay, int *nmin, int *nesp){
   
    for(int i=0;i<strlen(cad);i++){ //Cómo lo haría con sizeof?

        if(isdigit(cad[i])){(*ndig)++;}
            else{if(isupper(cad[i])){(*nmay)++;}
                else{if(islower(cad[i])){(*nmin)++;}
                    else{if(cad[i]==' '){(*nesp)++;}
                }
            }
        }

    }
    
    printf("\nLa cadena tiene %i dígitos, %i mayúsculas, %i minúsculas, y %i espacios\n\n",*ndig, *nmay, *nmin, *nesp);

}