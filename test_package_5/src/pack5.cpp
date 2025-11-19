#include <iostream>

#include <pack5.hpp>
#include <pack1.hpp>
#include <pack2.hpp>
#include <pack4.hpp>

std::string pack5_str() {
    return pack1_str() + pack2_str() + pack4_str() + "pack5";
}
