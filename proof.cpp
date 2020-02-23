#include "proof.hpp"
#include <stdio.h>
#include <string.h>


Proof::Proof(Block* b)
{
    this->target = 1;
    this->target << (256-TARGET_BITS);
    this->block = b;
}

std::string Proof::prepare_data(int nonce){
    std::string result;
    result += this->block->get_prev_block_hash() 
            += this->block->get_data()
            += integer_to_hex(this->block->get_timestamp())
            += integer_to_hex(TARGET_BITS)
            += integer_to_hex(nonce);
    return result;
}

p_data Proof::run(){
    h_type hashint, nonce = 0;
    std::string hash;

    std::cout << "Minning block containing "
             << this->block->get_data();
    while(nonce < INT64_MAX){
        auto data = this->prepare_data(nonce);
        auto hash = sha256(data);
        std::cout << hash << std::endl;

        memcpy(&hashint, hash.c_str(), strlen(hash.c_str()));

        if(hashint < this->target){
            break;
        }else{
            nonce++;
        }
    }
        std::cout << "HASH :" << hash << std::endl;

    std::cout << std::endl << std::endl;
    p_data p{nonce, hash};
    return p;
}