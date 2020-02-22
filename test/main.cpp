#include <saber/blockchain.hpp>

int main(){
    Blockchain c;

    for(int i = 0; i < 10; i++){
        c.add_block("EAT CHICKEN #" + std::to_string(i));
    }
    
    for(auto b : c.blockchain){
        std::cout << b.get_hash() << std::endl;
        std::cout << b.get_data() << std::endl;
  
    }
    return 0;
}



