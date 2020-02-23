#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include <chrono>
#include <ctime>
#include "proof.hpp"
#include "utils.hpp"

class Block
{
private:
    int nonce;
    int timestamp;
    std::string data;
    std::string hash;
    std::string prev_block_hash;
public:
    Block(std::string prev_block_hash, std::string data);
    Block();
    // void set_hash();
    std::string get_hash();
    std::string get_data();
    std::string get_prev_block_hash();
    int get_timestamp();
};


inline std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

