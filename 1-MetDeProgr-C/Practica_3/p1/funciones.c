// Codifica un programa en C que, utilizando funciones, abra un fichero de texto, cuyo nombre se
// pedirá al usuario, y genere un nuevo fichero llamado mayusculas-nombreFicheroDeEntrada.txt,
// que tenga el mismo contenido que el fichero original pero en mayúsculas
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"

//----------------------------------------------------------
//Funcion: TodoMay
//Tarea: Combierte todos los caracteres a mayusculas
//Recibe: cad1 ->Nombre del fichero origen
//        nombreDestion->Nombre del fichero destino
//Devuelve (int): 1 si se ha podido efectuar con exito
//                0 en caso contrario
//----------------------------------------------------------
void TodoMay(char* cad1, char* cad2){
    FILE* f1, * f2;
    char aux;

    //Apertura del fichero para lectura 
    if((f1=fopen(cad1, "r"))==NULL){
        printf("\nError al abrir fichero %s, Añada si es necesario.txt\n", cad1);
    }else if((f2=fopen(cad2, "w"))==NULL){
            printf("\nError al abrir fichero %s\n",cad2);
            fclose(f1);
        }else{  
            while((aux=fgetc(f1))!=EOF){
                fputc(toupper(aux), f2);
            }  
            printf("Completado exitosamente\n\n");
            fclose(f1);
            fclose(f2);
        }     
    
}