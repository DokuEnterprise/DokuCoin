#pragma once
#define TARGET_BITS 24

#include "block.hpp"
#include "blockchain.hpp"

struct p_data{
    int nonce;
    std::string hash;
};
typedef struct p_data p_data;
typedef unsigned long long h_type;

//TODO: implement proof of stake later
class Proof
{
private:
    /* data */
public:
    Block block;
    int target;
    p_data run();
    Proof();
    std::string prepare_data(int nonce);
};

