#include <stdio.h>
#include "funciones.h"

int main(){
char nombreFichero[] = "discos.bin";
char nombreFTxt[500];

// añadirDisco(nombreFichero);

mostrarDatos(nombreFichero);

// if(masUnid(nombreFichero) == -1){
//     printf("\nNo se ha encontrado un disco con dicho código\n\n");
// }else printf("\nSe ha realizado correctamente la operación\n\n");

// printf("EL Nº de discos distintos es: %i\n\n",contarDiscos(nombreFichero));

printf("Introduzca el nombre del archivo de texto: ");
scanf("%s", nombreFTxt);
binToTxt(nombreFichero, nombreFTxt);
}