#include "computer.h"
#include <string>

Computer::Computer( std::string id, ComputerType type,  std::string name, float price,  std::string maker,  std::string seller):Product(id,name,price, 
    maker, seller),type_(type){}

std::string Computer::mostrar(){
    switch(type_){
        case ComputerType::Desktop:
            return "Desktop";
        case ComputerType::Laptop:
            return "Laptop";
        case ComputerType::Server:
            return "server";
        case ComputerType::Tablet:
            return "Tablet";
        case ComputerType::Gaming:
            return "Gaming";
        default:
        return "Algo va mal";
    }
}
