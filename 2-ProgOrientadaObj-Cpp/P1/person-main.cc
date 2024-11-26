#include "person.h"
#include <iostream>

int main(){
    Person p1("Juan", 32, 4.568), p2("Ana", 41, 7.371);
    std::cout << p1.GetName()<<"\n";
    std::cout << p2.GetName()<<"\n";

    int a=60;
    ns1::a=0;
    ns2::a=2.7;
    std::cout<< "ns1::a= " << ns1::a << "\n";
    std::cout<< "ns2::a= " << ns2::a << "\n";
    std::cout<< "a= " << a << "\n";

}