#include <iostream>
#include "person.h"

int main(){
    Person p1("XX1"), p2("XX2");
    std::cout<<p1.GetDataStr();
    std::cout<<p2.GetDataStr();

}