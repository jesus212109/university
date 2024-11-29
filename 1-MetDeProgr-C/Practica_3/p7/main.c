#include <stdio.h>
#include <string.h>
#include "macros.h"
#include "funciones.h"

int main(int argc, char *argv[])
{
    int opcion;
    char nombreFichero[] = "libros.bin";

#if 0
char nombreFichero*;

 /* Se comprueban si los argumentos son correctos */
if (argc !=2 )
	{
		printf("Número de argumentos incorrecto\n");
		printf("El programa se debe ejecutar de la siguente forma:\n\t %s <nombre de fichero>\n",argv[0]);
		return -1;i
	}


  /* Se toma el nombre del fichero */
nombreFichero = argv[1];
#endif
    CLEAR_SCREEN;
    LUGAR(5, 1);
    BIYELLOW;
    printf("Gestión de libros usando el fichero <%s>\n\n", nombreFichero);
    RESET;
    printf("Pulsa enter para continuar");
    getchar();

    do{
        /* Se elige la opción del menún */
        opcion = menu();

        CLEAR_SCREEN;
        LUGAR(5, 1);
        switch (opcion)
        {
        case 0: /* FIN DEL PROGRAMA */
            LUGAR(10, 10);
            INVERSE;
            printf("Fin del programa %s.\n", argv[0]);
            RESET;
            LUGAR(24, 10);
            return 0;
            break;

        case 1: /* COMPROBAR SI EXISTE UN LIBRO Y MOSTRAR SUS DATOS EN SU CASO */
            BIYELLOW;
            printf("Opción 1: COMPROBAR SI EXISTE UN LIBRO Y MOSTRAR SUS DATOS EN SU CASO \n");
            RESET;
            mostrarporNombre(nombreFichero);
            break;

        case 2: /* INTRODUCIR UN LIBRO: SI YA EXISTE, SE INCREMETARÁN SU UNIDADES */
            BIYELLOW;
            printf("Opción 2: INTRODUCIR UN LIBRO: SI YA EXISTE, SE INCREMETARÁN SU UNIDADES \n");
            RESET;
            addLibro(nombreFichero);

        case 3: /* CONTAR LOS LIBROS CON TÍTULOS DIFERENTES DEL FICHERO */
            BIYELLOW;
            printf("Opción 3: CONTAR LOS LIBROS CON TÍTULOS DIFERENTES DEL FICHERO \n");
            RESET;
            printf("El Nº de libros es = %li\n", tamanio(nombreFichero));
            break;

        case 4: /* LISTAR LOS LIBROS DEL FICHERO */
            BIYELLOW;
            printf("Opción 4: LISTAR LOS LIBROS DEL FICHERO \n");
            RESET;
            listadoDesdeVector(nombreFichero);
            break;

        case 5: /* VENDER EJEMPLARES DE UN LIBRO  */
            BIYELLOW;
            printf("Opción 5: VENDER EJEMPLARES DE UN LIBRO \n");
            RESET;
            venderLibro(nombreFichero);
            break;

        case 6: /* BORRAR LIBROS SIN EJEMPLARES */
            BIYELLOW;
            printf("Opción 6: BORRAR LIBROS SIN EJEMPLARES  \n");
            RESET;
            borrado(nombreFichero);
            break;

        default: /* OPCIÓN INCORRECTA */
            RESET;
            RED;
            LUGAR(10, 10);
            printf("Opción incorrecta");
            RESET;
        }

        LUGAR(11, 10);
        printf("pulse ");
        UNDERLINE;
        printf("ENTER");
        RESET;
        printf(" para ");
        INVERSE;
        printf(" regresar al menú");
        RESET;
        getchar();

    } while (opcion != 0);

    return 0;
}