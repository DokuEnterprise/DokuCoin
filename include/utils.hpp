#pragma once

#include <string>
#include <iostream>
#include <sstream>

inline std::string integer_to_hex(int num){
    std::stringstream stream;
    stream << std::hex << num;
    std::string result( stream.str() );
    return result;
}