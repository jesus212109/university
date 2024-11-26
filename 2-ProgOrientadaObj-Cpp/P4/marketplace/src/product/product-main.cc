#include <iostream>
#include "product.h"

int main(){
    Product p1("XX1");
    std::cout<<p1.GetId()<<"\n"<<p1.GetName()<<"\n"<<p1.GetMaker()<<"\n"<<p1.GetSeller()<<"\n"<<p1.GetPrice();
    exit(EXIT_SUCCESS);
}