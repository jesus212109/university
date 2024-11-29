/**
 * @file hash.cpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#ifdef __DEBUG__
#include <iomanip>
#include <iostream>
#endif

#include <cassert>
#include <cstdlib>
#include "hash.hpp"

/**Global object to generate random bits.*/
std::minstd_rand Generator;

double
uniform()
{
    double ret_v = 0.0;
    // TODO
    // Hint: Use std::uniform_real_distribution<double>
    // Remember: use Generator as random bit generator.
    /**
     * @brief Generate an uniform random number in [0.0, 1.0) interval.
     * @return the random number.
     * @post ret_v in [0.0, 1.0)
     */

    std::uniform_real_distribution<double> dis(0,1); //dis es un objeto que representa una distribución uniforme, de numeros reales en este caso
    ret_v = dis(Generator); //Generator dice la forma de generar los Nº aleatorios

    //
    assert(0.0l <= ret_v && ret_v < 1.0l);
    return ret_v;
}

std::uint64_t
pick_at_random(std::uint64_t const &a, std::uint64_t const &b)
{
    assert(a < b);
    std::uint64_t ret_v = 0;
    // TODO
    // Hint: Use std::uniform_int_distribution<std::uint64_t>
    /**
     * @brief pick at random a value from the integer range [a, b).
     * @param a is lower bound of the range (inclusive).
     * @param b is upper bound of the range (exclusive).
     * @return the picked up value.
     * @prec a<b
     * @post ret_v in [a,b)
     */

    std::uniform_int_distribution<std::uint64_t> dis(a,b);
    ret_v = dis(Generator);

    //
    assert(a <= ret_v && ret_v <= b);
    return ret_v;
}

//////////////////////////////////////////////////////////////
// Universal hash function.
//////////////////////////////////////////////////////////////

UHash::UHash()
{
    m_ = 2;
    p_ = 4294967311l;
    a_ = pick_at_random(std::uint64_t(1), p_);
    b_ = pick_at_random(std::uint64_t(0), p_);

    assert(m() == 2);
    assert(p() == 4294967311l);
    assert(0 < a() && a() < p());
    assert(0 <= b() && b() < p());
}

UHash::UHash(size_t M)
{
    assert(M > 1 && (M & (M - 1)) == 0); // m is two power.
    assert(M < 4294967311l);

    m_ = M;
    p_ = 4294967311l;
    a_ = pick_at_random(std::uint64_t(1), p_);
    b_ = pick_at_random(std::uint64_t(0), p_);

    assert(M == m());
    assert(p() == 4294967311l);
    assert(0 < a() && a() < p());
    assert(0 <= b() && b() < p());
}

UHash::Ref
UHash::create(std::uint64_t m)
{
    return std::make_shared<UHash>(m);
}

UHash::UHash(size_t M, std::uint64_t P, std::uint64_t A,
             std::uint64_t B)
{
    assert(M > 1 && (M & (M - 1)) == 0); // m is two power.
    assert(M < P);
    assert(0 < A && A < P);
    assert(0 <= B && B < P);

    m_ = M;
    p_ = P;
    a_ = A;
    b_ = B;

    assert(M == m());
    assert(P == p());
    assert(A == a());
    assert(B == b());
}

UHash::Ref UHash::create(size_t m, std::uint64_t p, std::uint64_t a,
                         std::uint64_t b)
{
    return std::make_shared<UHash>(m, p, a, b);
}

UHash::Ref UHash::pick_at_new(std::uint64_t const &new_m) const
{
    assert(new_m > 1 && (new_m & (new_m - 1)) == 0); // new_m is two power.
    assert(new_m < p());

    UHash::Ref new_f;
    new_f = UHash::create(new_m);

    assert(new_f->m() == new_m);
    assert(new_f->p() == p());
    assert(new_f->a() != a() || new_f->b() != b());
    return new_f;
}

