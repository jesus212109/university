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
#include <stdexcept>
#include <cassert>

#include "list.hpp"

template <class T>
bool DNode<T>::is_dummy() const
{
    bool ret_v = false;
    // TODO

    ret_v = _item == nullptr;

    //
    return ret_v;
}

template <class T>
DNode<T>::DNode()
{
    // TODO

    //Constructor de nodo vacío
    _item = nullptr;
    _prev = nullptr;
    _next = nullptr;

    //
    assert(is_dummy());
}

template <class T>
DNode<T>::DNode(T const &it)
{
    // TODO

    //Constructor de nodo con item al inicializarlo
    _item = std::make_shared<T>(it);
    _next = nullptr;
    _prev = nullptr;

    //
    assert(!is_dummy());
    assert(next() == nullptr);
    assert(prev() == nullptr);
}

template <class T>
typename DNode<T>::Ref DNode<T>::create()
{
    return std::make_shared<DNode<T>>();
}

template <class T>
typename DNode<T>::Ref DNode<T>::create(T const &it)
{
    return std::make_shared<DNode<T>>(it);
}

template <class T>
DNode<T>::~DNode()
{
    // TODO
    // Hint: if std::shared_ptr is used for the references,
    //   there is nothing todo.

    //Hemos usado sharedptr no hace falta hacer nada

    //
}

template <class T>
T DNode<T>::item() const
{
    assert(!is_dummy());
    T it;
    // TODO

    it = *(_item);

    //
    return it;
}

template <class T>
typename DNode<T>::Ref DNode<T>::prev() const
{
    DNode<T>::Ref n;
    // TODO

    n = _prev;

    //
    return n;
}

template <class T>
typename DNode<T>::Ref DNode<T>::next() const
{
    DNode<T>::Ref n;
    // TODO

    n = _next;

    //
    return n;
}

template <class T>
void DNode<T>::set_item(const T &new_it)
{
    // TODO

    _item = std::make_shared<T>(new_it);



    //
    assert(item() == new_it);
}

template <class T>
void DNode<T>::set_prev(DNode<T>::Ref n)
{
    // TODO

    _prev = n;

    //
    assert(n == prev());
}

template <class T>
void DNode<T>::set_next(DNode<T>::Ref n)
{
    // TODO

    _next = n;

    //
    assert(n == next());
}

template <class T>
List<T>::List()
{
    // TODO
    // Remember: in an empty list, the dummy node is linked with itself.

    _dummy = std::make_shared<DNode<T>>(); //No se podría utilizar Ref
    _dummy->set_next(_dummy);
    _dummy->set_prev(_dummy);
    _size = 0;

    //
    assert(is_empty());
}

template <class T>
List<T>::~List()
{
    // Think. We are using smart pointers (shared_ptr) so the nodes will
    // released automatically when the references going off.


}

template <class T>
typename DNode<T>::Ref List<T>::dummy() const
{
    typename DNode<T>::Ref d;
    // TODO

    d = _dummy;

    //
    return d;
}

template <class T>
typename List<T>::Ref List<T>::create()
{
    auto l = List<T>::Ref(new List<T>);
    l->this_ = l;
    return l;
}

template <class T>
typename List<T>::Ref List<T>::create(std::istream &in) noexcept(false)
{       //Unfold
    List<T>::Ref list;
    std::string token;
    in >> token;

    // TODO
    // Hint: use std::istringstream to convert from "string" to template
    //  parameter T type.
    // Remember: throw std::runtime_error("Wrong input format.") exception when an input
    //  format error was found.
  
    list = List<T>::create();   //Repasar

            if(token == "[")
            {
                in >> token;

                while(!in.eof() && token != "]")
                {
                    std::istringstream tk(token); // Creo un objeto tk de clase istringstring
                    //Su parametro de construcctor le asigno el token
                    T value;
                    tk >> value; //Volcar tk en value que es tipo T

                    if (tk.fail()) // Error si falla la conversión del tipo
                    {
                        throw std::runtime_error("Wrong input format.");
                    }

                    list->push_back(value);
                    in >> token;
                }

                if(token != "]")
                {
                    throw std::runtime_error("Wrong input format.");
                }

            }

            else if(token != "[]")
            {
                throw std::runtime_error("Wrong input format.");
            }

        //
        return list;
}



template <class T>
bool List<T>::is_empty() const
{
    bool ret_val = true;
    // TODO

    ret_val = (_size == 0);

    //
    return ret_val;
}

