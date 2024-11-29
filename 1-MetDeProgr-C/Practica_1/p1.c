// Codifica un programa que utilice la sentencia printf para escribir el tamaño de los tipos de las
// siguientes variables:
// int a, *b, **c;
// double d, *e, **f;
// char g, *h, **i; 

#include <stdio.h>
#include <string.h>

int main(){
    int a, *b, **c;
    double d, *e, **f;
    char g, *h, **i; 

    printf("\nEl tamaño de a es %li bytes \n",sizeof(a));
    printf("\nEl tamaño de *b es %li bytes\n",sizeof(b));
    printf("\nEl tamaño de **c es %li bytes\n",sizeof(c));
    printf("\nEl tamaño de d es %li bytes\n",sizeof(d));
    printf("\nEl tamaño de *e es %li bytes\n",sizeof(e));
    printf("\nEl tamaño de **f es %li bytes\n",sizeof(f));
    printf("\nEl tamaño de g es %li bytes\n",sizeof(g));
    printf("\nEl tamaño de *h es %li bytes\n",sizeof(h));
    printf("\nEl tamaño de **i es %li bytes\n",sizeof(i));
}