#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    struct nodo * cabeza = NULL;

    ficheroAlista("libros.txt",&cabeza);

    //Mostrar la lista
    printf("Los datos de la lista son:\n");
    mostrarLista(cabeza);

    //Borrado de toda la lista
    borrarLista(&cabeza);

    return 0;
}