template <class T>
size_t List<T>::size() const
{
    size_t ret_val = 0;
    // TODO
    ret_val = _size;
    //
    return ret_val;
}

template <class T>
void List<T>::set_size(size_t new_size)
{
    // TODO

    _size = new_size;

    //
    assert(size() == new_size);
}

template <class T>
typename List<T>::iterator List<T>::begin() const
{
    iterator iter;
    // TODO
    // Hint: use iterators.

    iter = ListIterator<T>(_dummy->next());

    //
    return iter;
}

template <class T>
typename List<T>::iterator List<T>::end() const
{
    iterator iter;
    // TODO
    // Hint: use iterators.

    iter = ListIterator<T>(_dummy);

    //
    return iter;
}

template <class T>
T List<T>::front() const
{
    assert(!is_empty());
    T f;
    // TODO
    // Hint: use iterators.

    //f = (_dummy->next())->item();     Lo mismo sin iteradores
    ListIterator<T> iterator = begin();
    f = iterator.item();
    //
    return f;
}

template <class T>
T List<T>::back() const
{


    assert(!is_empty());
    T f;

    // TODO
    // Hint: use iterators.
    //f = (_dummy->next())->item();    Lo mismo sin iteradores

    ListIterator<T> iterator = this->end();
    iterator.goto_prev(1); //Para que en vez de apuntar a dummy, apunte al back
    f = iterator.item();
    //

    return f;
}

template <class T>
void List<T>::fold(std::ostream &out) const
{
    // TODO

    ListIterator<T> it;

           out << "[";
           it = begin();
           while (it != end()) {
               out << " " << it.item();
               it.goto_next(1);
           }
           out << " ]";

    //
}

template <class T>
void List<T>::hook(typename DNode<T>::Ref n, typename DNode<T>::Ref pos)
{
#ifndef NDEBUG
    auto old_size = size();
#endif
    // TODO
    // Remember updating the size.

        //Mirar dibujos en mis apuntes para entender
    n->set_prev(pos->prev());
    n->set_next(pos);
    pos->prev()->set_next(n);
    pos->set_prev(n);
    _size++;
    //
    assert(size() == old_size + 1);
}

template <class T>
void List<T>::unhook(typename DNode<T>::Ref pos)
{
#ifndef NDEBUG
    auto old_size = size();
#endif
    // TODO
    // Remember updating the size.

        //Mirar dibujos en mis apuntes para entender
    pos->prev()->set_next(pos->next());
    pos->next()->set_prev(pos->prev());
    _size--;

    //
    assert(size() == old_size - 1);
}

template <class T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator const &pos,
                                           T const &it)
{
#ifndef NDEBUG
    auto old_is_empty = is_empty();
    auto old_size = size();
    auto old_pos_prev = pos.prev();
#endif
    iterator ret_v;
    // TODO
    // Hint: delegate in hook.

    std::shared_ptr<DNode<T>> n = DNode<T>::create(it);//Creo nodo n, con valor it
    //typename DNode<T>::Ref n(new DNode<T>(it));
    hook(n, pos.node());    //Insterto, con los valores dados
    ret_v.set_node(n);  //Asigno al iterdor ret_v el nodo n creado antes
    //
    assert(!old_is_empty || (front() == it && back() == it));
    assert(old_is_empty || ret_v.next() == pos);
    assert(old_is_empty || old_pos_prev == ret_v.prev());
    assert(size() == (old_size + 1));
    return ret_v;
}

    template <class T>
    typename List<T>::iterator List<T>::remove(List<T>::iterator const &pos)
    {
        assert(!is_empty());
    #ifndef NDEBUG
        auto old_size = size();
        auto old_pos_next = pos.next();
        auto old_pos_prev = pos.prev();
    #endif
        iterator ret_v;
        // TODO
        // Hint: delegate in unkook
        //La función tiene que devolver un iterador que apunte al siguiente nodo del borrado

        //ret_v.set_node(pos.next(1).node()); //DEBUG
        ret_v = pos.next(1);
        //A ret_v le asigno la posición del siguiente a eliminar, (ambos son iteradores)
        unhook(pos.node());

        //
        assert(ret_v == old_pos_next);
        assert(ret_v.prev() == old_pos_prev);
        assert(size() == (old_size - 1));
        return ret_v;
    }

    template <class T>
    void List<T>::push_front(T const &new_it)
    {
    #ifndef NDEBUG
        size_t old_size = size();
    #endif
        // TODO
        //  Hint: delegate in insert();


        insert(begin(), new_it);

        //
        assert(front() == new_it);
        assert(size() == (old_size + 1));
    }

