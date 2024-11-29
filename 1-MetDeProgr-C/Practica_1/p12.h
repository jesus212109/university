struct fraccion{
int numerador;
int denominador;
};
void leerFraccion(struct fraccion* ptra);
void imprimirFraccion(struct fraccion a);
void multiplicarFracciones(struct fraccion a, struct fraccion b, struct fraccion* res);