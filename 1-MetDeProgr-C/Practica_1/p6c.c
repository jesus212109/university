// Codifica un programa que permita comprobar el funcionamiento de las dos funciones
// anteriores.

#include <stdio.h>
#include "p6c.h"

int main(){
    int a=0, b=0,min;

    printf("\n Si no aparece ningún mensaje de error significa que las dos funciones anteriores superan todos los test \n");

    min = min1(a+5,b-5);
    if(min != b-5) { printf("\n ERROR1 \n");  }

    min = min1(a-15,b+15);
    if(min != a-15) { printf("\n ERROR2 \n");  }
    
    min2(a+5,b-5,&min);
    if(min != b-5) { printf("\n ERROR3 \n");  }

    min2(a-15,b+15,&min);
    if(min != a-15) { printf("\n ERROR4 \n");  }
    
}