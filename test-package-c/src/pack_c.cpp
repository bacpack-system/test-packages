#include <iostream>

#include <pack_c.hpp>
#include <pack_b.hpp>

std::string pack_c_str() {
    return pack_b_str() + "pack_c";
}
