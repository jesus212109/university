#include <string>
#include <vector>
#include <iostream>
#include "person.h"

void Person::AddPreferences(std::string s1, std::string s2, std::string s3){
    preferences_.insert(preferences_.begin(),s1);
    preferences_.insert(preferences_.end(),s3);
    preferences_.insert(preferences_.begin()+(preferences_.size()/2),s2);
}

void Person::ShowPreferences(){                 
    std::cout << "\nLas preferencias son: " << std::endl;
    for (auto s: preferences_){      
        //Auto, autoespecifica el tipo de variable y los dos puntos indican que se va a iterar sobre "preferences_"
        std::cout << s << std::endl;    
    }
}

void Person::ChangePreference(int n, std::string s1){
    try{  //Intenta hacer la siguiente operacióń
    preferences_.at(n) = s1;
    }
    catch (std::out_of_range const& exc){  
    //Si ocurre el error "out of range" realiza lo siguiente (evitando la violación de segmento)
    std::cout << exc.what() << '\n';
    }
}