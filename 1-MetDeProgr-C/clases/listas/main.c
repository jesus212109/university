#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    //Creo una lista
    struct nodo * cabeza = NULL;

    //Inserto delante (pila)
    insertarDelante(&cabeza,1);
    insertarDelante(&cabeza,2);
    insertarDelante(&cabeza,3);

    //Mostrar la lista 
    printf("Los datos de la lista son:\n");
    mostrarLista(cabeza);

    //Insertar detras (cola)
    insertarDetras(&cabeza,4);
    insertarDetras(&cabeza,5);
    insertarDetras(&cabeza,6);

    //Mostrar la lista 
    printf("Los datos de la lista son:\n");
    mostrarLista(cabeza);

    //Borrar toda la lista
    borrarLista(&cabeza);

    return 0;
}