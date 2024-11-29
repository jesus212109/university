// Codifica   un   programa   en   C   que,   utilizando   funciones,   lea   números   enteros   desde   un   fichero
// binario generado en el ejercicio anterior, almacene sus valores en un vector dinámico y calcule la
// media de los números pares. El nombre del fichero se le preguntará al usuario.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void calcularMediaNumerosPares(char *nombreFichero, int *pares, float *media)
{
    FILE *fichero;
    int n;
    int cantidad;
    int i;
    int *v = NULL;

    fichero = fopen(nombreFichero, "rb");
    if (fichero == NULL)
    {
        printf("Error. El fichero: <%s> no se pudo abrir correctamente.\n", nombreFichero);
        exit(-1);
    }

    /*LECTURA DE LOS NUMEROS DEL FICHERO BINARIO*/
    cantidad = 0;
    while (fread(&n, sizeof(int), 1, fichero) == 1)
    {/*SE REDIMENSIONA EL VECTOR*/
        v = (int *)realloc(v, (cantidad + 1) * sizeof(int));
        /*SE COMPIA EL NUMERO LEIDO EN EL VECTOR*/
        v[cantidad] = n;
        cantidad++;
    }
    /*CALCULAMOS LA CANTIDAD DE PARES Y LA MEDIA DE ELLOS*/
    *pares = 0;
    *media = 0;
    for (i = 0; i < cantidad; i++){
        if (v[i] % 2 == 0){
            *media = *media + v[i];
            (*pares)++;
        }
    }
    *media = *media / (*pares);
    fclose(fichero);
}