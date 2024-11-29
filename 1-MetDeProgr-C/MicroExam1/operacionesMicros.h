#ifndef LIBMICORS_H
#define LIBMICROS_H

/* -------------------------------------
    Metodología de la Programación
    
    Fichero de cabecera ejercicios micros
----------------------------------------*/

//Definición de estructuras
struct persona{
  char nombre[100]; //NO puede contener espacios en blanco
  int edad; 
};


// ---------------------------------------------------
//      FUNCIONES PARA VECTORES DE FLOAT
//----------------------------------------------------
/* ---------------------------------------------------
   Funcion que rellena un vector de tam float
   leidos desde teclado

   Se le pasa: v -> dirección de inicio del vector  
               tam -> tamañao del vector

   Devuelve: nada
   --------------------------------------------------*/
void rellenarVectorFloat(float *v, int tam);

/* ---------------------------------------------------
   Funcion que imprime un vector de tam float por
   pantalla

   Se le pasa: v -> dirección de inicio del vector  
               tam -> tamañao del vector

   Devuelve: nada
   --------------------------------------------------*/
void imprimirVectorFloat(float *v, int tam);



// ---------------------------------------------------
//      FUNCIONES PARA VECTORES DE ENTEROS
//----------------------------------------------------

/* ---------------------------------------------------
   Funcion que rellena un vector de tam enteros
   leidos desde teclado

   Se le pasa: v -> dirección de inicio del vector  
               tam -> tamañao del vector

   Devuelve: nada
   --------------------------------------------------*/
void rellenarVectorInt(int *v, int tam);

/* ---------------------------------------------------
   Funcion que imprime un vector de tam enteros por
   pantalla

   Se le pasa: v -> dirección de inicio del vector  
               tam -> tamañao del vector

   Devuelve: nada
   --------------------------------------------------*/
void imprimirVectorInt(int *v, int tam);



// ---------------------------------------------------
//      FUNCIONES PARA MATRICES DE ENTEROS
//----------------------------------------------------

/* ------------------------------------------------
   Funcion que rellena una matriz de enteros preguntando
   los valores por teclado
   
   Se le pasa: m -> dirección de inicio de la matriz
               nFil -> nº de filas de la matriz
               nCol -> nº de columnas de la matriz

   Devuelve: nada

   Utiliza: nada
   ------------------------------------------------ */
void rellenarMatrizInt(int ** m, int nFil, int nCol);

/* ------------------------------------------------
   Funcion que imprime por pantalla una matriz de enteros
   
   Se le pasa: m -> dirección de inicio de la matriz
               nFil -> nº de filas de la matriz
               nCol -> nº de columnas de la matriz

   Devuelve: nada

   Utiliza: nada
   ------------------------------------------------ */
void imprimirMatrizInt(int ** m, int nFil, int nCol);



// ---------------------------------------------------
//      FUNCIONES PARA VECTORES DE ESTRUCTURAS
//----------------------------------------------------

/* ---------------------------------------------------
   Funcion que rellena un vector de tam alumnos
   leidos desde teclado.

   Se le pasa: v -> dirección de inicio del vector  
               tam -> tamaño del vector

   Devuelve: nada
   --------------------------------------------------*/
void rellenarVectorStruct(struct persona *v, int tam);

/* ---------------------------------------------------
   Funcion que imprime un vector de tam alumnos por
   pantalla

   Se le pasa: v -> dirección de inicio del vector  
               tam -> tamaño del vector

   Devuelve: nada
   --------------------------------------------------*/
void imprimirVectorStruct(struct persona *v, int tam);

#endif