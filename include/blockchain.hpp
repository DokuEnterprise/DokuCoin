#pragma once

#include "block.hpp"
#include <vector>

class Blockchain
{
private:
    std::vector<Block> blockchain;
public:
    void add_block(std::string data);
    Blockchain();
};
