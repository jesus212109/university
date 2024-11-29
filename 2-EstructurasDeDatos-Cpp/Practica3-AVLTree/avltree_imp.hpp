/**
 * @file avltree_imp.hpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once
#include <cassert>

#include "avltree.hpp"

/****
 * AVLTNode class implementation.
 ****/

template <class T>
AVLTNode<T>::AVLTNode(T const &it)
{
    // TODO

    item_ = it;
    height_ = 0;
    parent_ = nullptr;
    left_ = nullptr;
    right_ = nullptr;

    //
    assert(check_height_invariant());
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::create(T const &it)
{
    return std::make_shared<AVLTNode<T>>(it);
}

template <class T>
AVLTNode<T>::AVLTNode(T const &it, AVLTNode<T>::Ref parent,
                      AVLTNode<T>::Ref left, AVLTNode<T>::Ref right)
{
    // TODO

    item_ = it;
    parent_ = parent;
    left_ = left;
    right_ = right;
    update_height();
    //Necesario Comprobar que left/rignht->height no sea NULL, para actualizando en cada insert la altura


    //
    assert(check_height_invariant());
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::create(T const &it,
                                              AVLTNode<T>::Ref parent,
                                              AVLTNode<T>::Ref left,
                                              AVLTNode<T>::Ref right)
{
    return std::make_shared<AVLTNode<T>>(it, parent, left, right);
}

template <class T>
T AVLTNode<T>::item() const
{
    T value = T();
    // TODO
    value = item_;
    //
    return value;
}

template <class T>
int AVLTNode<T>::height() const
{
    int height = 0;
    // TODO
    height = height_;
    //
    return height;
}

template <class T>
int AVLTNode<T>::balance_factor() const
{
    int bf = 0;
    // TODO

    //bf = (right()->height()) - (left()->height()); //MAL  --->  //Necesario Comprobar que left/rignht->height no sea NULL,
    //porque si hight es nulptr = violación de segmento

    int left_h = left() != nullptr ? left()->height() : -1;
    int right_h = right() != nullptr ? right()->height() : -1;
    bf = right_h - left_h;
    
    // si negativo desbalance izq (rot der) 
    //si positivo desbalance der (rot izq)

    //
    return bf;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::parent() const
{
    AVLTNode<T>::Ref node;
    // TODO
    node = parent_;
    //
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::child(int dir) const
{
    assert(dir == 0 || dir == 1);
    AVLTNode<T>::Ref node;
    // TODO
    (dir == 0) ? node = left_ : node = right_;
    //
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::left() const
{
    AVLTNode<T>::Ref node;
    // TODO
    node = child(0);
    //
    assert(node == child(0));
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::right() const
{
    AVLTNode<T>::Ref node;
    // TODO
    node = child(1);
    //
    assert(node == child(1));
    return node;
}

template <class T>
bool AVLTNode<T>::check_height_invariant() const
{
    bool ret_val = false;
    // TODO

    int left_h = left() != nullptr ? left()->height() : -1;
    int right_h = right() != nullptr ? right()->height() : -1;
    ret_val = height() == 1 + std::max(right_h, left_h);

    //
    return ret_val;
}

template <class T>
void AVLTNode<T>::set_item(const T &new_it)
{
    // TODO
    item_ = new_it;
    //
    assert(item() == new_it);
}

template <class T>
void AVLTNode<T>::set_parent(AVLTNode<T>::Ref new_parent)
{
    // TODO
    parent_ = new_parent;
    //
    assert(parent() == new_parent);
}

template <class T>
void AVLTNode<T>::set_child(int dir, Ref new_child)
{
    assert(dir == 0 || dir == 1);
    // TODO
    // Remember to update the height property.
    (dir == 0) ? left_ = new_child : right_ = new_child;
    update_height();
    //
    assert(check_height_invariant());
    assert(dir == 0 || right() == new_child);
    assert(dir == 1 || left() == new_child);
}

template <class T>
void AVLTNode<T>::set_left(Ref new_child)
{
    // TODO
    // Remember to update the height property.
    set_child(0,new_child);
    //
    assert(check_height_invariant());
    assert(left() == new_child);
}

template <class T>
void AVLTNode<T>::set_right(AVLTNode<T>::Ref new_child)
{
    // TODO
    // Remember to update the height property.
    set_child(1,new_child);
    //
    assert(check_height_invariant());
    assert(right() == new_child);
}

template <class T>
void AVLTNode<T>::update_height()
{
    // TODO
    // Remember: we want O(1) here.

    int left_h = left() != nullptr ? left()->height() : -1;
    int right_h = right() != nullptr ? right()->height() : -1;
    height_ = 1 + std::max(right_h, left_h);

    //
    assert(check_height_invariant());
}

/***
 * AVLTree class implementation.
 ***/

template <class T>
AVLTree<T>::AVLTree()
{
    // TODO

    parent_ = nullptr;
    current_ = root_;     //Se inicializa apuntando a la raíz , hace falta después para insertar y borrar
    root_ = nullptr;

    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(is_empty());
}

template <class T>
AVLTree<T>::AVLTree(T const &item)
{
    // TODO
    root_ = AVLTNode<T>::create(item);
    parent_ = nullptr;
    current_ = root_;

    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(!is_empty());
}

template <class T>
AVLTree<T>::AVLTree(std::istream &in) noexcept(false)
{
    // TODO
        /**
     * @brief Unfold an AVLTree from an input stream.
     * The input format will be:
     * '[]' for the empty tree.
     * '[ '<item>' '<left-subtree>' '<right-subtree>' ]'
     *
     * For example a tree with three nodes:
     * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
     *
     * @param in is the input stream.
     * @param parent is the parent node of the node to be unfolded.
     * @return The node unfolded on success.
     * @warning std::runtime_error("Wrong input format."),
     * std::runtime_error("It is not a binary search tree") or
     * std::runtime_error("It is not an avl bstree") will throw if an error
     * happened.
     */

    std::string token;
    T it;
    in >> token;

    if (token == "[")
    {
        in >> it;
        if (in.fail()){
            throw std::runtime_error("Wrong input format.");
        }
        
        root_ = AVLTNode<T>::create(it);
        auto l = AVLTree<T>(in);
        auto r = AVLTree<T>(in);
        set_left(l);
        set_right(r);

        in >> token;
        if(token != "]"){
          throw std::runtime_error("Wrong input format.");
        }
    }
    else if (token != "[]"){
        throw std::runtime_error("Wrong input format.");
    }

    //

    if (!is_a_binary_search_tree())
        throw std::runtime_error("It is not a binary search tree");
    if (!is_a_balanced_tree())
        throw std::runtime_error("It is not an avl tree");
}

#ifdef __ONLY_BSTREE__
/**
 * @brief Create an perfectly balanced BSTree by inserting the median of
 *        an ordered sub sequence data[begin, end).
 * @param data is the ordered sequence of values.
 * @param begin,
 * @param end specify a [begin, end) indexing interval of array data to use.
 * @pre 0 <= begin <= end <=data.size()
 * @pre begin==end || data[begin]<data[end];
 */
template <class T>
void create_inserting_median(std::vector<T> const &data,
                             size_t begin,
                             size_t end,
                             AVLTree<T> &tree)
{
    assert(begin <= end);
    assert(end <= data.size());
    assert(begin == end || data[begin] <= data[end - 1]);

    // TODO
    // Hint: if (end==begin) none thing must be done (it is an empty sub array)
    //  else, insert the median in the tree and (recursively) process
    //  the two sub sequences [begin, median_idx) and [median_idx+1, end)
    if ((end - begin) >= 1)
    {
        tree.insert(data[begin + ((end - begin) / 2)]);
        create_inserting_median(data, begin, (begin + ((end - begin) /2)), tree);
        create_inserting_median(data, (begin + ((end - begin) / 2)) + 1, end, tree);
    }
    //
}

template <class T>
AVLTree<T>
create_perfectly_balanced_bstree(std::vector<T> &data)
{
    AVLTree<T> tree;
    // TODO
    // Remember: the empty tree is perfectly balanced.
    // Remember: first, an ordered sequence (using < order) of values is needed.
    // Then you should use the above create_inserting_median function
    // on a empty tree to recursively create the perfectly balanced bstree.
    std::sort(data.begin(),data.end());
    create_inserting_median(data,0,data.size(),tree);
    //
    return tree;
}
#endif //__ONLY_BSTREE__

template <class T>
bool AVLTree<T>::is_empty() const
{
    bool empty = true;
    // TODO

    empty = root_ == nullptr;
    //Un árbol de búsqueda cuyo valor de la raíz sea nulo, sera siempre un árbol vacío

    //
    return empty;
}

template <class T>
T AVLTree<T>::item() const
{
    assert(!is_empty());
    T value = T();
    // TODO

    value = root_->item();

    //
    return value;
}

template <class T>
std::ostream &AVLTree<T>::fold(std::ostream &out) const
{
    // TODO
        /**
     * @brief Fold an AVLTree into an output stream.
     *  * The output format will be:
     * [ <item> <left> <right> ] or [] if it is a empty tree.
     * @param out is the output stream.
     * @return the output stream.
     *
     * EJ)  "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"                 Recorrido Prefijo
     */   

    if (is_empty())
      out<<"[]";
    else{
      out<<"[ ";
      out<<item();
      out<<" ";

      left().fold(out);

      out<<" ";
      right().fold(out);
      out<<" ]";
    }

    //
    return out;
}

template <class T>
bool AVLTree<T>::current_exists() const
{
    bool exists = false;
    // TODO

    exists = current_ != nullptr;

    //
    return exists;
}

template <class T>
T AVLTree<T>::current() const
{
    assert(current_exists()); // Initialized to prevent in compile error : Carlos
    T value = T();
    // TODO

    value = current_->item();

    //
    return value;
}

template <class T>
int AVLTree<T>::current_level() const
{
    assert(current_exists());
    int level = 0;
    // TODO
    //Da la distancia entre el curr y el root

    auto p = current_node()->parent();
    while (p != nullptr)
    {
        p = p->parent();
        level++;
    }

    //
    return level;
}

template <class T>
AVLTree<T> AVLTree<T>::left() const
{
    assert(!is_empty());
    AVLTree<T> subtree;
    // TODO

    subtree = AVLTree(root_node()->left());

    //
    return subtree;
}

template <class T>
AVLTree<T> AVLTree<T>::right() const
{
    assert(!is_empty());
    AVLTree<T> subtree;
    // TODO

    subtree = AVLTree(root_node()->right());

    //
    return subtree;
}

template <class T>
int AVLTree<T>::size() const
{
    int s = 0;
    // TODO

   if(!is_empty)
        s = 1 + current_->left()->size() + current_->right()->size();
    else    
        return 0;

    //
    return s;
}

template <class T>
int AVLTree<T>::height() const
{
    int h = 0;
    // TODO
    // Remember: we want O(1) here.
   
    if(!is_empty())
        h = root_->height();
    else
       h = -1;

    //
    return h;
}

template <class T>
int AVLTree<T>::balance_factor() const
{
#ifdef __ONLY_BSTREE__
    return 0;
#else
    int bf = 0;
    // TODO

    bf = root_node()->balance_factor();

    //
    return bf;
#endif
}

template <class T>
bool AVLTree<T>::has(const T &k) const
{
#ifndef NDEBUG
    bool old_current_exists = current_exists();
    T old_current;
    if (old_current_exists)
        old_current = current();
#endif

    bool found = true;

    // TODO
    // Hint: you can reuse the search method for this but in this case you will
    //       need to use "const_cast" to remove constness of "this" and
    //       save/restore the old state of current before returning.

    auto aux = root_node();//Trabajo con un árbol auxiliar para no alterar el original

    while (aux != nullptr && aux->item() != k)
    {
        aux = k < aux->item() ? aux->left() : aux->right();
    }
    
    found = aux != nullptr;
    //

#ifndef NDEBUG
    assert(!old_current_exists || old_current == current());
#endif
    return found;
}

/**
 * @brief infix process of a node.
 * The Processor must allow to be used as a function with a parameter  (the
 * item to be processed) and returning true if the process must continue or
 * false if not.
 * @param node is the node to be processed.
 * @param p is the Processor.
 * @return true if all the tree was in-fix processed.
 */
template <class T, class Processor>
bool infix_process(typename AVLTNode<T>::Ref node, Processor &p)
{
    bool retVal = true;
    // TODO
    // Remember: if node is nullptr return true.

    if (node != nullptr){
        retVal = retVal && infix_process<T>(node->left(),p);
        retVal = p(node->item());
        retVal = retVal && infix_process<T>(node->right(),p);
        //retval && para obviar el caso en el que sea null o valga 0, ya que el compilador   
        //saltará la segunda parte del AND
    }

    //
    return retVal;
}

template <class T>
bool AVLTree<T>::is_a_binary_search_tree() const
{
    bool is_bst = true;
    // TODO
    // Remember: a empty tree is a binary search tree.
    //
    // Remember: for a non empty binary search tree, the in-fix traversal from
    // the root node must follow an ordered sequence of items.
    //
    // Remember: use a lambda function with signature '(T v) -> bool' to
    //  implement the Processor.
    //

    if(is_empty())
    {
        return true;
    }
    
    bool first = true;
    T prenum;

    auto l = [&first,&prenum](T value) -> bool
    {
        if(first)
        {
            prenum = value;
            first = false;
            return true;
        }

        if(prenum < value)
        {
            prenum = value;
            return true;
        }
        return false;
    };

    is_bst = infix_process<T>(root_node(),l);

    //
    return is_bst;
}

template <class T>
bool AVLTree<T>::is_a_balanced_tree() const
{
#ifdef __ONLY_BSTREE__
    return true;
#else
    bool is_balanced = true;
    // TODO
    // Remember: a empty tree is balanced.
    //
    // Remember: A non empty tree is balanced if both children are balanced
    // and the absolute value of the balance factor of the tree is less or
    // equal to one.

    if (is_empty())
    {
        return true;
    }
    
    if (std::abs(balance_factor()) <= 1)
    {
        is_balanced = is_balanced && left().is_a_balanced_tree();
        is_balanced = is_balanced && right().is_a_balanced_tree();
    }
    else
    {
        is_balanced = false;
    }
    
    //
    return is_balanced;
#endif
}

template <class T>
void AVLTree<T>::create_root(T const &v)
{
    assert(is_empty());
    // TODO

    root_ = std::make_shared<AVLTNode<T>>(v);

    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(!is_empty());
    assert(item() == v);
}

template <class T>
bool AVLTree<T>::search(T const &k)
{
    bool found = false;
    // TODO

    current_ = root_;
    parent_ = nullptr;
    while (current_ != nullptr && !found){
        if (current_->item() == k)
            found = true;
        else
        {
            parent_ = current_;
            current_->item() > k ? (current_ = current_->left()) : (current_ = current_->right());
        }
    }

    //
    assert(!found || current() == k);
    assert(found || !current_exists());
    return found;
}

template <class T>
void AVLTree<T>::insert(T const &k)
{
    // Check invariants.
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());

    // TODO
    // Remember: after inserting you must balance the tree using make_balanced()
    if (!search(k))
    {
        // TODO

        current_ = AVLTNode<T>::create(k, parent_, nullptr, nullptr);

        if (is_empty()){
            root_ = current_;
            parent_ = nullptr;
        }
        else{
            parent_->item() > k? (parent_->set_left(current_)) : (parent_->set_right(current_));
        }
        //Al usar set_left y set_right ya se está insertando de forma balanceada

        //
        assert(check_parent_chains());
        make_balanced();
        assert(check_parent_chains());
    }
    // Check invariants.
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());

    // check postconditions.
    assert(current_exists());
    assert(current() == k);
}

template <class T>
void AVLTree<T>::remove()
{
    // check preconditions.
    assert(current_exists());

#ifndef NDEBUG
    // the invariants only must be checked for the first recursive call.
    // We use a static variable to count the recursion levels.
    // see section "Static variables in a Function" in
    // ref https://www.geeksforgeeks.org/static-keyword-cpp/ for more info.
    static int recursion_count = 0;
    recursion_count++;
    if (recursion_count == 1)
    {
        // Check invariants.
        assert(is_a_binary_search_tree());
        assert(is_a_balanced_tree());
    }
#endif // NDEBUG

    bool replace_with_subtree = true;
    typename AVLTNode<T>::Ref subtree;

    // TODO
    //  Check which of cases 0,1,2,3 we have (see theorical class slides).

    //Si no tenemos ni izq ni dcho, entramos
    if (current_->right() == nullptr && current_->left() == nullptr) 
    subtree = nullptr;

    // Entramos si no tiene izq
    else if (current_->left() == nullptr) 
    subtree = current_->right();
    
    // Entramos si no tiene dcho
    else if (current_->right() == nullptr) 
    subtree = current_->left();

    // Entramos si tenemos izquierdo y derecho
    else 
    replace_with_subtree = false;
    //

    if (replace_with_subtree)
    {
        // TODO
        // Manage cases 0,1,2
        // Remember: update subtree to parent links too.

        // Entramos si el padre es nulo
        if (parent_ == nullptr) 
        root_ = subtree;
        
        // Entramos si el actual es igual al izq del padre 
        else if (current_ == parent_->left()) 
        parent_->set_left(subtree);

        // Entramos si el actual es igual al dcho del padre
        else if (current_ == parent_->right()) 
        parent_->set_right(subtree);

        if(subtree)
            subtree->set_parent(parent_);

        //  
        assert(check_parent_chains());
        make_balanced();
        assert(check_parent_chains());

        set_current_node(nullptr);
    }
    else
    {
        // TODO
        // Manage case 3.

        auto x = current_;
        find_inorder_sucessor();
        x->set_item(current_->item());
        remove();

        //
    }

#ifndef NDEBUG
    // We come back so the recursion count must be decreased.
    recursion_count--;
    assert(recursion_count >= 0);
    if (recursion_count == 0)
    {
        // Only check for the last return.
        // Check invariants.
        assert(is_a_binary_search_tree());
        assert(is_a_balanced_tree());
        // Check postconditions.
        assert(!current_exists());
    }
#endif
}

template <class T>
AVLTree<T>::AVLTree(typename AVLTNode<T>::Ref const &root_node)
{
    // TODO

    root_ = root_node;
    current_ = nullptr;
    parent_ = nullptr;

    //
    assert(!current_exists());
}

template <class T>
void AVLTree<T>::set_left(AVLTree<T> &subtree)
{
    assert(!is_empty());
    // TODO
    // Remember to set parent's link of the subtree root to this.

    root_->set_left(subtree.root_node());
    if(subtree.root_)
        subtree.root_->set_parent(root_);

    //
    assert(subtree.is_empty() || left().item() == subtree.item());
    assert(!subtree.is_empty() || left().is_empty());
}

template <class T>
void AVLTree<T>::set_right(AVLTree<T> &subtree)
{
    assert(!is_empty());
    // TODO
    // Remember to set parent's link of the subtree root to this.

    root_->set_right(subtree.root_node());
    if(subtree.root_)
        subtree.root_->set_parent(root_);

    //
    assert(subtree.is_empty() || right().item() == subtree.item());
    assert(!subtree.is_empty() || right().is_empty());
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::current_node() const
{
    typename AVLTNode<T>::Ref node;
    // TODO

    node = current_;

    //
    return node;
}

template <class T>
void AVLTree<T>::set_current_node(typename AVLTNode<T>::Ref const &new_c)
{
    // TODO

    current_ = new_c;

    //
    assert(current_node() == new_c);
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::root_node() const
{
    typename AVLTNode<T>::Ref node;
    // TODO

    node = root_;

    //
    return node;
}

template <class T>
void AVLTree<T>::set_root_node(typename AVLTNode<T>::Ref const &new_root)
{
    // TODO

    root_ = new_root;

    //
    assert(root_node() == new_root);
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::parent_node() const
{
    typename AVLTNode<T>::Ref node;
    // TODO

    node = parent_;

    //
    return node;
}

template <class T>
void AVLTree<T>::set_parent_node(typename AVLTNode<T>::Ref const &new_p)
{
    // TODO

    parent_ = new_p;

    //
    assert(parent_node() == new_p);
}

template <class T>
void AVLTree<T>::find_inorder_sucessor()
{
    assert(current_exists());
    assert(is_a_binary_search_tree());

#ifndef NDEBUG
    T old_curr = current();
#endif
    // TODO

    parent_ = current_;
    current_ = current_->right(); // Siguiente mayor

    while (current_->left() != nullptr) // Vamos todo lo que podemos a la izq
    {
        parent_ = current_;
        current_ = current_->left();
    }

    //
    assert(current_exists() && current_node()->left() == nullptr);
#ifndef NDEBUG
    assert(current() > old_curr);
#endif
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::rotate(typename AVLTNode<T>::Ref P, int dir)
{
    assert(P != nullptr);
    assert(dir == 0 || dir == 1);
    assert(P->child(1 - dir) != nullptr);
#ifdef __DEBUG__
    if (__DEBUG__ > 1)
        std::clog << "Rotating to " << (dir == 0 ? "left" : "right") << " on key " << P->item() << std::endl;
#endif
    // TODO
    // Remember update links to parents.
    // Hint: you can see wikipedia: https://en.wikipedia.org/wiki/Tree_rotation

    auto G = P->parent();
    auto S = P->child(1 - dir);
    auto C = S->child(dir);

    P->set_child(1-dir,C);
    S->set_child(dir,P);
    P->set_parent(S);

    if (C != nullptr)
    {
        C->set_parent(P);

    }

    if (G != nullptr)
    {
        int gpdir = P == G->child(0) ? 0 : 1;
        G->set_child(gpdir,S);
    }
    else
    {
        set_root_node(S);
    }
    S->set_parent(G);

    //
    return S;
}

template <class T>
void AVLTree<T>::make_balanced()
{
#ifdef __ONLY_BSTREE__
    return;
#else
   typename AVLTNode<T>::Ref P = parent_node(); // the subtree root node.
   typename AVLTNode<T>::Ref S;
    int bfP;
    int bfS;
    int dir;
    while (P != nullptr)
    {
        // TODO
        // Checks the subtrees balance factors to do rotations if needed.
        // Remember: first update the height of the subtree root node.

        P->update_height();
        bfP = P->balance_factor();
        
        if (std::abs(bfP) > 1) // Subtree balanced
        {
            dir = (bfP < 0) ? 0 : 1;
            S = P->child(dir);

            bfS = S->balance_factor();

            if (bfS * bfP >= 0)
            {
                P = rotate(P,1 - dir);
            }
            else
            {
                rotate(S,dir);
                P = rotate(P,1 - dir);
            }
        }
        
        //
        P = P->parent(); // going up.
    }
    if (current_exists())
        set_parent_node(current_node()->parent());
    assert(!current_exists() || current_node()->parent() == parent_node());
#endif //__ONLY_BSTREE__
}

template <class T>
bool AVLTree<T>::check_parent_chains() const
{
    if (!is_empty())
    {
        std::function<void(typename AVLTNode<T>::Ref, std::vector<T>)> go_down;
        go_down = [&go_down](typename AVLTNode<T>::Ref node, std::vector<T> branch) -> void
        {
            if (node->left() != nullptr || node->right() != nullptr)
            {
                branch.push_back(node->item());
                if (node->left())
                    // go down by the left
                    go_down(node->left(), branch);
                if (node->right())
                    // go down by the right
                    go_down(node->right(), branch);
            }
            else
            {
                // The node is a leaf node, so check the branch
                // to the tree root node.
                typename AVLTNode<T>::Ref parent = node->parent();
                int idx = static_cast<int>(branch.size()) - 1;
                while (node->parent() != nullptr && idx >= 0)
                {
                    assert(parent->item() == branch[idx]);
                    --idx;
                    parent = parent->parent();
                }
                assert(idx == -1 && parent == nullptr);
            }
        };
        std::vector<T> branch;
        go_down(root_node(), branch);
    }
    return true;
}
