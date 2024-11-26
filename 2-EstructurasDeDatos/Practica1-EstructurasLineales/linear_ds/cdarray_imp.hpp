/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once
#include <sstream>
#include <cassert>
#include "cdarray.hpp"

template <class T>
CDArray<T>::CDArray(size_t cap)
{
    assert(cap > 0);
    // TODO

    _capacity = cap;
    _front = 0;
    _back = 0;
    _size = 0;
    // Creamos vector de tipo T, en el cual el puntero inteligente apunta al primer elemento del array con capacidad cap
    _data = std::shared_ptr<T>(new T[cap]); // New es un malloc a alto nivel

    //
    assert(capacity() == cap);
    assert(is_empty());
    assert(size() == 0);
}

template <class T>
CDArray<T>::~CDArray() {}

template <class T>
typename CDArray<T>::Ref
CDArray<T>::create(size_t cap)
{
    return std::make_shared<CDArray<T>>(cap);
}

template <class T>
typename CDArray<T>::Ref
CDArray<T>::create(std::istream &in) noexcept(false)
{
    auto ret_v = std::make_shared<CDArray<T>>(1);
    // TODO
    // Hint: use std::istringstream to convert from "string" to template
    //  parameter T type.
    // Remember: throw std::runtime_error("Wrong input format.") exception when an input
    //  format error was found.

    std::string token;
    in >> token;        //Recibe strings separado por espacios
    if (token != "[") {
        throw std::runtime_error("Wrong format"); //Lanzo error por mal formato
    }


    in >> token;     //Recibe siguiente string
    while (!in.eof() && token != "]") { //Recorre todo lo que hay entre corchetes
        T value;        
        std::istringstream(token) >> value; 
        // istringstream vuelca el token(string) a value(tipo T)
        ret_v->push_back(value);
        in >> token;
    }

    if (token != "]") { //Salta el error si no se ha cerrado bien el archivo
        throw std::runtime_error("Wrong format");
    }

    //
    return ret_v; //ojo, los throw en caso de fallo se lanzan antes de enviar el retorno
}

template <class T>
bool CDArray<T>::is_empty() const
{
    bool ret_v = false;
    // TODO
    ret_v = _size == 0;
    //
    return ret_v;
}

template <class T>
bool CDArray<T>::is_full() const
{
    bool ret_v = false;
    // TODO
    ret_v = _size == _capacity;
    //
    assert(!ret_v || size() == capacity());
    return ret_v;
}

template <class T>
size_t
CDArray<T>::capacity() const
{
    size_t ret_v = 0;
    // TODO
    ret_v = _capacity;
    //
    return ret_v;
}

template <class T>
size_t
CDArray<T>::size() const
{
    size_t ret_v = 0;
    // TODO
    ret_v = _size;
    //
    return ret_v;
}

template <class T>
std::ostream &
CDArray<T>::fold(std::ostream &out) const
{
    // TODO

    out << "[";

    for(int i= 0; i < _size; ++i){
        out << " " << this->get(i);
    }

    out << " ]";

    //
    return out;
}

template <class T>
T CDArray<T>::get(size_t pos) const
{
    T ret_v;
    // TODO

    // Utilizamos la operación módulo y el front para permitir usar al usuario el operados [] como de costumbre
    ret_v = _data.get()[(_front + pos) % _capacity];

    //
    return ret_v;
}

template <class T>
void CDArray<T>::set(size_t pos, T const &new_v)
{
    // TODO

    _data.get()[(_front + pos) % _capacity] = new_v;

    //
    assert(new_v == get(pos));
}

size_t cInc(size_t v, size_t size) // Suma para recorrer el array
{
    size_t ret_v;
    // TODO

    ret_v = ((v + 1) % size);

    //
    return ret_v;
}

size_t cDec(size_t v, size_t size)
{
#ifndef NDEBUG
    size_t old_v = v;
#endif
    size_t ret_v;
    // TODO
    // Remember: v is a unsigned value, so you must cast to signed before decrementing

    ret_v = ((v - 1 + size) % size);

    //
    assert(old_v == cInc(ret_v, size));
    return ret_v;
}

