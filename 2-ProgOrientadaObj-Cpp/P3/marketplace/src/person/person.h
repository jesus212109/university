#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

class Person{
    private:
        std::string name_;
        int age_;
        float rank_;
        std::vector<std::string> preferences_;

        //empieza practica3:
        std::string id_;
        std::string town_;
        std::string province_;
        std::string country_;
        int entry_year_;

    public:
        Person(std::string id,std::string name="empty", std::string town="empty",
        std::string province="empty", std::string country="empty",int age=0, 
        float rank=0, int entry_year=0);
        //Person(std::string name, int age, double rank) {name_=name;age_=age;rank_=rank;}
        std::string GetName(){return name_;}
        int GetAge(){return age_;}
        float GetRank(){return rank_;}
        
        //empieza practica 2:
        std::vector<std::string>GetPreferences(){return preferences_;}
        void AddPreference(std::string s1){preferences_.push_back(s1);}
        void AddPreferences(std::string s1, std::string s2, std::string s3);
        void ShowPreferences();
        void ChangePreference(int n, std::string s1);

        //empieza practica 3:
        std::string GetId(){return id_;}
        std::string GetTown(){return town_;}
        std::string GetProvince(){return province_;}
        std::string GetCountry(){return country_;}
        int GetEntryYear(){return entry_year_;}

        void SetId(std::string id){id_=id;}
        void SetName(std::string name){name_=name;}
        void SetTown(std::string town){town_=town;}
        void SetProvince(std::string province){province_=province;}
        void SetCountry(std::string country){country_=country;}
        void SetRank(float rank){rank_=rank;}

        bool SetAge(int n);
        bool SetEntryYear(int n);

        std::string GetDataStr();
        
};

#endif