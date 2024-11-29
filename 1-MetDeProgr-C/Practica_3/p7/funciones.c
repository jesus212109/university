#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "funciones.h"
int menu(){
    int opcion;

    CLEAR_SCREEN;
    LUGAR(5, 10);
    BBLUE;
    printf("Opciones del menú");
    RESET;

    LUGAR(6, 10);
    printf("1.- Comprobar si existe un libro y mostrar sus datos en su caso.");

    LUGAR(7, 10);
    printf("2.- Introducir un libro: si ya existe, se incrementarán sus ejemplares.");

    LUGAR(8, 10);
    printf("3.- Contar el número de libros con títulos diferentes.");

    LUGAR(9, 10);
    printf("4.- Listar los libros del fichero almacenándolos previamente en un vector.");

    LUGAR(10, 10);
    printf("5.- Vender ejemplares de un libro. Se venderán, como máximo, el número de ejemplares que tenga.");

    LUGAR(11, 10);
    printf("6.- Borrar los libros sin ejemplares.");

    LUGAR(12, 10);
    GREEN;
    printf("0.- Salir");
    RESET;

    LUGAR(14, 10);
    BIYELLOW;
    printf("Opción --> ");
    RESET;
    scanf("%d", &opcion);
    getchar();

    CLEAR_SCREEN;
    LUGAR(5, 1);

    return opcion;
}



//OPCIÓN 1
void mostrarporNombre(char *nombreFichero){
    FILE *pFichero;
    struct libro aux;
    int encontrado = 0;
    char titulo[SMAX];
    /* abre fichero para lectura */
    if((pFichero = fopen(nombreFichero, "rb")) == NULL){
        printf("ERROR AL ABRIR EL FICHERO");
    }
    printf("Introduzca el título del libro que busca:\n");
	fgets(titulo, SMAX, stdin);
    limpiarCadena(titulo);
    while ((encontrado == 0) && (fread(&aux, sizeof(struct libro), 1, pFichero) == 1)){
        if (strcmp(aux.titulo, titulo) == 0){
        /* se ha encontrado un registro con ese nombre */
            printf("El libro existe, y sus datos son:\nTitulo: %s\nAutor: %s\n\nPrecio: %.2f€\nUnidades: %i\n", aux.titulo, aux.autor, aux.precio, aux.unid);
            encontrado = 1;
        }
    }
    if(encontrado == 0){
        printf("El titulo que busca no coincide con ningún libro en la base de datos");
    }
    fclose(pFichero); /* se cierra el fichero */
}

/*********************************************************************************************************************/
//OPCIÓN 2
void addLibro(char* nombreFichero){ 
    FILE *f;
    struct libro aux1, aux2;
    int encontrado = 0, cantidad;

    printf("Introduzca el título\n");
    fgets(aux1.titulo, 100, stdin);
    limpiarCadena(aux1.titulo);

    if((f=fopen(nombreFichero, "r+b"))==NULL) {
        fprintf(stderr, "\nNo se puede abrir <%s>", nombreFichero);    
    }

    while ((encontrado == 0) && (fread(&aux2, sizeof(struct libro), 1, f) == 1)){
        if (strcmp(aux1.titulo, aux2.titulo) == 0){          
        /* se ha encontrado un registro con ese nombre */
            printf("El libro existe, introduzca una cantidad para aumentar las unidades\n");
            scanf("%i", &cantidad);
            (aux2.unid) += cantidad;
            fseek(f, -(int)sizeof(struct libro), SEEK_CUR); // Retrocedemos posicion
            fwrite(&aux2, sizeof(struct libro), 1, f);     // Escribimos registro actualizado
            fflush(f);                                  
            encontrado = 1;
        }
    }if(!encontrado){
        fgets(aux1.autor, 50, stdin);
        limpiarCadena(aux1.autor);
        scanf("%f %i", &aux1.precio, &aux1.unid);
        fseek(f, 0L, SEEK_END);                        // Puntero al final del archivo
        fwrite(&aux1, sizeof(struct libro), 1, f);     // Escribimos registro actualizado
        fflush(f);  
    }
    fclose(f);
}
/*********************************************************************************************************************/
struct libro *reservaMemoria(int n){
    struct libro *p = NULL;
    if((p = calloc(sizeof(struct libro), n)) == NULL){
        printf("ERROR: No se pudo reservar memoria");
    }
    return p;
}

