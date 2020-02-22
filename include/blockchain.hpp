#pragma once

#include "block.hpp"
#include <vector>

class Blockchain
{
private:
public:
    std::vector<Block> blockchain;
    void add_block(std::string data);
    Blockchain();
};
