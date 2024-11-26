#ifndef BASKET_H
#define BASKET_H

#include <string>
#include <list>
//Una lista en C++ es una estructura de datos lineal que permite almacenar un conjunto de elementos, que pueden ser de cualquier tipo. La lista permite almacenar elementos duplicados y organiza los elementos en función de su posición en la lista.
//std::list<tipo> nombre_lista;
#include <map>
//Un mapa en C++ es una estructura de datos que permite almacenar un conjunto de elementos, donde cada elemento es un par de valores. El mapa organiza estos pares en función de sus valores clave, lo que facilita la búsqueda y eliminación de elementos en el mapa
//std::map<tipo_clave, tipo_valor> nombre_mapa;
#include <vector>
#include "product.h"


class Basket{
    private:
        std::list <Product> product_list_;
        std::map<std::string, int> product_quantity_;
        float total_;
    public:

        Basket(){total_=0.0;} 
        
        void AddProduct(Product p);
        bool DeleteProduct(Product p);
        bool DeleteProduct(std::string id);
        void DeleteBasket();
        int GetSize();
        float GetTotal();
        std::vector<std::string> GetIds();
        std::vector<int> GetQs();
        
};

#endif