template <class T>
void List<T>::push_back(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    //  Hint: delegate in insert();

    insert(end(), new_it);//Como insert hace hook y hook enlace a la izq de pos,
    //Si lo haces en la pos end() que es el nodo dummy, inserto al final de la lista

    //
    assert(back() == new_it);
    assert(size() == (old_size + 1));
}

template <class T>
void List<T>::pop_front()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    auto old_begin_next = begin().next();
#endif
    // TODO
    // Hint: delegate in remove.

    remove(begin());

    //
    assert(is_empty() || begin() == old_begin_next);
    assert(size() == (old_size - 1));
}

template <class T>
void List<T>::pop_back()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    auto old_end_prev_prev = end().prev().prev();
#endif
    // TODO
    // Hint: delegate in remove.

    remove(end().prev()); //Ojo end apunta a dummy
    
    //
    assert(is_empty() || end().prev() == old_end_prev_prev);
    assert(size() == (old_size - 1));
}

template <class T>
typename List<T>::iterator List<T>::find(T const &it, List<T>::iterator const &from) const
{
    iterator ret_v;
    // TODO

    ret_v = from;
    while (ret_v != end() && ret_v.item() != it) {
            ret_v.goto_next(); // Avanzamos al siguiente elemento
        }

    //
    assert(ret_v == end() || ret_v.item() == it);
    return ret_v;
}

template <class T>
void List<T>::splice(iterator const &pos, Ref list2,
                     iterator const &first, iterator const &last)
{
#ifndef NDEBUG
    size_t old_size = size();
    size_t old_l2_size = list2->size();
    auto old_range_size = first.distance(last);
#endif
    // TODO
    // Hint: if the range [first, last) is empty, nothing must be done.

    //Var
    size_t rangeSize = first.distance(last);
    std::shared_ptr<DNode<T>> posNode = pos.node();
    std::shared_ptr<DNode<T>> posPrevNode = posNode->prev(); //Porque flecha o punto
    std::shared_ptr<DNode<T>> firstNode = first.node();
    std::shared_ptr<DNode<T>> prevFirstNode = firstNode->prev();
    std::shared_ptr<DNode<T>> lastNode = last.node();
    std::shared_ptr<DNode<T>> prevLastNode = lastNode->prev();

    //Splice range into this
    posPrevNode->set_next(firstNode);
    firstNode->set_prev(posPrevNode);
    posNode->set_prev(prevLastNode);
    prevLastNode->set_next(posNode);

    //remove range from list2
    prevFirstNode->set_next(lastNode);
    lastNode->set_prev(prevFirstNode);

    //Update list sizes.
    set_size(size() + rangeSize);
    list2->set_size(list2->size() - rangeSize);

    //
    assert(size() == (old_size + old_range_size));
    assert(list2->size() == (old_l2_size - old_range_size));
}

template <class T>
void List<T>::splice(iterator const &pos, Ref list2)
{
#ifndef NDEBUG
    size_t old_size = size();
    auto old_list2_size = list2->size();
#endif
    // TODO
    // Hint: Delegate in splice the list2 range [begin, end).

    splice(pos, list2, list2->begin(), list2->end());

    //
    assert(size() == (old_size + old_list2_size));
    assert(list2->size() == 0);
    assert(list2->is_empty());
}

template <class T>
void List<T>::splice(iterator const &pos, Ref list2, iterator const &i)
{
#ifndef NDEBUG
    size_t old_size = size();
    auto old_list2_size = list2->size();
#endif
    // TODO
    // Hint: Delegate in splice the list2 range [i, i.next()).

    splice(pos, list2, i, i.next());

    //
    assert(size() == (old_size + 1));
    assert(list2->size() == (old_list2_size - 1));
}

template <class T>
template <class Compare>
void List<T>::merge(List<T>::Ref other, Compare comp)
{
    // TODO
    // Remember: The nodes of the other list are spliced into this list.

    iterator iter1, iter2, temp;

    iter1 = begin();
    iter2 = other->begin();
    while((iter1 != end() ) && (iter2 !=other->end())){
        if(comp(iter1.item(), iter2.item())){
            iter1.goto_next();
        }else{
            temp = iter2;
            iter2.goto_next();
            splice(iter1, other, temp);
        }
    }
    if( iter2 != other->end() ){
        splice( iter1, other);
    }
    //
}

