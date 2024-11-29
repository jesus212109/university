/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include <cassert>
#include <algorithm>
#include <limits>

#include "kdtree.hpp"

KDTree::~KDTree()
{
}

bool KDTree::is_empty() const
{
    bool empty = true;
    // TODO

    //
    return empty;
}

size_t
KDTree::get_k() const
{
    assert(!is_empty());
    size_t k = 0;
    // TODO

    //
    return k;
}

KDTree::KDTree()
{
    // TODO

    //
    assert(is_empty());
}

KDTree::Ref
KDTree::create()
{
    KDTree::Ref ret_v = nullptr;
    // TODO

    //
    assert(ret_v->is_empty());
    return ret_v;
}

BTree<Pattern>::Ref KDTree::btree() const
{
    BTree<Pattern>::Ref ret_v;
    // TODO

    //
    return ret_v;
}

void KDTree::set_btree(BTree<Pattern>::Ref new_tree)
{
    // TODO

    //
}

void KDTree::set_k(size_t k)
{
    // TODO

    //
    assert(get_k() == k);
}

/**
 * @brief Create a level of the kdtree object.
 *
 * Create a binary tree in a recursive way splitting each dimension into two
 * parts using the median as pivot and calling recursively for each part.
 * The pivot will be the root of the binary tree.
 *
 * @param begin is the an iterator at the begin of patterns seq.
 * @param end is the an iterator at the end of patterns seq.
 * @param level is the current level of this subtree.
 * @param k is the number of dimensions of the pattern's space.
 * @return a ref to the binary tree created of this level.
 */
static BTree<Pattern>::Ref
create_kdtree(std::vector<Pattern>::iterator begin,
              std::vector<Pattern>::iterator end,
              size_t level, size_t k)
{
    BTree<Pattern>::Ref btree;
    const size_t size = std::distance(begin, end);
    assert(size > 0);
    // TODO
    // Hint: use a lambda to implement the pattern comparison algorithm.
    // Hint: use std::nth_element algorithm as partial sorting algorithm.

    //
    return btree;
}

KDTree::Ref
KDTree::create(std::vector<Pattern> &dataset)
{
    assert(dataset.size() > 0);
    KDTree::Ref kdtree;
    // TODO

    //
    assert(!kdtree->is_empty());
    return kdtree;
}

void KDTree::fit(std::vector<Pattern> &dataset)
{
    assert(dataset.size() > 0);
    // TODO

    //
    assert(get_k() == dataset[0].dim());
}

KDTree::Ref
KDTree::create(std::istream &in) noexcept(false)
{
    KDTree::Ref kdtree;
    // TODO

    //
    return kdtree;
}

std::ostream &KDTree::fold(std::ostream &out) const
{
    // TODO

    //
    return out;
}

static std::tuple<float, Pattern>
find_candidate(Pattern const &p, BTree<Pattern>::Ref btree, size_t level,
               const Pattern::distance_function_t &dist)
{
    // Which dimension is splitted here.
    size_t axis = level % p.dim();

    Pattern curr = btree->item();
    float curr_dist = dist(p, curr);

    auto curr2 = curr;
    auto curr2_dist = curr_dist;

    //  TODO: step 1.

    //

    // TODO: step 2.

    //

    // TODO: step 3.

    //

    // TODO: step 4.

    //

    return std::make_tuple(curr_dist, curr);
}

std::tuple<float, Pattern>
KDTree::find_nn(Pattern const &p, const Pattern::distance_function_t &dist) const
{
    assert(!is_empty());
    assert(p.dim() == get_k());
    return find_candidate(p, btree(), 0, dist);
}
