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
        std::cout << s << std::endl;
    }
}

void Person::ChangePreference(int n, std::string s1){
    try{
    preferences_.at(n) = s1;
    }
    catch (std::out_of_range const& exc){
    std::cout << exc.what() << '\n';
    }
}

//empiza la practica 3:

bool Person::SetAge(int n){
    if(n>0){
        age_=n;
        return true;
    }
    return false;
}

bool Person::SetEntryYear(int n){
    if(n>2000){
        entry_year_=n;
        return true;
    }
    return false;
}

Person::Person(std::string id,std::string name, std::string town,std::string province, std::string country,int age, float rank, int entry_year):
    id_(id), name_(name), town_(town),province_(province),country_(country),age_(age),rank_(rank),entry_year_(entry_year){
    if(entry_year<2000){
        entry_year_=0;
    }else{
        entry_year_=entry_year;
    }
}
    
    


std::string Person::GetDataStr() {
    return "Person:\nid: "+id_+"\n"+
           "name: " + name_ + '\n' +
           "town: " + town_ + '\n' +
           "province: " + province_ + '\n' +
           "country: " + country_ + '\n' +
           "age: " + std::to_string(age_) + '\n' +
           "rank: " + std::to_string(rank_);
}