//OPCIÓN 3
long tamanio(char* nombreFichero){
    FILE *f;
    long tam;
    if ((f = fopen(nombreFichero, "rb")) == NULL){
        fprintf(stderr, "\nError: no puedo abrir el fichero <%s>", nombreFichero);
    }
    if (fseek(f, 0L, SEEK_END)){
        fprintf(stderr, "\nError: no puedo usar el fichero <%s>", nombreFichero);
    }
    tam = (ftell(f) / sizeof(struct libro));
    fclose(f);
    return tam;
}

struct libro* ficheroAVector(char *fichero, long *nEle){
	FILE *f;
    *nEle = tamanio(fichero);
	struct libro *v = reservaMemoria(*nEle);

	if((f = fopen(fichero, "rb")) == NULL){
		printf("EL fichero no existe");
        v = NULL;
        return(v);
	}else{
    fread(v, sizeof(struct libro),*nEle, f); 

    fclose(f);
    return(v);
    }
}

//OPCIÓN 4
void listadoDesdeVector(char *fichero){
    long nEle=0;
    struct libro *v;
    v = ficheroAVector(fichero, &nEle);
    for(int i=0; i<nEle; i++){
        printf("Los datos del libro Nº%i son:\n", i+1);
        printf("Titulo: %s\n", v[i].titulo);
        printf("Autor: %s\n", v[i].autor);
        printf("Precio: %.2f€\n", v[i].precio);
        printf("Unidades: %i\n\n", v[i].unid);
    }
}

/*********************************************************************************************************************/
void limpiarCadena(char* cadena){
	if(cadena[strlen(cadena)-1]=='\n')
	    cadena[strlen(cadena)-1]='\0';
}
/*********************************************************************************************************************/
//OPCIÓN 5
void venderLibro(char* nombreFichero){ 
    FILE *f;
    struct libro aux1, aux2;
    int encontrado = 0, cantidad, resto = 0;

    printf("Introduzca el título\n");
    fgets(aux1.titulo, 100, stdin);
    limpiarCadena(aux1.titulo);

    if((f=fopen(nombreFichero, "r+b"))==NULL) {
        fprintf(stderr, "\nNo se puede abrir <%s>", nombreFichero);    
    }

    while ((encontrado == 0) && (fread(&aux2, sizeof(struct libro), 1, f) == 1)){
        if (strcmp(aux1.titulo, aux2.titulo) == 0){          
        /* se ha encontrado un registro con ese nombre */
            printf("Titulo correcto, ¿Cuantas unidades desea vender?\n");
            scanf("%i", &cantidad);
            resto = cantidad - aux2.unid; 
			if( resto > 0 ){ //Si cantidad > unidades, resto son las unidades que faltan para poder vender cantidad
				(aux2.unid) = 0;
				printf("No se dispone de tal stock, no se han podido vender %i unid.\n" , resto);
			} else{ //Si resto es positivo es porque : cantidad < unidades, por tanto esta venta no supone ningún problema
				(aux2.unid) -=  cantidad;
				printf("Inventario actualizado, quedan %i unidades\n", aux2.unid);
			}
            getchar(); //Necesario para que se vean los printf
            fseek(f, -(int)sizeof(struct libro), SEEK_CUR); // Retrocedemos posicion
            fwrite(&aux2, sizeof(struct libro), 1, f);     // Escribimos registro actualizado
            fflush(f);                                  
            encontrado = 1;
        }
    }if(!encontrado){
        printf("El titulo introducido no existe en la base de datos.\n");
    }
    fclose(f);
}
/*********************************************************************************************************************/
//OPCIÓN 6
void borrado(char* nombreFichero){ 
    FILE *f, *faux;
    struct libro aux;
    int encontrado = 0;

    if((f=fopen(nombreFichero, "rb"))==NULL) {
        fprintf(stderr, "\nNo se puede abrir <%s>", nombreFichero);    
    }else if((faux=fopen("temp", "wb"))==NULL) {
        fprintf(stderr, "\nNo se puede abrir <%s>", nombreFichero);    
    }

    while (fread(&aux, sizeof(struct libro), 1, f) == 1){
        if (aux.unid != 0){          
            fwrite(&aux, sizeof(struct libro), 1, faux);
        }else{
            encontrado = 1;
        }
    }
    fclose(f);
    fclose(faux);
    if (!encontrado){ // No hay registros para borrar
        printf("No ha sido necesario eliminar ningún libro\n");
        remove("temp");
    }else{
        remove(nombreFichero);
        rename("temp", nombreFichero);
    }
}