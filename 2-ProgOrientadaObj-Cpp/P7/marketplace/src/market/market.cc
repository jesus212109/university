#include <iostream>
#include "market.h"

bool Market::AddClient(Client c)
{
    for (auto it = client_list_.begin(); it != client_list_.end(); it++)
    {
        if (it->GetId() == c.GetId())
        {
            return false; //Si el cliente existe no se puede volver a añadir
        }
    }

    client_list_.push_back(c);
    return true;
}

bool Market::AddSeller(Seller s)
{
    for (auto it = seller_list_.begin(); it != seller_list_.end(); it++)
    {
        if (it->GetId() == s.GetId())
        {
            return false; //Si el vendedor existe no se puede volver a añadir
        }
    }
    seller_list_.push_back(s);
    return true;
}

bool Market::DeleteClient(Client c)
{
    for (auto it = client_list_.begin(); it != client_list_.end(); it++)
    {
        if (it->GetId() == c.GetId())
        {
            client_list_.erase(it);
            return true;
        }
    }
    return false;
}

bool Market::DeleteSeller(Seller s)
{
    for (auto it = seller_list_.begin(); it != seller_list_.end(); it++)
    {
        if (it->GetId() == s.GetId())
        {
            seller_list_.erase(it);
            return true;
        }
    }
    return false;
}

bool Market::AddProductSeller(Product p, std::string id_seller)
{
    for (auto it = seller_list_.begin(); it != seller_list_.end(); it++)
    {
        if (it->GetId() == id_seller)
        {
            it->AddProduct(p);
            return true;
        }
    }
    return false;
}

bool Market::AddProductClient(Product p, std::string id_client)
{   //Itero sobre la lista de vendedores
    for (auto it = seller_list_.begin(); it != seller_list_.end(); ++it)
    {   //Procedemos si el producto se encuentra en la lista de vendedores y se reduce la cantidad en dicha lista en 1
        if (it->DeleteProduct(p) == true)
        {   //Itero sobre la lista de clientes
            for (auto it2 = client_list_.begin(); it2 != client_list_.end(); ++it2)
            {   //Si encuentro el ID del cliente que quiero le añado el producto a su lista (cesta)
                if (it2->GetId() == id_client)
                {
                    it2->AddProduct(p);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Market::DeleteProductSeller(Product p, std::string id_seller)
{
    for (auto it = seller_list_.begin(); it != seller_list_.end(); it++)
    {
        if (it->GetId() == id_seller)
        {
            if(it -> DeleteProduct(p) == true){
            //it -> DeleteProduct(p);
            return true;
            }
        }
    }
    return false;
}

bool Market::DeleteProductClient(Product p, std::string id_client)
{
    for (auto it = client_list_.begin(); it != client_list_.end(); it++)
    {
        if (it->GetId() == id_client)
        {
            if(it -> DeleteProduct(p) == true){
            //it -> DeleteProduct(p);
            return true;
            }
        }
    }
    return false;
}

float Market::GetMoneyInBasket()
{
    float suma = 0.0;

    for (auto it = client_list_.begin(); it != client_list_.end(); it++)
    {
        suma += it->GetTotal();
    }
    return suma;
}

bool Market::DumpMarket(int outmode) //Realiza tiket
{
    std::vector<std::string> idprod;
    std::vector<int> qprod;
    if (outmode < 0 || outmode > 1)
        return false;
    else
    {
        if (outmode == 1)
        {
            std::ofstream fich("ventas.txt");
            if (fich.is_open())
            {
                fich << "|-------------------------------------|\n"
                    << "|CLIENT ID  |PRODUCT ID  |PRODUCT QTY |\n";
                for (auto it = client_list_.begin(); it != client_list_.end(); it++)
                {
                    idprod = it->GetIds();
                    qprod = it->GetQs();
                    for (int i = 0; i < it->GetSize(); i++)
                    {
                        fich << "|" << it->GetId() << "         |"
                            << idprod[i] << "          |"
                            << qprod[i] << "           |\n";
                    }
                }
                fich << "|-------------------------------------|\n"
                    << "|TOTAL: " << GetMoneyInBasket() << "€                          |\n"
                    << "|-------------------------------------|";
                fich.close();
            }
            else
                std::cout << "Error de apertura del fichero";
        }
        if (outmode == 0)
        {
            std::cout << "|-------------------------------------|\n"
                    << "|CLIENT ID  |PRODUCT ID  |PRODUCT QTY |\n";
            for (auto it = client_list_.begin(); it != client_list_.end(); it++)
            {
                idprod = it->GetIds();
                qprod = it->GetQs();
                for (int i = 0; i < it->GetSize(); i++)
                {
                    std::cout << "|" << it->GetId() << "         |"
                            << idprod[i] << "          |"
                            << qprod[i] << "           |\n";
                }
            }
            std::cout << "|-------------------------------------|\n"
                    << "|TOTAL: " << GetMoneyInBasket() << "€                          |\n"
                    << "|-------------------------------------|";
        }
    }
    return true;
}