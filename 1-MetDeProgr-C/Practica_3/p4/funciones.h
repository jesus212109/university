// #ifndef _FUNCIONES_H_
// #define _FUNCIONES_H_
#define SMAX 500

struct libro{      
   char titulo[SMAX];
   char autor[SMAX];
   float precio;
   int unid; //unid == unidades
};

int menu();
void limpiarCadena(char* cadena);
void mostrarLibro(char *fichero);
void introducirNuevo(char *fichero);
int contarDiferentes(char *fichero);
void desdeVect(char *fichero);
void ventaEjem(char *fichero);
void borrado(char *fichero);

// #endif
