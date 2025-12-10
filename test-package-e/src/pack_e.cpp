#include <pack_e.hpp>
#include <pack_a.hpp>
#include <pack_b.hpp>
#include <pack_d.hpp>

std::string pack_e_str() {
    return pack_a_str() + pack_b_str() + pack_d_str() + "pack_e";
}
