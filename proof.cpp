#include "proof.hpp"


Proof::Proof()
{
    this->target = 1;
    this->target << (256-TARGET_BITS);
}

std::string Proof::prepare_data(int nonce){
    std::string result;
    result += this->block.get_prev_block_hash() 
            += this->block.get_data()
            += integer_to_hex(this->block.get_timestamp())
            += integer_to_hex(TARGET_BITS)
            += integer_to_hex(nonce);
    return result;
}

p_data Proof::run(){
    h_type hashint, nonce;
    std::string hash;

    std::cout << "Minning block containing "
             << this->block.get_data()
            << std::endl;
    while(true){
        auto data = this->prepare_data(nonce);
        auto hash = sha256(data);
        std::cout << hash << std::endl;

        hashint = reinterpret_cast<h_type>(hash.c_str());

        if(hashint < this->target){
            break;
        }else{
            nonce++;
        }
    }
    std::cout << std::endl << std::endl;
    p_data p{nonce, hash};
    return p;
}