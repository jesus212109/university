#ifndef FUNCIONES_H
#define FUNCIONES_H
#define SMAX 250

struct alumno{
    char nombre[SMAX];
    char apellido1[SMAX];
    char apellido2[SMAX];
    int edad, bil;  //bil = 0 == No bilingue, bil = 1 == Bilingue
};

void aumentoX(char* nombreFichero, int x);

#endif