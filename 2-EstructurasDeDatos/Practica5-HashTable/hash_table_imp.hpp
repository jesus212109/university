/**
 * @file hash_table_imp.hpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#pragma once

#ifdef __DEBUG__
#include <iomanip>
#include <iostream>
#endif

#include <cassert>

#include "hash_table.hpp"

template <class K, class V>
HashTable<K, V>::HashTable(size_t m,
                           const Key_to_uint64_t &key_to_int,
                           OACollisionResolution::Ref hash)
{
    assert(m == hash->m());
    // TODO
    /**
     * @brief Create a new HashTable.
     * @param m is the table size.
     * @param key_to_int is the converter from key values to int value.
     * @param hash is the hash function.
     * @post not is_valid()
     * @post size()==m
     */

    key_to_int_ = key_to_int;
    hash_ = hash;
    used_entries_ = 0;
    table_ = std::vector<HashTableEntry<K, V>>(m);

    //
    assert(size() == m);
}

template <class K, class V>
size_t
HashTable<K, V>::size() const
{
    size_t ret_v = 0;
    // TODO

    ret_v = table_.size();

    //
    return ret_v;
}

template <class K, class V>
float HashTable<K, V>::load_factor() const
{
    float ret_v = 0.0f;
    // TODO

    ret_v = (float)used_entries_/(float)size();

    //
    return ret_v;
}

template <class K, class V>
bool HashTable<K, V>::has(K const &k) const
{
    bool ret_v = false;
    // TODO
    //  Hint: use the find method.

    int idx = find(k);

    if(table_[idx].is_valid() && table_[idx].key() == k){
        ret_v = true;
    }

    //
    return ret_v;
}

template <class K, class V>
size_t HashTable<K, V>::find(K const &k) const
{
    assert(load_factor() < 1.0f);
    size_t idx = 0;
    // TODO
    /**
     * @brief Get a table entry.
     * @param idx is a table position.
     * @return return a const reference to the entry at the table position.
     * @pre 0<=idx<size()
     */
    int iter = 0;

    do{
        idx = hash_->operator()(key_to_int_(k),iter);
        iter++;
    }while(!(table_[idx].is_empty()) && !(table_[idx].key() == k));

    //
    assert(0 <= idx && idx < size());
    return idx;
}

template <class K, class V>
size_t HashTable<K, V>::insert(K const &k, V const &v)
{
    assert(load_factor() <= 0.5f);
    size_t idx = 0;
    // TODO
    // Remember: increment the number of used entries only when an
    // empty entry was used.
    /**
     * @brief Insert a new entry.
     *
     * If the key is currently in the table, the value is updated.
     *
     * @return idx as the table index where the pair <k,v> is saved.
     * @post 0<=idx && idx<size()
     * @post entry(find(k)).is_valid()
     * @post entry(find(k)).get_key()==k
     * @post entry(find(k)).get_value()==v
     */

    idx = find(k);
    if ( table_[idx].is_empty() ){
        used_entries_++;
    }
    table_[idx].set(k,v);
    if(load_factor() > 0.5){
        rehash();
        idx = find(k);
    }

    //
    assert(idx < size());
    assert(entry(idx).is_valid());
    assert(entry(idx).key() == k);
    assert(entry(idx).value() == v);
    assert(load_factor() <= 0.5f);
    return idx;
}

template <class K, class V>
void HashTable<K, V>::remove(size_t idx)
{
#ifndef NDEBUG
    assert(entry(idx).is_valid());
    K old_k = entry(idx).key();
#endif
    // TODO
    // Remember: we are using a mark to sign "deleted".
    /**
     * @brief Remove the entry at the cursor position.
     * @pre entry(idx).is_valid()
     * @post !entry(idx).is_valid()
     * @post !has(old entry(idx).get_key())
     */

    table_[idx].set_deleted();

    //
    assert(!entry(idx).is_valid());
    assert(!has(old_k));
}

template <class K, class V>
size_t HashTable<K, V>::rehash()
{
    // TODO
    // Remember: rehash when load_factor > 0.5
    // Remember: we use a 2 factor to grown the current size.
    // Remember: a new hash function will be picked at random from the Universal Family.
    // Remember: reset the number of used entries to zero before inserting the old valid
    // entries in the new table.
    /**
     * @brief Generate a new table with doble size when load factor > 0.5
     * @return the table size (the old size if growing was not necessary).
     * @post load_factor()<=0.5
     */

    std::vector<HashTableEntry<K,V>> oldT;

    if(load_factor() > 0.5){
        oldT = table_;
        table_ = std::vector<HashTableEntry<K,V>>(oldT.size()*2);
        hash_=hash_->pick_at_new(oldT.size()*2);
        used_entries_ = 0;

        for( auto it : oldT ){
            if( it.is_valid() ){
                insert(it.key(), it.value());
            }
        }
    }

    //
    assert(load_factor() <= 0.5);
    return size();
}

template <class K, class V>
HashTableEntry<K, V> const &HashTable<K, V>::entry(size_t idx) const
{
    assert(idx < size());
    // TODO: recode according to your representation.
    return table_[idx];
    //
}

template <class K, class V>
HashTableEntry<K, V> &HashTable<K, V>::entry(size_t idx)
{
    assert(idx < size());
    // TODO: recode according to your representation.
    return table_[idx];
    //
}

template <class K, class V>
V const &HashTable<K, V>::operator[](K const &k) const
{
    assert(has(k));
    // TODO: recode according to your representation.
    auto idx = find(k);
    return table_[idx].value();
    //
}

template <class K, class V>
V &HashTable<K, V>::operator[](K const &k)
{
    // TODO: recode according to your representation.
    // Remember: if an entry exits for the key, return a reference to its value,
    // else insert a new entry pair <k, _> and return a reference to its value.
    auto idx = find(k);
    if (!table_[idx].is_valid()){
        table_[idx].set(k, V() ); // V() es un constructor vacío
    }
    return table_[idx].value();
    //
}
