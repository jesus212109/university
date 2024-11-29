#include <stdio.h>
#include <string.h>
/* Para usar malloc */
#include <malloc.h>
/* Para usar las macros de pantalla */
#include "macros.h"
/* Prototipos de las funciones */
#include "funciones.h"

int menu()
{
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

	LUGAR(11,10);
	printf("6.- Borrar los libros sin ejemplares.");
	
	LUGAR(12,10);
	GREEN;
	printf("0.- Salir");
	RESET;

	LUGAR(14,10);
	BIYELLOW;
	printf("Opción --> ");
	RESET;
	scanf("%d",&opcion);
	getchar();

	CLEAR_SCREEN;
	LUGAR(5,1);

	return opcion;
}
// getchar();//Para evitar problemas al recibir la cantidad de elementos a borrar
/***************************************************************************************************************************************************************/

void mostrarLibro(char *fichero){
	FILE *f;
	struct libro aux;
	int encontrado=0;
	char titulo[SMAX];
	if((f = fopen(fichero, "r")) == NULL){
		printf("EL fichero no existe");
	}else{
		printf("Introduzca el título del libro que busca:\n");
		fgets(titulo, SMAX, stdin);
		while((fgets(aux.titulo,SMAX,f) != NULL) && (fgets(aux.autor,SMAX,f) != NULL) && (fscanf(f, "%f %d\n", &(aux.precio), &(aux.unid)) != EOF)){
			if( strcmp(aux.titulo, titulo) == 0){
				encontrado = 1;
				printf("Se ha encontrado su búsqueda y sus datos son:\n");
				printf("Titulo: %s", aux.titulo);
				printf("Autor: %s", aux.autor);
				printf("Precio: %.2f€\n", aux.precio);
				printf("Unidades: %i\n\n", aux.unid);
			}
		}
		if(encontrado == 0)
			printf("No se ha encontrado ningún libro con ese título\n");
		fclose(f);
	}
}

/***************************************************************************************************************************************************************/

void introducirNuevo(char *fichero){
	FILE *f;
	char titulo[SMAX], autor[SMAX];
	float precio;
	int unid;
	if((f = fopen(fichero, "a+")) == NULL){
		printf("EL fichero no existe");
	}else{
		printf("Introduzca el título del nuevo libro:\n");
		fgets(titulo, SMAX, stdin);//leo fgets stdin y quito \n ¿titulo[strlen] = \0?
		if(titulo[strlen(titulo)-1]=='\n')
				titulo[strlen(titulo) - 1] = '\0';
		fprintf(f,"\n%s\n",titulo);

		printf("Introduzca el autor:\n");
		fgets(autor, SMAX, stdin);
		if(autor[strlen(autor)-1]=='\n')
				autor[strlen(autor) - 1] = '\0';
		fprintf(f,"%s\n", autor);

		printf("Introduzca el precio:\n");
		scanf("%f", &precio);
		fprintf(f, "%f ", precio);

		printf("Introduzca el Nº de unidades:\n");
		scanf("%i", &unid);
		fprintf(f, "%i", unid);

		fclose(f);
	}
}

/***************************************************************************************************************************************************************/

int contarDiferentes(char *fichero){
	FILE *f;
	struct libro aux;
	int cont=0;
	if((f = fopen(fichero, "r")) == NULL){
		printf("EL fichero no existe");
		return -1;
	}else{
		while((fgets(aux.titulo,SMAX,f) != NULL) && (fgets(aux.autor,SMAX,f) != NULL) && (fscanf(f, "%f %d\n", &(aux.precio), &(aux.unid)) != EOF)){
			cont++;
		}return cont;
	}
}

/***************************************************************************************************************************************************************/

// void mostrarDatos(char *fichero){//Implementar con vector dinámico
// 	FILE *f;
// 	struct libro aux;
// 	int i=0;
// 	if((f = fopen(fichero, "r")) == NULL){
// 		printf("EL fichero no existe");
// 	}else{
// 		while((fgets(aux.titulo,SMAX,f) != NULL) && (fgets(aux.autor,SMAX,f) != NULL) && (fscanf(f, "%f %d\n", &(aux.precio), &(aux.unid)) != EOF)){
// 			printf("Los datos del libro Nº%i son:\n", i+1);

// 			if(aux.titulo[strlen(aux.autor)-1]=='\n')
// 				aux.titulo[strlen(aux.titulo) - 1] = '\0';
// 			if(aux.autor[strlen(aux.autor)-1]=='\n')
// 				aux.autor[strlen(aux.autor) - 1] = '\0';
// 			printf("Titulo: %s", aux.titulo);
// 			printf("Autor: %s\n", aux.autor);
// 			printf("Precio: %.2f€\n", aux.precio);
// 			printf("Unidades: %i\n\n", aux.unid);
// 			i++;
// 		}
// 		fclose(f);
// 	}
// }

struct libro *reservaMemoria(int n){
    struct libro *p = NULL;
    if((p = calloc(sizeof(struct libro), n)) == NULL){
        printf("ERROR: No se pudo reservar memoria");
    }
    return p;
}

