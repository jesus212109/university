#include "product.h"

Product::Product(std:: string id, std::string name,float price, 
std::string maker,std::string seller):id_(id), name_(name), price_(price), maker_(maker),seller_(seller){}
//Esta es una estructura alternativa para hacer el constructor, importante poner los dos puntos ":"