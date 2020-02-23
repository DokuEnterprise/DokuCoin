#include <saber/blockchain.hpp>
#include <saber/block.hpp>


int main(){
    Blockchain c;

    for(int i = 0; i < 10; i++){
        c.add_block("EAT CHICKEN #" + std::to_string(i));
    }
    
    for(auto b : c.blockchain){
        std::cout << "HASH: " <<  b.get_hash() << std::endl;
        std::cout << "DATA: " << b.get_data() << std::endl;    }
    return 0;
}



