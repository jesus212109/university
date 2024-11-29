// Escribe   un   programa   que   permita   gestionar   los   jugadores   de   baloncesto   del   equipo   de   una
// ciudad. 
// El programa realizará secuencialmente las siguientes operaciones:
// a) Crear un vector dinámico de jugadores.
// b) Listar los jugadores registrados en el equipo, con las características de cada uno de ellos
// (dorsal, peso, estatura).
// c) Borrar todos los jugadores con una 'a' en su nombre.
// d) Listar de nuevo los jugadores.
// e) Liberar memoria al terminar.
// Deberás implementar al menos las siguientes funciones (también puede utilizar otras funciones
// auxiliares que considere oportunas):
// ●Función para reservar memoria para un vector de estructuras de jugador. 
// ●Función para  leer  un nuevo jugador. La función pedirá al usuario los datos de un jugador y
// los devolverá en una estructura struct Ficha_jugador.
// ●Función para rellenar un vector de jugadores usando la función para leer un jugador.
// ●Función para listar los jugadores del equipo. 
// ●Función   para   borrar   jugadores   cuyo   nombre   contenga   un   carácter   que   se   pasará   como
// argumento y que podrá aparecer en mayúscula o minúscula. Te pueden ser de utilidad las
// funciones tolower y toupper de ctype.h y la función strchr de string.h.
// ◦Al terminar la ejecución, el vector de jugadores habrá reducido su tamaño usando la
// función realloc.
// ◦La función devolverá el número de jugadores que quedan en el vector.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p5.h"

struct Ficha_jugador *reservaMemoria(int n){
    struct Ficha_jugador *p = NULL;
    if((p = calloc(sizeof(struct Ficha_jugador), n)) == NULL){
        printf("ERROR: No se pudo reservar memoria");
    }
    return p;
}

void liberaMemoria(struct Ficha_jugador **eq){
    free(*eq);
    *eq = NULL;
}

void listaEquipo(struct Ficha_jugador *eq, int n){
    for(int i = 0; i<n; i++){
        printf("\n\nLos datos del jugador %i son: \n", i);
        imprimeJugador(&eq[i]);
    }
}

void imprimeJugador(struct Ficha_jugador *eq) {
    printf("\nNombre: %s", eq->nombre);
    printf("Dorsal: %i\n", eq->dorsal);
    printf("Peso: %f\n", eq->peso);
    printf("Estatura: %i\n", eq->estatura);
}

void leeJugador(struct Ficha_jugador *eq){//falla
    getchar();
    
    printf("\nIntroduzca el nombre: \n");
    fgets(eq->nombre, LEN_NOMBRE, stdin);
    eq->nombre[strlen(eq->nombre)-1] = '\0';

    printf("\nIntroduzca el dorsal: \n");
    scanf("%i", &eq->dorsal);

    printf("\nIntroduzca el peso: (kg)\n");
    scanf("%f", &eq->peso);

    printf("\nIntroduzca la estatura: (cm)\n");
    scanf("%i", &eq->estatura);
}

// // void rellenaEquipo(struct Ficha_jugador* eq, int n){
//   strcpy(eq[0].nombre, "Juana");
//   eq[0].dorsal = 4;
//   eq[0].peso = 73.5;
//   eq[0].estatura = 192;
 
//   strcpy(eq[1].nombre, "Luisa");
//   eq[1].dorsal = 5;
//   eq[1].peso = 60.5;
//   eq[1].estatura = 172;
 
//   strcpy(eq[2].nombre, "Esther");
//   eq[2].dorsal = 8;
//   eq[2].peso = 88.5;
//   eq[2].estatura = 203;
 
//   strcpy(eq[3].nombre, "Irene");
//   eq[3].dorsal = 2;
//   eq[3].peso = 78.0;
//   eq[3].estatura = 195;
// }

void borrarConA(struct Ficha_jugador** eq, int *n){
    printf("Se procede a eliminar los jugadores con una a en su nombre");
    for(int i=0; i<*n ;i++){  //Recorremos nuestro vector
        
        if( strchr((*eq)[i].nombre , 'a') != NULL || strchr((*eq)[i].nombre , 'A') != NULL)  {

            printf("\n\n\nESTE JUGADOR SERÁ ELIMINADO:");
            imprimeJugador(&(*eq)[i]);

            for(int j=i; j<*n-1; j++){//n-1 para no intentar copiar dos veces la info del ultimo y evitar violación de segmento
                (*eq)[j] = (*eq)[j+1]; //desde el error, copiamos los datos del siguiente para peparar la posterio liberación de memoria 
            }
            i--;    //para no saltarnos la comparación del siguiente
            (*n)--;     //Es lógico ya que acabamos de eliminar unos datos
        }
    }

   *eq = realloc( *eq, *n * sizeof(struct Ficha_jugador) ); //reasignamos la memoria y liberamos la última posición (anteriormente duplicada)

}