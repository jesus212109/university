/**
 * @file ip_utils.cpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include "ip_utils.hpp"
#include <sstream>
#include <string>
#include <algorithm>

//Las IP están reprentadas con 4 valores separados con puntos "192.168.10.30", por ello valores a,b,c,d 

IP::IP() : bytes({0, 0, 0, 0})
{
}
IP::IP(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d)
    : bytes({a, b, c, d})
{
}

bool IP::operator==(IP const &b) const
{
    return bytes == b.bytes;
}

bool IP::operator<(IP const &b) const
{
    return bytes < b.bytes;
}

std::ostream &
operator<<(std::ostream &out, const IP &ip)
{
    // TODO
    // Remember: we want to output the ascii code, not the char.

    out << static_cast<int>(ip.bytes[0]) << '.' <<
              static_cast<int>(ip.bytes[1]) << '.' <<
              static_cast<int>(ip.bytes[2]) << '.' <<
              static_cast<int>(ip.bytes[3]);

    //
    return out;
}

std::istream &
operator>>(std::istream &in, IP &ip) noexcept(false)
{
    // TODO
    // Hint: you can use a std::istringstream to convert from text to uint8_t.
    // Hint: you can use the std::replace algorithm to replace '.' by ' '.
    // Remember: if a wrong format is detected, throw an runtime_error exception.

    std::string direction;
        in>>direction;

        if(in){
            for(size_t i=0;i<direction.size();i++){
                if(direction[i]=='.'){
                    direction[i]=' ';
                }
            }
            std::istringstream in_(direction);
            int vector[4];
            in_ >> vector[0] >> vector[1] >> vector[2] >> vector[3];
            if(in_){
                for(int i=0;i<4;i++){
                    if(vector[i]<0 || vector[i]>255)
                        throw std::runtime_error("Invalid IP");
                    else
                        ip.bytes[i] = static_cast<uint8_t>(vector[i]);
                }
            }
            else
                throw std::runtime_error("Ip: wrong input format.");
        }
        else
        throw std::runtime_error("Ip: wrong input format.");

    //
    return in;
}

std::uint64_t
ip_to_int(const IP &ip)
{
    std::uint64_t ret_val = 0l;
    // Remember: casting to 64 bits unsigned integer to do not loss bits.
    // Hint: mult by 2^n means shift to left n bits.
    ret_val = (static_cast<std::uint64_t>(ip.bytes[0]) << 24) +
              (static_cast<std::uint64_t>(ip.bytes[1]) << 16) +
              (static_cast<std::uint64_t>(ip.bytes[2]) << 8) +
              (static_cast<std::uint64_t>(ip.bytes[3]));
    //
    return ret_val;
}
