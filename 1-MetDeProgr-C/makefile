inicio: saluda compilar

saluda: 
	@echo "Este es el makefile de Santiago Bravo"

compilar: main.o funciones.o
	gcc main.o funciones.o -o pepito

main.o: main.c
	gcc -c main.c

funciones.o: funciones.c
	gcc -c funciones.c

.PHONY:
	clean

clean:
	rm *.o