#ifndef FUNCIONES_H
#define FUNCIONES_H

void mostrarVector(int *v, int tam);
void ordenarVector(int *v, int tam,int (*funcion)(int a, int b));
int ascendente(int a, int b);
int descendente(int a, int b);

#endif