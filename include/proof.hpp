#pragma once
#define TARGET_BITS 24


#include "blockchain.hpp"

//TODO: implement proof of stake later
class Proof
{
private:
    /* data */
public:
    Block block;
    int target;
    Proof();
};

