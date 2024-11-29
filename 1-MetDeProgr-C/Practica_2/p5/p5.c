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
#include <string.h>
#include "p5.h"

int main(){
    struct Ficha_jugador *eq = NULL;
    int n;

    printf("Tamaño del equipo: ");
    scanf("%i",&n);

    eq = reservaMemoria(n);
    
    
    for(int i=0; i<n; i++){
        printf("\n\nIntroduce los datos del jugador %i: \n",i);
        leeJugador(&eq[i]);
    }
    listaEquipo(eq,n);

    // n=4;
    // eq = reservaMemoria(n);
    // rellenaEquipo(eq,n);

    borrarConA(&eq, &n);
    printf("\nLa nueva lista con %i jugadores es:\n", n);
    listaEquipo(eq,n);

    liberaMemoria(&eq);