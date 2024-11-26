/**
 * @file trie_node.cpp
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
#include <cstdint>

#include "trie_node.hpp"

TrieNode::TrieNode (bool is_key_state)
{
    //TODO
    /**
     * @brief Constructor.
     * @param is_key is true when the node represents a key.
     * @post is_key() == is_key_state
     * @post !current_exists()
     */

    isKey_ = is_key_state;
    curr_ = dict_.end();

    //
    assert(is_key()==is_key_state);
    assert(!current_exists());
};

TrieNode::Ref TrieNode::create(bool is_key_state)
{
    return std::make_shared<TrieNode>(is_key_state);
}

TrieNode::~TrieNode()
{}

bool TrieNode::is_key() const
{
    bool ret_val = true;
    //TODO
    /* @brief Does the node represent a key value?
       @return true if this node represents a key value.*/

    ret_val = isKey_;

    //
    return ret_val;
}

bool
TrieNode::has(char k) const
{
    bool ret_v = false;
    //TODO
    //Has it the node a child for the symbol k?

    ret_v = dict_.find(k) != dict_.end();

    //
    return ret_v;
}

TrieNode::Ref
TrieNode::child(char k) const
{
    assert(has(k));
    TrieNode::Ref node = nullptr;
    //TODO
    /**
     * @brief The child for the symbol k?
     * @return a reference to the node.
     * @pre has(k)
     */

    if( has(k) )
        node = dict_.at(k); //dict_.at(k) acede al contenido del mapa por su key(tipo char), y el contenido es un REF
        //dict_[k] no compila asi que se usa dict_.at(k)
    //
    return node;
}

bool
TrieNode::current_exists() const
{
    bool ret_val = true;
    //TODO
    /**
     * @brief Does current exist?
     * @return true if current is valid.
     */

    ret_val = curr_ != dict_.end();
    //dict_.end() señala al siguiente al del elemnto final por tanto no referencia a ninguno(NINGÚN ELEMENTO VÁLIDO(existan valores o no))

    //
    return ret_val;
}

TrieNode::Ref
TrieNode::current_node() const
{
    assert(current_exists());
    TrieNode::Ref node = nullptr;
    //TODO
    /**
     * @brief Get the current child's node.
     * @return a reference to the current child node.
     * @pre current_exist()
     */

    node = curr_->second;

    //
    return node;
}

char
TrieNode::current_symbol() const
{
    assert(current_exists());
    char symbol = 0;
    //TODO
    /**
     * @brief Get the current child's symbol.
     * @return the current next symbol.
     * @pre current_exist()
     */

    symbol = curr_->first;

    //
    return symbol;
}

void
TrieNode::set_is_key_state(bool new_state)
{
    //TODO
    /**
     * @brief Mark this node as a node representing (or not) a key.
     * @post is_key() == new_state
     */

    isKey_ = new_state;

    //
    assert(is_key()==new_state);
}

bool
TrieNode::find_child(char s)
{
    bool found = false;
    //TODO
    /**
     * @brief Move current to the child associated with a symbol.
     * @return true if a child was found.
     * @post ret_val || !current_exists()
     * @post !ret_val || current_symbol()==s
     */

    //dict_.find(s) devuelve si lo encuentra el interador a dicho elemento
    curr_ = dict_.find(s);
    found = curr_ != dict_.end();

    //
    assert(found || !current_exists());
    assert(!found || current_symbol()==s);
    return found;
}

void
TrieNode::goto_first_child()
{
    //TODO

    if( dict_.begin() != dict_.end() )
        curr_ = dict_.begin();

    //
}

void
TrieNode::goto_next_child()
{
    assert(current_exists());
    //TODO

    if( dict_.begin() != dict_.end() )
        curr_++;

    //
}

void
TrieNode::set_child(char k, Ref node)
{
    assert(node != nullptr);
    //TODO
    /**
     * @brief Set a child node for a given symbol.
     * If none previous child was associated with the given symbol, a new child
     *    is create.
     * if a previous child existed for the given symbol, the child node is updated.
     * @arg[in] s is the symbol.
     * @arg[in] node is the new child node.
     * @pre node != nullptr
     * @post current_symbol()==k
     * @post current_node()==node
     */

//    if( has(k) )          //No es necesario este if
//        dict_[k] = node; //para asignar valor si podemos usar corchetes
//    else
//        dict_.insert(std::pair<char,Ref>(k, node));
//    curr_ = dict_.find(k);

    dict_[k] = node; //si no existe se crea en dict y si existe se atualiza el valor
    curr_ = dict_.find(k);


    //
    assert(current_symbol()==k);
    assert(current_node()==node);
}

std::ostream&
TrieNode::fold(std::ostream& out) const
{
    //TODO
    //Hint: review c++ input/output manipulators at
    //      https://en.cppreference.com/w/cpp/io/manip
    /**
     * @brief Fold the node and childs.
     * Format:
     * node: '[' <is_key_state> {<symbol> <node>}* ']'
     * Where:
     * <is_key_state>: 'T'|'F'
     * <symbol>: ASCII code of the symbol coded as a hexadecimal 16 bits unsigned --> OJO hay que hacer conversión con función hex, "std::hex"
     *           int value.
     * @param out is the output stream.
     * @return the modified stream.
     */

    //No recursivo
//        if(dict_.begin() == dict_.end() ){
//            out << "[]";
//        }
//        else{
//            out<<"[ ";
//            if( is_key() )
//                out<<"T";
//            else
//                out<<"F";

//        for( auto i : dict_ ){
//            out<<" ";
//            out<<std::hex << static_cast<uint16_t>(i.first);
//            out<<" ";
//            if( i.second->is_key() ){
//                out<<"[ T ]";
//            }
//            else{
//                out<<"[ F ]";
//            }
//        }
//        out<<" ]";
//     }

    //Recursivo
    out << "[";
    (is_key()) ? out << " T" : out << " F";

    for (auto it = dict_.begin(); it != dict_.end(); it++)
    {
        out << " " << std::hex << (uint16_t)it->first << " ";
        it->second->fold(out);
    }
    out << " ]";

    //
    return out;
}

TrieNode::Ref TrieNode::create(std::istream &in) noexcept(false)
{
    TrieNode::Ref node = nullptr;
    // TODO
    /**
     * @brief Create a TrieNode unfolding from an input stream.
     * @see fold() for the expected input format.
     * @param in is the input stream.
     * @return a shared reference to the node created.
     * @throw std::runtime_error("Wrong input format") when wrong input format
     *        is detected.
     *
     * converir a decimal y luego a char
     * con static_cast<char>(loQueToque)
     *
     *  * node: '[' <is_key_state> {<symbol> <node>}* ']'
     */


    std::string token;
    bool is_key;
    in >> token;

    
    if (token != "[")
    {
        throw std::runtime_error("Wrong input format");
    }

    in >> token;
    if (token == "T")
        is_key = true;
    else if (token == "F")
        is_key = false;
    else
        throw std::runtime_error("Wrong input format");

    node = TrieNode::create(is_key);
try{
    while (in >> token && token != "]")
    {
        node->set_child(char(std::stoi(token, nullptr, 16)),TrieNode::create(in));
    }

    if (token != "]")
        throw std::runtime_error("Wrong input format");
}catch(std::invalid_argument &x){throw std::runtime_error("Wrong input format");}
    //
    return node;
}
