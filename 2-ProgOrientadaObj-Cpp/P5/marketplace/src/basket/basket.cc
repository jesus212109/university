#include <iostream>
#include "basket.h"
#include "product.h"

void Basket::AddProduct(Product p)
{
    if (product_quantity_.count(p.GetId()) == 0)
    {
        product_list_.push_back(p);
        product_quantity_[p.GetId()] = 1;
    }

    else
    {
        product_quantity_[p.GetId()] += 1;
    }

    total_ += p.GetPrice();
}

bool Basket::DeleteProduct(Product p)
{
    if (product_quantity_.count(p.GetId()) == 0)
    {
        return false;
    }
    else
    {
        if (product_quantity_[p.GetId()] == 1)
        {
            product_list_.remove(p);
            product_quantity_.erase(p.GetId());
        }
        else
        {
            product_quantity_[p.GetId()]--;
        }
    }
    total_ -= p.GetPrice();
    return true;
}

//Esta funcion y la anterior pueden tener el mismo nombre pero como reciben argumentos distintos se distinguen, (no hay problema)

bool Basket::DeleteProduct(std::string id)
{ //Cuando nos dan el ID es necesario el iterador porque estamos trabando con la lista y hay que recorrerla hasta encontrar el elemento que queremos
    if (product_quantity_.count(id) == 0)
    {
        return false;
    }

    for (auto it = product_list_.begin(); it != product_list_.end(); it++)
    {
        if (it->GetId() == id)
        {
            total_ -= it->GetPrice();
            if (product_quantity_[id] == 1)// Si cantidad = 1, se quita de la cesta
            {
                it=product_list_.erase(it);
                product_quantity_.erase(id);
            }else{                         //Si cantidad > 1 , cantidad --
                product_quantity_[id]--;
            }
        }
    }
    return true;
}

void Basket::DeleteBasket()
{
    total_ = 0.0;
    product_list_.clear();
    product_quantity_.clear();
}

int Basket::GetSize(){ product_list_.size();}

float Basket::GetTotal()
{
    return total_;
}

//Comforme recorro la lista, voy copiando en el vector los ID de la lista, en C++ los vectores son de memoria dinamica ;)
std::vector<std::string> Basket::GetIds()
{
    std::vector<std::string> ids;
    for (auto it = product_list_.begin(); it != product_list_.end(); it++)
    {
        ids.push_back(it->GetId());
    }
    return ids;
}

//Comforme recorro la lista, voy copiando en el vector las cantidades de la lista
std::vector<int> Basket::GetQs()
{
    std::vector<int> qs;
    for (auto it = product_list_.begin(); it != product_list_.end(); it++)
    {
        qs.push_back(product_quantity_[it->GetId()]);
    }
    return qs;
}