template <class T>
void CDArray<T>::push_front(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
    bool old_is_empty = is_empty();
    T old_front = is_empty() ? T() : get(0);
#endif
    // TODO

    if (this->is_empty()){
        _front = 0;
        _back = 0;
    }else {
        if(this->is_full()){ this->grow(); }  
            _front = cDec(_front, capacity()); //Actualizo el valor de Front
    }
    // = _data.get()[( _front ) % _capacity] = new_it
    this->set(0, new_it); //Inserto en front que usando la función de interfaz de usuario es insertar en 0
    ++_size; 
    
    //
    assert(size() == old_size + 1);
    assert(get(0) == new_it);
    assert(old_is_empty || (get(1) == old_front));
}

template <class T>
void CDArray<T>::push_back(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
    bool old_is_empty = is_empty();
    T old_back = is_empty() ? T() : get(size() - 1);
#endif
    // TODO               ME QUEDÉ AQUÍ, COMPROBAR ESTA FUNCIÓN Y SEGUIR
    if(this->is_empty()){
        _front = 0;
        _back = 0;
    } else{
        if (this->is_full()){ this->grow();}
        _back = cInc(_back, capacity());
    }
    // = _data.get()[( _back ) % _capacity] = new_it
    this->set(_size,new_it); //Inserto en back que usando la función de interfaz de usuario es insertar en su último elemento(dado por _size)
    ++_size;
    //
    assert(size() == old_size + 1);
    assert(get(size() - 1) == new_it);
    assert(old_is_empty || (get(size() - 2) == old_back));
}

template <class T>
void CDArray<T>::pop_front()
{
#ifndef NDEBUG
    size_t old_size = size();
    T old_next_front = size() > 1 ? get(1) : T();
#endif
    // TODO

    _front = cInc(_front, capacity());
    --_size; //Ojo, viene ++_size en diapo(Así es como está bien)

    //
    assert(size() == old_size - 1);
    assert(is_empty() || get(0) == old_next_front);
}

template <class T>
void CDArray<T>::pop_back()
{
#ifndef NDEBUG
    size_t old_size = size();
    T old_prev_back = size() > 1 ? get(size() - 2) : T();
#endif
    // TODO

    _back = cDec(_back, capacity());
    --_size;

    //
    assert(size() == old_size - 1);
    assert(is_empty() || get(size() - 1) == old_prev_back);
}

template <class T>
void CDArray<T>::insert(size_t pos, T const &v)//v = valor
{
    assert(pos >= 0 && pos < size());
#ifndef NDEBUG
    size_t old_size = size();
    T old_back = get(size() - 1);
    T old_pos_v = get(pos);
#endif
    // TODO
    // Hint: if pos==0, delegate in push_front.
    // Remember: back_ needs to be updated too.

    if(pos == 0){ push_front(v); }
    else
    {
        if(this->is_full()){ grow(); }
        ++_size;
        for(size_t i = (_size-2); i >= pos; i--){
          set(i+1, get(i)); //Muevo los elementod delante de pos hacia delante
        }
        set(pos, v);
        _back = cInc(_back, capacity());
    }
    //
    assert(size() == old_size + 1);
    assert(get(pos) == v);
    assert(get(pos + 1) == old_pos_v);
    assert(get(size() - 1) == old_back);
}

template <class T>
void CDArray<T>::remove(size_t pos)
{
    assert(pos >= 0 && pos < size());
#ifndef NDEBUG
    size_t old_size = size();
    T old_next_pos_v = (pos <= (size() - 2)) ? get(pos + 1) : T();
#endif
    // TODO
    // Remember: back_ needs to be updated.

    for( size_t i = pos; i < _size-1; i++ ){
        set(i, get( i + 1));
    }
    _back = cDec(_back, this->size());
    --_size;

    //
    assert(size() == old_size - 1);
    assert(pos == size() || get(pos) == old_next_pos_v);
}

template <class T>
void CDArray<T>::grow()
{
#ifndef NDEBUG
    size_t old_capacity = capacity();
#endif
    // TODO

    //Crea un puntero a un vector con el doble de la capacidad
    auto tmp= std::shared_ptr<T>(new T[capacity()*2]);

    for(size_t i=0; i<_size; i++){ //Copio en el nuevo toda la información del anterior
        tmp.get()[i] = _data.get()[_front];
        _front=cInc(_front,_capacity);
    }
    _front = 0;
    _back = size()-1; 
    _data = tmp;
    _capacity*=2;

    //
    assert(capacity() == 2 * old_capacity);
}