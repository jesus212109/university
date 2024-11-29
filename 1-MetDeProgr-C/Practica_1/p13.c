// Un proyecto informático requiere trabajar con vectores de números enteros generados de
// manera aleatoria. Para hacer más rápido el acceso, han decidido crear dos índices que les
// permitan recorrer solamente los divisibles por 3 o los elementos impares. Un índice, es un vector
// de punteros, que almacena la dirección de los elementos que se quieren recorrer. Escribe un
// programa que:
// •Rellene un vector de enteros con números aleatorios (en un rango fijado por el usuario).
// •Imprima el vector completo.
// •Cree un índice con las direcciones de los elementos impares del vector original.
// •Cree un índice con las direcciones de los divisibles por 3 que hay en el vector original.
// •Imprima, usando los índices, los elementos impares y los divisibles por 3.
// Implementa, al menos, las funciones: rellenarVectorAleatorio, imprimirVector, crearndiceImpares,
// crearIndicesDivisibles, imprimeIndice.
#include <stdio.h>
#include "p13.h"
int main(){

    int v[VMAX];
    int *vImp[VMAX], *vDiv[VMAX];
    int nImp,nDiv;

    rellenarVectorAleatorio(v ,VMAX);
    imprimirVector(v, VMAX);

    crearIndiceImpares(v,VMAX,vImp,&nImp);
    imprimeIndice(vImp, nImp);
    
    crearIndicesDivisibles(v, VMAX, vDiv, &nDiv);
    imprimeIndice(vDiv, nDiv);
    
}