destino: saludo main

saludo:
	@echo "Ejecutando el makefile de Jesús Fernández López"

main: main.o funciones.o
	gcc main.o funciones.o -o main

main.o: main.c
	gcc -c main.c

funciones.o: funciones.c
	gcc -c funciones.c