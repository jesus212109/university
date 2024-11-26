#ifndef COMPUTER_H
#define COMPUTER_H
#include "product.h"
#include <string>

//Declaración de un enumerado (enum), que se llama ComputerType y define cinco valores posibles que pueden ser asignados a una variable de este tipo
enum class ComputerType{
    Desktop,
    Laptop,
    Server,
    Tablet,
    Gaming
};

class Computer: public Product{
    private:
        ComputerType type_;
    public:

    std::string mostrar();

    Computer( std::string id,ComputerType type, std::string 
    name="empty",float price=0.0, std::string maker="empty",
     std::string seller="empty");

    ComputerType GetType(){return type_;}
    void SetType(ComputerType type){type_=type;}
};
#endif