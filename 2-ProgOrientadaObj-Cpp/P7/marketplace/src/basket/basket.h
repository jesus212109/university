#ifndef BASKET_H
#define BASKET_H

#include <string>
#include <map>
#include <vector>
#include <list>
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
        
        //Función para práctica 7
        bool DeleteProducts(Product p);
};

#endif
