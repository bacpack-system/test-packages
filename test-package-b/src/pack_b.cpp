#include <pack_b.hpp>
#include <pack_a.hpp>

std::string pack_b_str() {
    return pack_a_str() + "pack_b";
}
