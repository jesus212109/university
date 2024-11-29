#ifndef FUNCIONES_H
#define FUNCIONES_H

void rellenarVector(int *v,int tam);
void mostrarVector(int *v,int tam);
int * reservarMemoria(int tam);
void liberarMemoria(int * *vector);
void ordenarVector(int * v, int tam, int (*nombreFuncion)(int a, int b));
int ascendente(int a, int b);
int descendente(int a, int b);

#endif