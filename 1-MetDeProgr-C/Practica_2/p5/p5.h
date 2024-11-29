#ifndef P5_H
#define P5_H

#define LEN_NOMBRE 50

struct Ficha_jugador {
   char nombre[LEN_NOMBRE];
   int dorsal;              /* Nº entero */
   float peso;             /* Expresado en kilos */
   int estatura;           /* Expresado en centímetros*/
};

struct Ficha_jugador *reservaMemoria(int n);
void liberaMemoria(struct Ficha_jugador **eq);
void listaEquipo(struct Ficha_jugador *eq, int n);
void imprimeJugador(struct Ficha_jugador *eq);
void leeJugador(struct Ficha_jugador *eq);
// void rellenaEquipo(struct Ficha_jugador* eq, int n);
void borrarConA(struct Ficha_jugador** eq, int *n);

#endif