#include <stdio.h>
#include "funciones.h"

int contarDiscos(char *fich){
    FILE* f;
    int tam;  
    if((f=fopen(fich, "rb"))==NULL){ 
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>",fich);
}  
    if(fseek(f, 0L, SEEK_END)){ 
        fprintf(stderr, "\nError: no puedo usar el fichero <%s>", fich);
    }  
    tam = ftell(f)/sizeof(struct disco);
    fclose(f);
    return tam;
}

void mostrarDatos(char *fich){
    FILE* f;
    if((f=fopen(fich, "rb"))==NULL){ 
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>",fich);
    }  
    struct disco aux;
    int i = 0;
    while(fread(&aux, sizeof(struct disco), 1, f) == 1){
        printf("Los datos del disco Nº%i son:\n", i+1);
        printf("Nombre:  %s\n", aux.nombre);
        printf("Autor:  %s\n", aux.autor);
        printf("Código:  %i\n", aux.cod);
        printf("Unidades:  %i\n\n", aux.unid);
        i++;
    }
    fclose(f);
}

void añadirDisco(char *fich){
    FILE* f;
    if((f=fopen(fich, "ab"))==NULL){ 
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>",fich);
    }  
    struct disco aux;
    printf("Introduzca los datos del nuevo disco:\n");
    printf("Nombre: ");
    scanf("%s", aux.nombre);
    printf("Autor: ");
    scanf("%s", aux.autor);
    getchar(); //evita problemas con el ultimo \n
    printf("Código : ");
    scanf("%i", &aux.cod);
    printf("Unidades: ");
    scanf("%i", &aux.unid);
    fwrite(&aux,sizeof(struct disco),1,f);
    fclose(f);
}

int masUnid(char *fich){
    FILE* f;
    int cod, unid = -1;
    printf("Introduzca el código del disco al cual incrementar unidades:\n");
    scanf("%i", &cod);
    struct disco aux;
    if((f=fopen(fich, "r+b"))==NULL){ 
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>",fich);
    }  
    while ((unid == -1) && (fread(&aux, sizeof(struct disco), 1, f) == 1)){
        if(cod == aux.cod){
            printf("introduzca la cantidad de unidades que se deben incrementar: ");
            scanf("%i", &unid);
            aux.unid += unid;
        }
        fseek(f, -(int)sizeof(struct disco), SEEK_CUR); // Retrocedemos una posicion para escribir el mismo que hemos leido
        fwrite(&aux, sizeof(struct disco), 1, f);
    }
    // printf("\n%i\n", unid);
    fclose(f);
    return unid;
}

void binToTxt(char *fbin, char *ftxt){
    FILE* f1, *f2;
    struct disco aux;
    if((f1=fopen(fbin, "rb"))==NULL){ 
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>",fbin);
    }  
    if((f2=fopen(ftxt, "w"))==NULL){ 
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>",ftxt);
    }  
    while (fread(&aux, sizeof(struct disco), 1, f1) == 1){
        fprintf(f2, "%s\n%s\n%i\n%i\n", aux.nombre, aux.autor, aux.cod, aux.unid);
    }
    fclose(f1);
    fclose(f2);
}