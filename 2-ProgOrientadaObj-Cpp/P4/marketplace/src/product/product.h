#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>


class Product{
    private:
        std::string id_;
        std::string name_;
        float price_;
        std::string maker_;
        std::string seller_;

    public:
        Product(std:: string id, std::string name="empty",float price=0.0,
        std::string maker="empty",std::string seller="empty");

        //geters:
        std::string GetId(){return id_;}
        std::string GetName(){return name_;}
        std::string GetMaker(){return maker_;}
        std::string GetSeller(){return seller_;}
        float GetPrice(){return price_;}

        //setters:
        void SetId(std::string id){id_=id;}
        void SetName(std::string name){name_=name;}
        void SetMaker(std::string maker){maker_=maker;}
        void SetSeller(std::string seller){seller_=seller;}
        void SetPrice(float price){price_=price;}


};
#endif