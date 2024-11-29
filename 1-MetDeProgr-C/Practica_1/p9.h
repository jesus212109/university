#include <math.h>

//Las estructuras se declaran aquí
  struct monomio    
    {
      int  coeficiente;
      int  grado;
    };

void leerMonomio(struct monomio* ptra);
void imprimirMonomio(struct monomio a);
void maximinGrado(struct monomio* ptra, struct monomio* max, struct monomio* min, int n);
float evalx(struct monomio* ptra, float x, int n);