void desdeVect(char *fichero){//Implementar con vector dinámico
	FILE *f;
	struct libro *aux = reservaMemoria(contarDiferentes(fichero));
	int i=0;
	if((f = fopen(fichero, "r")) == NULL){
		printf("EL fichero no existe");
	}else{
		while((fgets(aux[i].titulo,SMAX,f) != NULL) && (fgets(aux[i].autor,SMAX,f) != NULL) && (fscanf(f, "%f %d\n", &(aux[i].precio), &(aux[i].unid)) != EOF)){
			
			
			printf("Los datos del libro Nº%i son:\n", i+1);
			if(aux[i].titulo[strlen(aux[i].autor)-1]=='\n')
				aux[i].titulo[strlen(aux[i].titulo) - 1] = '\0';
			if(aux[i].autor[strlen(aux[i].autor)-1]=='\n')
				aux[i].autor[strlen(aux[i].autor) - 1] = '\0';
			printf("Titulo: %s", aux[i].titulo);
			printf("Autor: %s\n", aux[i].autor);
			printf("Precio: %.2f€\n", aux[i].precio);
			printf("Unidades: %i\n\n", aux[i].unid);
			i++;
		}
		fclose(f);
	}
}

// /***************************************************************************************************************************************************************/

void limpiarCadena(char* cadena){
	if(cadena[strlen(cadena)-1]=='\n')
	    cadena[strlen(cadena)-1]='\0';
}

// /***************************************************************************************************************************************************************/

void ventaEjem(char *fichero){
	FILE *f1, *f2;
	struct libro aux;
	int encontrado = 0, resto = 0;


	int vendidos; 
	char titulo[SMAX];
	printf("Introduzca el título del libro que busca:\n");
	fgets(titulo, SMAX, stdin);
	limpiarCadena(titulo);
	printf("\nIntroduzca la cantidad de elementos:\n");
    scanf("%i",&vendidos); 
	getchar();//Para evitar problemas al recibir la cantidad de elementos a borrar


	if((f1 = fopen(fichero, "r")) == NULL){//Se abren los ficheros
		printf("Error al abrir fichero <%s>", fichero);
    }
	
	if((f2 = fopen("temporal", "w")) == NULL){
		printf("Error al abrir fichero");	
    }   

	//Se recibe la info de f1 durante el bucle:
	while(fgets(aux.titulo,SMAX,f1) != NULL)
	{
			limpiarCadena(aux.titulo);
			// printf("\nTitulo: <%s>", aux.titulo);

		    fgets(aux.autor,SMAX,f1);
			limpiarCadena(aux.autor);
			// printf("\nAutor: <%s>", aux.autor);

			fscanf(f1, "%f ", &(aux.precio));
			fscanf(f1, "%d\n", &(aux.unid));

			//printf("\n\tComparando <%s> con <%s>", aux.titulo, titulo);

			if( strcmp(aux.titulo, titulo) == 0){  //Encuento el dato a cambiar
				encontrado = 1;
				resto = vendidos - aux.unid;
				if( resto > 0 ){ //Si vendidos > unidades, resto son las unidades que faltan para poder vender dicha cantidad
					(aux.unid) = 0;
					printf("No se dispone de tal stock, no se han podido vender %i unid.\n" , resto);
				} else{ //Si resto es negativo es porque : vendidos < unidades, por tanto esta venta no supone ningún problema
					(aux.unid) -=  vendidos;
					printf("Inventario actualizado, quedan %i unidades\n", aux.unid);
				}
			}//Escribo los datos incluyendo lo que se haya modificado en f2
			fprintf(f2,"%s\n",aux.titulo);
			fprintf(f2,"%s\n",aux.autor);
			fprintf(f2, "%f ", aux.precio);
			fprintf(f2, "%d\n", aux.unid);					
	}
	
	fclose(f1);
	fclose(f2);
	
	if(encontrado == 0){
			printf("No se ha encontrado ningún libro con ese título\n");
			remove("temporal");
	}
	else
	{		remove(fichero);
			rename("temporal", fichero);
	}
	
}


/***************************************************************************************************************************************************************/

void borrado(char *fichero)
{
	FILE *f, *faux;
	struct libro aux;
	int encontrado = 0;
	if ((f = fopen(fichero, "r")) == NULL)
	{
			printf("EL fichero no existe");
	}
	if ((faux = fopen("temp", "w")) == NULL)
	{
			printf("EL fichero no existe");
	}
	while ((fgets(aux.titulo, SMAX, f) != NULL) && (fgets(aux.autor, SMAX, f) != NULL) && (fscanf(f, "%f %d\n", &(aux.precio), &(aux.unid)) != EOF))
	{
		limpiarCadena(aux.titulo);
		limpiarCadena(aux.autor);
			if (aux.unid != 0)
			{
				fprintf(faux, "%s\n", aux.titulo);
				fprintf(faux, "%s\n", aux.autor);
				fprintf(faux, "%f ", aux.precio);
				fprintf(faux, "%i\n", aux.unid);
			}
			else
			{
				encontrado = 1;
			}
	}
	fclose(f);
	fclose(faux);
	if (!encontrado)
	{ // No hay registros para borrar
			printf("No ha sido necesario eliminar ningún libro\n");
			remove("temp");
	}
	else
	{
		printf("Se han eliminado correctamente los libros sin unid.\n");
		remove(fichero);
		rename("temp", fichero);
	}
}
