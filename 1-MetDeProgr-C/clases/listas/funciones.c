#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

struct nodo *nuevoElemento()
{
    struct nodo *nuevo = NULL;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevo == NULL)
    {
        printf("Error al reservar memoria para el nodo nuevo.\n");
        exit(-1);
    }
    return nuevo;
}

void insertarDelante(struct nodo **cabeza, int dato)
{
    struct nodo *nuevo = nuevoElemento();
    nuevo->dato = dato;
    nuevo->siguiente = (*cabeza);
    (*cabeza) = nuevo;
}

void mostrarLista(struct nodo *cabeza)
{
    struct nodo *auxiliar = cabeza;
    while (auxiliar != NULL)
    {
        printf("%d\n", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
    }
}

void insertarDetras(struct nodo **cabeza, int dato)
{
    struct nodo *nuevo = nuevoElemento();
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    if ((*cabeza) == NULL)
    {
        (*cabeza) = nuevo;
    }
    else
    {
        struct nodo *auxiliar = (*cabeza);
        while (auxiliar->siguiente != NULL)
        {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevo;
    }
}

void borrarLista(struct nodo **cabeza)
{
    struct nodo *auxiliar = (*cabeza);
    while (auxiliar != NULL)
    {
        (*cabeza) = (*cabeza)->siguiente;
        free(auxiliar);
        auxiliar = (*cabeza);
    }
}