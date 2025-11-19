#include <iostream>

#include <pack2.hpp>
#include  <pack1.hpp>

std::string pack2_str() {
    return pack1_str() + "pack2";
}
