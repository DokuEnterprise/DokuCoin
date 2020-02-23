#include "block.hpp"
#include "proof.hpp"
#include <string.h>
#include <stdio.h>


// void Block::set_hash(){
//     //TODO: make this better later
//     auto t = std::to_string(this->timestamp);
//     hash = sha256(t + data + prev_block_hash);
// }

std::string Block::get_data(){
    return this->data;
}

int Block::get_timestamp(){
    return this->timestamp;
}

std::string Block::get_hash(){
    return this->hash;
}

std::string Block::get_prev_block_hash(){
    return this->prev_block_hash;
}

// Creates a new block
Block::Block(std::string prev_block_hash, std::string data){
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    this->data = data;
    this->timestamp = static_cast<long int>(end_time);
    this->prev_block_hash = prev_block_hash;
    
    auto x = this;
    Proof p(x);

    auto pdata = p.run();
    this->hash = pdata.hash;
    this->nonce = pdata.nonce;
    // this->set_hash();
}

// creates a new genesis block
Block::Block(){
    this->data = "GENESIS";
}