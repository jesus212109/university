#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
#define SMAX 500
struct libro {      
   char titulo[100];
   char autor[50];
   float precio;
   int unid;
};

int menu();

void limpiarCadena(char* cadena);
void mostrarporNombre(char *nombreFichero);
struct libro *reservaMemoria(int n);
long tamanio(char* nombreFichero);
struct libro* ficheroAVector(char *fichero, long *nEle);
void listadoDesdeVector(char *fichero);
void addLibro(char* nombreFichero);
void venderLibro(char* nombreFichero);
void borrado(char* nombreFichero);

#endif