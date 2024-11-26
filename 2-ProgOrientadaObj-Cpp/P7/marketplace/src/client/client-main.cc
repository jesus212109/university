#include <iostream>
#include "person.h"
#include "basket.h"
#include "client.h"

int main(){
    Client p("xxxx1", "Jose", "Almeria", "Almeria", "España",
    20, 1.8, 2003,5);
    std::cout<<"soy el cliente: "<<p.GetName()<<" y soy de "<<
    p.GetProvince()<<" y tengo el valor premium: "<<p.GetPremium();

    
}