#include "computer.h"
#include <iostream>

int main(){
    Computer p1("XX1",ComputerType::Gaming);

    std::cout<<p1.GetId()<<"\n"<<p1.GetName()<<"\n"<<p1.GetMaker()<<"\n"<<p1.GetSeller()<<"\n"<<p1.GetPrice()<<(int)p1.GetType()<<"\n"<<p1.mostrar()<<"\n";
    exit(EXIT_SUCCESS);
}