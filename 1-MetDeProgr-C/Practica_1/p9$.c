// a) Implementa una función denominada leerMonomio, que reciba una estructura pasada por
// referencia y permita leer los datos de un monomio.
// b) Implementa una función denominada imprimirMonomio, que reciba una estructura por
// valor y muestre el coeficiente y el grado del monomio.
// c) Utilizando las funciones anteriores, en el programa principal lee y escribe un polinomio
// (vector de monomios). Por simplicidad, no introducir monomios con el mismo exponente.
// d) Crea una función que, usando paso de parámetros por referencia, devuelva el monomio de
// mayor grado y el de menor grado. Utilízala en tu programa.
// e) Crea un función que evalúe un polinomio en un punto X. /Utilízala en tu programa. susituyo x en el polinomio
#include <stdio.h>
#include "p9.h"

void leerMonomio(struct monomio* ptra){
    int aux1,aux2;
   printf("El coefinciente es = ");
   scanf("%i", &aux1);
   ptra->coeficiente=aux1;
   printf("y el grado es = ");
   scanf("%i", &aux2);
   ptra->grado=aux2;
   //printf("El coefinciente es = %i y su grado = %i \n\n", ptra->coeficiente, ptra->grado);
}

void imprimirMonomio(struct monomio a){
     printf("El coefinciente es = %i y su grado = %i \n\n", a.coeficiente, a.grado);
}

void maximinGrado(struct monomio* ptra, struct monomio* max, struct monomio* min, int n){
     
     *max = ptra[0];
     *min = ptra[0];
     
     for(int i=0; i<n; i++){//Aquí se pueden apreciar los dos tipos de llamadas hacia una sección de ptra
          if((ptra[i].grado) > (max->grado)){
               *max = ptra[i];
          }
          if(((ptra+i)->grado) < min->grado){
               *min = ptra[i];
          }
    }
    printf("\nEl monomio de mayor grado es de coefinciente = %i y su grado = %i ", max->coeficiente, max->grado);
    printf("\nEl monomio de mínimo grado es de coefinciente = %i y su grado = %i \n\n", min->coeficiente, min->grado);
}

float evalx(struct monomio* ptra, float x, int n){
     float res=0;
     for(int i=0; i<n; i++){
        res+=ptra[i].coeficiente*(pow(x,ptra[i].grado));
     }
     printf("\nEl valor del polinomio para x = %f  es %f\n",x, res);
     return res;
}