#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include <string>
#include <list>
#include "client.h"
#include "seller.h"
#include "product.h"
#include <fstream>

class Market
{
private:
    std::list<Client> client_list_;
    std::list<Seller> seller_list_;
    std::string slogan_;

public:
    Market(std::string slogan) { slogan_ = slogan; }
    std::string GetSlogan() { return slogan_; }
    void SetSlogan(std::string slogan) { slogan_ = slogan; }
    bool AddClient(Client c);
    bool AddSeller(Seller s);
    int NClients(){return client_list_.size();}
    int NSellers(){return seller_list_.size();}
    bool DeleteClient(Client c);
    bool DeleteSeller(Seller s);
    bool AddProductSeller(Product p, std::string id_seller);
    bool AddProductClient(Product p, std::string id_client);
    bool DeleteProductSeller(Product p, std::string id_seller);
    bool DeleteProductClient(Product p, std::string id_client);
    float GetMoneyInBasket();
    bool DumpMarket(int outmode);
};

#endif