template <class T>
template <class Compare>
void List<T>::sort(Compare comp)
{
    // TODO
    // Remember: we want a complexity in to N Log(N) so mergeSort algorithm is
    // a good candidate to sort the list.
    // Hint: Do a recursive implementation, splitting the list into two halves,
    // sorting recursively each part and merging the sorted lists to obtain
    // the full sorted list.

    // The empty list and a list with only one element are sorted by default.

    //typename List<T>::Ref tmp;   Me lo ahorro con el auto
    iterator midPoint;

    if( size() > 1 ){
        auto tmp = List<T>::create();
        //tmp = std::make_shared<List<T>>();    Hace lo mismo
        midPoint = begin();
        midPoint.goto_next( size() / 2 );
        tmp->splice(tmp->begin(), This(), midPoint, end());
        sort(comp);
        tmp->sort(comp);
        merge(tmp, comp);
    }

    //
}

template <class T>
ListIterator<T>::~ListIterator() {}

template <class T>
bool ListIterator<T>::is_valid() const
{
    bool ret_v = false;
    // TODO
    // Remember: To Invoke node() here will provoque an infinite recursion!!.

    ret_v = node_ != nullptr;

    //
    return ret_v;
}
template <class T>
ListIterator<T>::ListIterator()
{
    // TODO

    node_= nullptr;

    //
    assert(!is_valid());
};

template <class T>
ListIterator<T>::ListIterator(typename DNode<T>::Ref const &n)
{
    // TODO

    node_ = n;

    //
    assert(n != nullptr || !is_valid());
};

template <class T>
T ListIterator<T>::item() const
{
    assert(is_valid());
    T ret_v;
    // TODO

    ret_v = node_->item();


    //
    return ret_v;
}

template <class T>
ListIterator<T> ListIterator<T>::next(size_t dist) const
{
    assert(is_valid());
    ListIterator<T> ret_v;
    // TODO

    for(size_t i = 0; i < dist ; i++) {
        ret_v = node_->next();
    }

    //
    return ret_v;
}

template <class T>
ListIterator<T> ListIterator<T>::prev(size_t dist) const
{
    assert(is_valid());
    ListIterator<T> ret_v;
    // TODO

    for(size_t i = 0; i < dist ; i++) {
        ret_v = node_->prev();
    }

    //
    return ret_v;
}

template <class T>
size_t ListIterator<T>::distance(ListIterator<T> const &other) const
{
    assert(is_valid());
    assert(other.is_valid());
    size_t ret_v = 0;
    //

    ListIterator<T> actual = *this;

    while(actual != other){
        actual = actual.next();
        ret_v++;
    }

    //
    return ret_v;
}

template <class T>
bool ListIterator<T>::operator==(ListIterator<T> const &o) const
{
    bool ret_v = false;

    // TODO
    // Remember: two iterators are equal if both point to the same node.

    ret_v = node_ == o.node_;


    //
    return ret_v;
}

template <class T>
bool ListIterator<T>::operator!=(ListIterator<T> const &o) const
{
    bool ret_v = false;

    // TODO
    // Remember: two iterators are equal if both point to the same node.

    ret_v = node_ != o.node_;
    
    //
    return ret_v;
}

template <class T>
void ListIterator<T>::set_item(T const &it)
{
    assert(is_valid());
    // TODO

    node_->set_item(it);

    //
    assert(it == item());
}

template <class T>
void ListIterator<T>::goto_next(size_t dist)
{
    assert(is_valid());
    // TODO
    for(int i=0; i<dist; i++){
        node_ = node_->next();
    }
    //
}

template <class T>
void ListIterator<T>::goto_prev(size_t dist)
{
    assert(is_valid());
    // TODO

    for(int i=0; i<dist; i++){
        node_ = node_->prev();
    }

    //
}

template <class T>
typename DNode<T>::Ref ListIterator<T>::node() const
{
    typename DNode<T>::Ref ret_v;
    // TODO

    ret_v = node_;

    //
    return ret_v;
}

template <class T>
void ListIterator<T>::set_node(typename DNode<T>::Ref const &n)
{
    // TODO

    node_ = n;
    //
    assert(node() == n);
}
