#include <iostream>
#include "tv.h"

int main(){
    Tv p1("XX1");
    std::cout<<p1.GetId()<<"\n"<<p1.GetName()<<"\n"<<p1.GetMaker()<<"\n"<<p1.GetSeller()<<"\n"<<p1.GetPrice()<<"\n"<<p1.GetInch();
    exit(EXIT_SUCCESS);
}