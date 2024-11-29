#ifndef FUNCIONES_H
#define FUNCIONES_H

struct nodo
{
    int dato;
    struct nodo * siguiente;
};

void insertarDelante(struct nodo ** cabeza, int dato);

void insertarDetras(struct nodo ** cabeza, int dato);

void mostrarLista(struct nodo * cabeza);

struct nodo * nuevoElemento();

void borrarLista(struct nodo ** cabeza);

#endif