size_t
UHash::operator()(std::uint64_t k) const
{
    assert(k < p());
    size_t hash = 0;

    // TODO
    // Hint: use static_cast to static type conversions.
    /**
     * @brief hash a key.
     * Hash the key to get a table index.
     * @param k is the key to be hashed.
     * @return the table index.
     * @pre k<p()
     * @post 0<=ret_v<m()
     */
    //( (a*k+b) %p) %m

    hash = static_cast<size_t> ( ( (a()*k+b() ) %p() ) %m() );


    //

    assert(hash < m());
    return hash;
}

std::uint64_t const &
UHash::m() const
{
    return m_;
}

std::uint64_t const &
UHash::p() const
{
    return p_;
}

std::uint64_t const &
UHash::a() const
{
    return a_;
}

std::uint64_t const &
UHash::b() const
{
    return b_;
}

//////////////////////////////////////////////////////////////
// Open Addressing Collision Resolution Methods.
//////////////////////////////////////////////////////////////

OACollisionResolution::OACollisionResolution(UHash const &hash_f)
    : hash_f_(hash_f)
{
}

UHash const &
OACollisionResolution::hash() const
{
    return hash_f_;
}
std::uint64_t
OACollisionResolution::m() const
{
    return hash().m();
}

//////////////////////////////////////////////////////////////
// Linear Probing hash function.
//////////////////////////////////////////////////////////////

LPHash::LPHash(UHash const &hash_f)
    : OACollisionResolution(hash_f)
{
}

OACollisionResolution::Ref
LPHash::create(UHash const &hash_f)
{
    return std::make_shared<LPHash>(hash_f);
}

OACollisionResolution::Ref
LPHash::pick_at_new(std::uint64_t new_m) const
{
    assert(new_m > 1 && (new_m & (new_m - 1)) == 0);
    return LPHash::create(UHash(new_m));
}

size_t
LPHash::operator()(uint64_t k, size_t iter) const
{
    size_t ret_v = 0;
    // TODO
    // Remember: if iter == 0 (first attempt), compute the hash value.
    //          iter>0 means a collision happened so get the next proper value
    //          regarding the collision algorithm.
    // Hint: you could save the first value in a static variable to avoid recompute it when
    //       a collision happened.

    static size_t h;
    if(iter == 0){
        h = hash()(k); //Obj observador hash que devuelve obj hash con parametro k
        ret_v = h;
    }else{
        ret_v = (h + iter) %m();
    }

    //
    return ret_v;
}

//////////////////////////////////////////////////////////////
// Quadratic Probing hash function.
//////////////////////////////////////////////////////////////

QPHash::QPHash(UHash const &hash_f)
    : OACollisionResolution(hash_f)
{
}

OACollisionResolution::Ref
QPHash::create(UHash const &hash_f)
{
    return std::make_shared<QPHash>(hash_f);
}

OACollisionResolution::Ref
QPHash::pick_at_new(std::uint64_t new_m) const
{
    assert(new_m > 1 && (new_m & (new_m - 1)) == 0);
    return QPHash::create(UHash(new_m));
}

size_t
QPHash::operator()(std::uint64_t k, size_t iter) const
{
    size_t ret_v = 0;
    // TODO
    // Remember: if iter == 0 (first attempt), compute the hash value.
    //          iter>0 means a collision happened so get the next proper value
    //          regarding the collision algorithm.
    // Hint: you could save the first value to avoid recompute it when
    //       a collision happened.
    // Remember: m is two power and c1= c2 = 1/2.

    static size_t h;
    if(iter == 0){
        h = hash()(k); //Obj observador hash que devuelve obj hash con parametro k
        ret_v = h;
    }else{
        ret_v = ( (h+(iter + iter*iter)/2 )%m() );
    }

    //
    return ret_v;
}

//////////////////////////////////////////////////////////////
// Random Probing hash function.
//////////////////////////////////////////////////////////////

