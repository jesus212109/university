#include "person.h"
#include <iostream>

int main(){
    Person p1("Paco", 32, 4.568), p2("Pepita", 41, 7.371);
    std::cout << p1.GetName()<<"\n";
    std::cout << p2.GetName()<<"\n";

    p1.AddPreferences("orangutan","leopardo","hormiga");
    p1.ShowPreferences();

    p1.AddPreferences("correr","baloncesto","futbol");
    p1.ShowPreferences();
    p1.AddPreference("cintura");
    p1.AddPreference("portaminas");
    p1.ShowPreferences();

    std::cout<<"\nDame el entero a cambiar\n";
    int n;
    std::cin>>n;
    std::string s1;
    std::cout<<"\nDame la cadena a cambiar:\n";
    std::cin>>s1;
    p1.ChangePreference(n-1, s1);
    p1.ShowPreferences();
    std::cout<<"\n-END-\n";
}