/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "pattern.hpp"

Pattern::Pattern(const size_t d, const int cl)
{
    // TODO

    //
    assert(dim() == d);
    assert(class_label() == cl);
}

Pattern::Pattern(const float values[], const size_t size, const int cl)
{
    assert(size>0);
    // TODO

    //
    assert(dim() == size);
    assert(class_label() == cl);
}

Pattern::Pattern(const std::vector<float>& values, const int cl)
{
    assert(values.size()>0);
    // TODO

    //
    assert(dim() == values.size());
    assert(class_label() == cl);
}

Pattern::Pattern(const std::valarray<float>& values, const int cl)
{
    assert(values.size()>0);
    // TODO

    //
    assert(dim() == values.size());
    assert(class_label() == cl);
}

std::valarray<float>
Pattern::values () const
{
    std::valarray<float> vs;
    // TODO

    //
    return vs;
}

Pattern Pattern::copy() const
{
    Pattern ret_v;
    // TODO: return a deep copy of this.

    //
    return ret_v;    
}

Pattern::~Pattern()
{;}

size_t Pattern::dim() const
{
    size_t d = 0;
    // TODO

    //
    return d;
}

bool Pattern::operator==(const Pattern& o)
{
    assert( dim()==o.dim());
    bool ret_val = false;
    // TODO

    //
    assert(!ret_val || class_label() == o.class_label());
    assert(!ret_val || (*this-o).abs().sum()==0.0);
    return ret_val;    
}

void Pattern::set_dim(size_t new_dim)
{
    // TODO

    //
    assert(dim()==new_dim);
}

int Pattern::class_label() const
{
    int cl = -1;
    // TODO

    //
    return cl;
}

float Pattern::operator [](const size_t idx) const
{
    assert(idx < dim());
    float v = 0.0;
    // TODO

    //
    return v;
}

float Pattern::sum() const
{
    float s = 0.0;
    // TODO

    //
    return s;
}

float Pattern::max() const
{
    float m = 0.0;
    // TODO

    //
    return m;
}

float Pattern::min() const
{
    float m = 0.0;
    // TODO

    //
    return m;
}

void Pattern::set_class_label(const int new_label)
{
    // TODO

    //
    assert (class_label() == new_label);
}

void Pattern::set_value(const size_t idx, const float new_val)
{
    assert(idx < dim());
    // TODO

    //
    assert((*this)[idx]==new_val);
}

Pattern& Pattern::operator += (const Pattern& o)
{
    assert(o.dim()==dim());
    // TODO

    //
    return *this;
}

Pattern& Pattern::operator -= (const Pattern& o)
{
    assert(o.dim()==dim());
    // TODO

    //
    return *this;
}

Pattern& Pattern::operator *= (const Pattern& o)
{
    assert(o.dim()==dim());
    // TODO

    //
    return *this;
}

Pattern& Pattern::operator /= (const Pattern& o)
{
    assert(o.dim()==dim());
    // TODO

    //
    return *this;
}

Pattern& Pattern::operator *= (const float c)
{
    // TODO

    //
    return *this;
}

Pattern& Pattern::operator /= (const float c)
{
    // TODO

    //
    return *this;
} 

Pattern& Pattern::abs()
{
    //TODO

    //
    return *this;
}

std::ostream& Pattern::fold(std::ostream& output) const
{
    // TODO
    // Remember: format "[ class_label [ v0 v1 ... vn-1 ] ]"

    //
    return output;
}

std::ostream& operator << (std::ostream& output, const Pattern& p)
{
    // TODO
    // Hint: use p.fold()

    //
    return output;
}


Pattern::Pattern(std::istream &input) noexcept(false)
{
    // TODO
    // Remember: input format is "[ class_label [ <dim_0> <dim_1> ... <dim_size-1> ] ]"

    //
}

std::istream &operator>>(std::istream &input, Pattern &p) noexcept(false)
{
    assert(input);
    p = Pattern(input);
    return input;
}

float
distance_L2(const Pattern& a, const Pattern& b)
{
    float dist = 0.0;
    // TODO

    //
    assert(dist >= 0.0);    
    return dist;
}

float
distance_L1(const Pattern& a, const Pattern& b)
{
    float dist = 0.0;
    // TODO

    //
    assert(dist >= 0.0);    
    return dist;
}


std::istream&
load_dataset(std::istream& input,
                  std::vector<Pattern>& dts) noexcept(false)
{
    // TODO
    // Remember: input format is
    // "<size_t num_patterns> <size_t pattern_dimensions>
    // <p_0>
    // <p_1>
    // ...
    // <p_num_patterns-1>
    // "

    //
    return input;
}
