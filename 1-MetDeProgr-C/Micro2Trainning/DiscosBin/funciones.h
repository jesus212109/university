struct disco
{
int cod;
char nombre[50];
char autor[50];
int unid;
};
int contarDiscos(char *fich);
void mostrarDatos(char *fich);
void añadirDisco(char *fich);
int masUnid(char *fich);
void binToTxt(char *fbin, char *ftxt);