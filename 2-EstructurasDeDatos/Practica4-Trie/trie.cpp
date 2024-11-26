/**
 * @file trie.cpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include <cassert>
#include <sstream>
#include "trie.hpp"

Trie::Trie()
{
    // TODO

    prefix_ = "";
    root_ = nullptr;

    //
    assert(is_empty());
}

Trie::Trie(TrieNode::Ref root_node, std::string const &pref)
{
    // TODO

    prefix_ = pref;
    root_ = root_node;

    //
    assert(prefix() == pref);
}

Trie::Trie(std::istream &in) noexcept(false)
{
    // TODO
    /**
     * @brief Create a Trie unfolding from an input stream.
     * @see fold method to know about the expected grammar.
     * @param in is the input stream.
     * @return a shared reference to the tree created.
     * @throw std::runtime_error("Wrong input format") when wrong input format
     *        is detected.
     */

    // std::string token;
    //     TrieNode::Ref root = nullptr;
    //     std::string pref = "";
    //     char c;

    //     in >> token;

    //     if (token == "[") //Si no empieza por [
    //     {
    //         in >> token;

    //         if (token != "\"")//Si el prefijo no empieza por "
    //         {
    //             throw std::runtime_error("Wrong input format.");
    //         }
        
    //         while (in >> token && token != "\"")
    //         {
    //             if (token == "[")//Si lee "[" es que no hay "
    //             {
    //                 throw std::runtime_error("Wrong input format.");
    //             }

    //             c = char(std::stoi(token,nullptr,16));
    //             pref += c;
    //         }

    //         root = TrieNode::create(in);
    //     }
    //     else if (token != "[]")
    //     {
    //       throw std::runtime_error("Wrong input format.");
    //     }


    //     in >> token;
    //     if (token != "]") //Si no acaba en "]"
    //     {
    //         throw std::runtime_error("Wrong input format.");
    //     }

    //     set_root(root);
    //     set_prefix(pref);
    
    // TODO //[ " 44 56 45 "[ T 44 ]]
        std::string token;
        in>>token;
        if(token != "["){
            throw std::runtime_error("Wrong input format");
        }
        in>>token;
        if(token != "\""){
            throw std::runtime_error("Wrong input format");
        }
        prefix_="";
        while(in>>token && token !="\""){
            try{
            prefix_+=char(std::stoi(token,nullptr,16));
            }catch(std::invalid_argument &x){throw std::runtime_error("Wrong input format");}
        }
        root_=TrieNode::create(in);
        in>>token;
        if(token!="]"){
            throw std::runtime_error("Wrong input format");
        }

    //
}

bool Trie::is_empty() const
{
    bool ret_v = true;
    // TODO

    ret_v = root() == nullptr;

    //
    return ret_v;
}

std::string
Trie::prefix() const
{
    std::string ret_val = "";
    // TODO

    ret_val = prefix_;

    //
    return ret_val;
}

void Trie::set_prefix(const std::string &new_p)
{
    // TODO

    prefix_ = new_p;

    //
    assert(prefix() == new_p);
}

bool Trie::is_key() const
{
    assert(!is_empty());
    bool ret_val = true;
    // TODO

    ret_val = root()->is_key();

    //
    return ret_val;
}

TrieNode::Ref
Trie::root() const
{
    TrieNode::Ref node;
    // TODO

    node = root_;

    //
    return node;
}

void Trie::set_root(TrieNode::Ref const &new_r)
{
    // TODO

    root_ = new_r;

    //
    assert(root() == new_r);
}

bool Trie::has(std::string const &k) const
{
    assert(!is_empty());
    bool found = false;
    // TODO
    // Hint: use find_node() to do this.
    // Remember: The Trie can have a prefix==k but does not store the key k.

    TrieNode::Ref node = find_node(prefix()+k); //Por si se ejecuta la función en un nodo intermedio, y le paso los valores del prefijo que faltan por encontrar
                                                //Si quiero buscar un string completo busco desde el nodo raiz que el prefix es una cadena vacía
    found = (node != nullptr) && (node->is_key());

    //
    return found;
}

/**
 * @brief Helper function to retrieve the keys.
 *
 * This function does a recursive preorder traversal of the trie's nodes
 * keeping the current prefix and the retrieved keys as functions parameters.
 *
 * @param[in] node is the current node.
 * @param[in] prefix is the current prefix.
 * @param[in,out] keys are theis_key retrieved keys.
 */
