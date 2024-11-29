#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarLista(struct nodo *cabeza)
{
    struct nodo *aux = cabeza;
    while (aux != NULL)
    {
        printf("Titulo: %s, Autor: %s, Precio: %f €\n",aux->dato.titulo, aux->dato.autor, aux->dato.precio);
        aux = aux->siguiente;
    }
}

struct nodo *nuevoElemento()
{
    struct nodo *nuevo = NULL;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevo == NULL)
    {
        printf("Error al reservar memoria para un nodo nuevo.\n");
        exit(-1);
    }
    return nuevo;
}

void insertarDetras(struct nodo **cabeza, struct libro l)
{
    struct nodo *nuevo = nuevoElemento();
    nuevo->dato = l;
    nuevo->siguiente = NULL;
    if ((*cabeza) == NULL)
    {
        (*cabeza) = nuevo;
    }
    else
    {
        struct nodo *aux = (*cabeza);
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void borrarLista(struct nodo **cabeza)
{
    struct nodo *aux = (*cabeza);
    while (aux != NULL)
    {
        (*cabeza) = (*cabeza)->siguiente;
        free(aux);
        aux = (*cabeza);
    }
}

int buscarLibro(struct nodo * cabeza, char * titulo)
{
    struct nodo * aux = cabeza;

    while(aux!=NULL && strcmp(aux->dato.titulo,titulo)!=0)
    {
        aux = aux->siguiente;
    }

    if(aux==NULL)
    {
        return 0;
    }

    return 1;

}

void ficheroAlista(char * nombreFichero, struct nodo ** cabeza)
{
    FILE * fich = fopen(nombreFichero,"r");
    if(fich==NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(-1);
    }

    struct libro l;
    while(fgets(l.titulo,200,fich))
    {
        l.titulo[strlen(l.titulo)-1]='\0';
        fgets(l.autor,200,fich);
        l.autor[strlen(l.autor)-1]='\0';
        fscanf(fich,"%f\n",&l.precio);

        insertarDetras(cabeza,l);
    }

    fclose(fich);
}