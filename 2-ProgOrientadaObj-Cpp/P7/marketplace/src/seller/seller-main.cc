#include <iostream>
#include "person.h"
#include "basket.h"
#include "seller.h"

int main(){
    Seller p("xxxx1", "Jose", "Almeria", "Almeria", "España",
    20, 1.8, 2003,"agriculura");
    std::cout<<"soy el vendedor: "<<p.GetName()<<" y soy de "<<
    p.GetProvince()<<" y tengo el valor premium: "<<p.GetSector();

    
}
