// a) Implementa una función denominada leerMonomio, que reciba una estructura pasada por
// referencia y permita leer los datos de un monomio.
// b) Implementa una función denominada imprimirMonomio, que reciba una estructura por
// valor y muestre el coeficiente y el grado del monomio.
// c) Utilizando las funciones anteriores, en el programa principal lee y escribe un polinomio
// (vector de monomios). Por simplicidad, no introducir monomios con el mismo exponente.
// d) Crea una función que, usando paso de parámetros por referencia, devuelva el monomio de
// mayor grado y el de menor grado. Utilízala en tu programa.
// e) Crea un función que evalúe un polinomio en un punto X. Utilízala en tu programa./ susituyo x en el polinomio
#include <stdio.h>
#include "p9.h"

int main(){

  printf("\nIntruduce el número de términos que se vallan a emplear\n");
  int n;
  scanf("%i",&n);

  struct monomio v[n];
  float x;

  printf("Construye un polinomio a partir de monomios: \n\n");
  for(int i=0; i<n; i++){
    leerMonomio(&(v[i]));
    printf("\n");
  }
  printf("\n\nEl polinomio introducido se compone de los siguientes monomios: \n\n");
  for(int i=0; i<n; i++){
      printf("El monomio nº %i: \n",i+1);
      imprimirMonomio(v[i]);
      // printf("\n");
  }
  struct monomio max,min;
  maximinGrado(v, &max, &min, n);

  printf("\nIntroduce un valor de X para sustituir en el polinomio\n");
  scanf("%f", &x);
  evalx(v, x, n);

}