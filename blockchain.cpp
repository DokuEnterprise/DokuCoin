#include "blockchain.hpp"


void Blockchain::add_block(std::string data){
    auto prev = blockchain[blockchain.size() -1];
    Block b(prev.get_hash(),data);
    this->blockchain.push_back(b);
}

Blockchain::Blockchain(){
    Block g;
    this->blockchain.push_back(g);
}