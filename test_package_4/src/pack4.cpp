#include <iostream>

#include <pack4.hpp>
#include <pack3.hpp>

std::string pack4_str() {
    return pack3_str() + "pack4";
}