RPHash::RPHash(UHash const &hash_f, std::uint64_t c)
    : OACollisionResolution(hash_f)
{
    assert(!(c <= m()) || (m() % c != 0));
    assert(!(m() <= c) || (c % m() != 0));
    c_ = c;
}

RPHash::RPHash(UHash const &hash_f)
    : OACollisionResolution(hash_f)
{
    c_ = (m() >> 1) - 1;
}

OACollisionResolution::Ref
RPHash::create(UHash const &hash_f)
{
    return std::make_shared<RPHash>(hash_f);
}

OACollisionResolution::Ref
RPHash::create(UHash const &hash_f, std::uint64_t c)
{
    return std::make_shared<RPHash>(hash_f, c);
}

OACollisionResolution::Ref
RPHash::pick_at_new(std::uint64_t new_m) const
{
    assert(new_m > 1 && (new_m & (new_m - 1)) == 0);
    return RPHash::create(UHash(new_m));
}

std::uint64_t const &
RPHash::c() const
{
    return c_;
}

size_t
RPHash::operator()(std::uint64_t k, size_t iter) const
{
    size_t ret_v = 0;
    // TODO
    // Remember: if iter == 0 (first attempt), compute the hash value.
    //         iter>0 means a collision happened so get the next proper value
    //         regarding the collision algorithm.
    // Hint: you could save the first value to avoid recompute it when
    //      a collision happened.

    static size_t h;
    if(iter == 0){
        h = hash()(k); //Obj observador hash que devuelve obj hash con parametro k
    }else{
        h = ( h + c() )%m();
    }
    ret_v = h;
    //La estructura es distinta ya que reasignamos el valor de de h en cada caso

    //

    return ret_v;
}

//////////////////////////////////////////////////////////////
// Rehashing hash function.
//////////////////////////////////////////////////////////////

RHash::RHash(UHash const &hash_f, std::vector<UHash> const &hash_fs)
    : OACollisionResolution(hash_f)
{
#ifndef NDEBUG
    for (size_t i = 0; i < hash_fs.size(); ++i)
    {
        assert(hash_fs[i].m() == hash_f.m());
        assert(hash_fs[i].p() == hash_f.p());
    }
#endif
    hash_fs_ = hash_fs;
}

OACollisionResolution::Ref
RHash::create(UHash const &hash_f, std::vector<UHash> const &hash_fs)
{
    return std::make_shared<RHash>(hash_f, hash_fs);
}

const std::vector<UHash> &
RHash::hash_fs() const
{
    return hash_fs_;
}

OACollisionResolution::Ref
RHash::pick_at_new(std::uint64_t new_m) const
{
    assert(new_m > 1 && (new_m & (new_m - 1)) == 0);
    std::vector<UHash> new_hash_fs;
    for (size_t i = 0; i < hash_fs().size(); ++i)
        new_hash_fs.push_back(UHash(new_m));

    return RHash::create(UHash(new_m), new_hash_fs);
}

size_t
RHash::operator()(std::uint64_t k, size_t iter) const
{
    size_t ret_v = 0;
    // TODO
    // Remember: if iter == 0 (first attempt), compute the hash value using
    // the hash_fs()[0], iter==1 using hash_fs()[1], ..., for iter>=hash_fs().size()
    // use linear probing from the last hash value.

//    static size_t h;
//    if(iter <= hash_fs().size()){
//        h = hash_fs()[iter](k);
//        ret_v = h;
//    }else{
//        ret_v = LPHash::operator ()(k, iter - hash_fs().size() );
//    }

    static size_t h;
    if(iter == 0){
        h = hash()(k);
    }else{
       if( iter - 1 < hash_fs().size()){
            h = hash_fs()[iter - 1](k);
       }
       else{
           h = (h + 1) % m(); //No puedo sumar iter, quiero avanzar de uno en uno en LP
       }
    }
    ret_v = h;

    //

    return ret_v;
}
