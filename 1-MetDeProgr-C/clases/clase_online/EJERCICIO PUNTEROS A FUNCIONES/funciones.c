/*
    Autor: Academia Main()
    Web: www.academiamain.es
    Contacto:  605 45 70 99 
*/
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    LA FUNCIÓN ejercicio() RECIBE COMO ARGUMENTOS UN VECTOR DE ELEMENTOS DE TIPO 
    DATO, UN INT QUE REPRESENTA EL TAMAÑO DEL VECTOR, Y UN INT QUE INDICA EL CRITERIO DE 
    ORDENACION:
        1 - ORDENARÁ POR NOMBRE ALFABÉTICAMENTE
        2 - ORDENARÁ POR PESO DESCENDENTEMENTE
        3-  ORDENARÁ POR CÓDIGO ASCENDENTEMENTE

    DESARROLLAR EL MÉTODO DE ORDENACIÓN QUE CONSIDERES.

    UTILIZAR PUNTEROS A FUNCIONES
*/

void ejercicio(struct dato * V, int nElementos, int criterio)
{
    if(criterio==1)
    {
        //COMPLETA AQUÍ
        ordena(V,nElementos,&nombre);
    }
    else if (criterio==2)
    {
        //COMPLETA AQUÍ
        ordena(V,nElementos,&peso);
    }
    else if (criterio==3)
    {
        //COMPLETA AQUÍ
        ordena(V,nElementos,&codigo);
    }
}

//COMPLETA AQUÍ CON LAS FUNCIONES QUE NECESITES
void ordena(struct dato *v, int tam,int (*funcion)(struct dato a, struct dato b))
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if ((*funcion)(v[i],v[j])==1)
            {
                struct dato aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int nombre(struct dato a, struct dato b)
{
    if(strcmp(a.nombre,b.nombre)>0)
    {
        return 1;
    }
    return 0;
}

int codigo(struct dato a, struct dato b)
{
    if(a.codigo > b.codigo)
    {
        return 1;
    }
    return 0;
}

int peso(struct dato a, struct dato b)
{
    if(a.peso < b.peso)
    {
        return 1;
    }
    return 0;
}