static void
preorder_traversal(TrieNode::Ref node, std::string prefix,
                   std::vector<std::string> &keys)
{
    // TODO
    // Remember: node->is_key() means the prefix is a key too.

    if (node->is_key())
        keys.push_back(prefix);
    node->goto_first_child();

    while (node->current_exists())
    {
        preorder_traversal(node->current_node(),prefix + node->current_symbol(),keys);
        node->goto_next_child();
    }

    //
}

void Trie::retrieve(std::vector<std::string> &keys) const
{
    assert(!is_empty());
    // TODO
    // Remember add the subtrie's prefix to the retrieve keys.

    preorder_traversal(root(),prefix(),keys);

    //
}

Trie Trie::child(std::string const &postfix) const
{
    assert(!is_empty());
    Trie ret_v;
    // TODO
    // Hint: use find_node() to follow the chain of nodes whose represent postfix.
    /**
     * @brief Gets the subtrie for the prefix prefix()+postfix
     * @param postfix is the prefix()+postfix represented by the subtrie to be found.
     * @return the subtrie storing the keys with prefix prefix()+postfix
     * @pre !is_empty()
     * @post ret_v.is_empty() || ret_v.prefix()==prefix()+postfix
     */
    //Necisito Explicación      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    TrieNode::Ref node = root();

    for (char c : postfix)
    {
        if (!node->find_child(c)){
            return ret_v;
        }
        node = node->child(c);
    }
    ret_v.set_root(node);
    ret_v.set_prefix(prefix() + postfix);

    //
    assert(ret_v.is_empty() || ret_v.prefix() == (prefix() + postfix));
    return ret_v;
}

bool Trie::current_exists() const
{
    assert(!is_empty());
    bool ret_val = false;
    // TODO

    ret_val = root()->current_exists();

    //
    return ret_val;
}

Trie Trie::current() const
{
    assert(current_exists());
    Trie ret_v;
    // TODO

    ret_v.set_root(root());
    ret_v.set_prefix(prefix() + current_symbol());

    //
    return ret_v;
}

char Trie::current_symbol() const
{
    assert(current_exists());
    char symbol = 0;
    // TODO

    symbol = root()->current_symbol();

    //
    return symbol;
}

void Trie::insert(std::string const &k)
{
    assert(k != "");
    // TODO

    TrieNode::Ref node;
    TrieNode::Ref new_node;

    if (root() == nullptr)
    {
        root_ = TrieNode::create(false);
    }

    node = root();

    for (size_t i = 0; i < k.size(); i++)
    {
        auto c = k[i];
        if (node->has(c))
        {
            node = node->child(k[i]);
        }
        else
        {
            new_node = TrieNode::create(false);
            node->set_child(k[i],new_node);
            node = new_node;
        }
    }

    node->set_is_key_state(true);

    //
    assert(!is_empty());
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const &pref) const
{
    assert(!is_empty());
    TrieNode::Ref node;
    // TODO
    // Remember: the prefix "" must return the trie's root node.

    node = root();
    size_t i = 0;

    while (i < pref.size() && node != nullptr)
    {
        if (node->has(pref[i])) //Compruebo si el caracter pref[i] se encuentra entre los hijos del node
        {
            node = node->child(pref[i]);    //Actualizo el valor de node
            i++;
        }
        else
        {
            node = nullptr;
        }
    }

    //
    return node;
}

std::ostream &
Trie::fold(std::ostream &out) const
{
    // TODO                                       ------------------------ NO FUNCIONA ---------------------------------

    out <<"[ \" ";
    for (auto c: prefix())
    {
        out<< std::hex << (uint16_t)c << " ";
    }
    out <<"\" ";

    root()->fold(out);
    //Para iterativo necesito un bucle que recorra el trie

    out <<" ]";

    //
    return out;
}

bool Trie::find_symbol(char symbol)
{
    assert(!is_empty());
    bool found = false;
    // TODO
    /**
     * @brief Move current to the subtree representing the prefix prefix()+symbol
     * @param symbol is the next symbol to be found.
     * @return true if a child was found.
     * @pre !is_empty()
     * @post !ret_v || currentExists()
     * @post ret_v || !currentExists()
     * @post !currentExists() || current().prefix() == (prefix()+symbol)
     */

    found = root()->find_child(symbol);

    //
    assert(!found || current_exists());
    assert(found || !current_exists());
    assert(!current_exists() || current_symbol() == symbol);
    return found;
}

void Trie::goto_first_symbol()
{
    assert(!is_empty());
    // TODO

    root()->goto_first_child();

    //
    assert(!current_exists() ||
           current().prefix() == (prefix() + current_symbol()));
}

void Trie::goto_next_symbol()
{
    assert(current_exists());
    // TODO

    root()->goto_next_child();

    //
}
