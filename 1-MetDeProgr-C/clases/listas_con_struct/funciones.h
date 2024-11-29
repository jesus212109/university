#ifndef FUNCIONES_H
#define FUNCIONES_H

struct libro
{
    char titulo[200];
    char autor[200];
    float precio;
};

struct nodo
{
    struct libro dato;
    struct nodo * siguiente;
};

struct nodo * nuevoElemento();
void insertarDetras(struct nodo ** cabeza, struct libro l);
void mostrarLista(struct nodo *cabeza);
void borrarLista(struct nodo **cabeza);
int buscarLibro(struct nodo * cabeza, char * titulo);
void ficheroAlista(char * nombreFichero, struct nodo ** cabeza);




#endif