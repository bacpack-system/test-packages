#include <iostream>

#include <pack3.hpp>
#include <pack2.hpp>

std::string pack3_str() {
    return pack2_str() + "pack3";
}
