#ifndef FUNCIONES_H
#define FUNCIONES_H

/**
@file funciones.h
@author Jesús Fernández López
@brief En este archivo contengo los tipos de datos y prototipos de las funciones que se me piden en el exámen.
@version 1.0.0
*/

/**
@fn struct persona* asignarMemoria(int n);
@author Jesús Fernández López
@brief Con esta función asigno a un puntero, un espacio en memoria del heap para trabajar con un vector de tipo struct persona
@param n se refiere al nº de elementos que tiene el vector
@return struct persona*, devuelve un puntero que tiene guardado la direccíon de memoria asignada en el heap
@version 1.0.0
*/
struct persona* asignarMemoria(int n);

void calculos( struct persona *v, int n, float *media, int *cont);
void liberarMemoria( struct persona *v);

#endif