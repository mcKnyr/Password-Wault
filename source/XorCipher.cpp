#include "XorCipher.hpp"
#include <stdexcept>
#include <sstream>
#include <iomanip>

std::string XorCipher::encrypt(
    const std::string& data, 
    const std::string& key
) const{
    if (key.empty()) 
        throw std::invalid_argument("Key cannot be empty");
    
    std::string result(data.size(), ' ');
    for(size_t i = 0; i < data.size(); i++){
        result[i] = data[i] ^ key[i % key.size()];
    }		
    return result;
}

std::string XorCipher::decrypt(
    const std::string& encrypted_data, 
    const std::string& key
) const{
    if (key.empty()) 
        throw std::invalid_argument("Key cannot be empty");
    
    std::string result(encrypted_data.size(), ' ');
    for(size_t i = 0; i < encrypted_data.size(); i++){
        result[i] = encrypted_data[i] ^ key[i % key.size()];
    }		
    return result;
}	

std::string XorCipher::toHex(const std::string& input){
    std::ostringstream oss;
    for(auto c : input){
        oss <<  std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);  
    }

    return oss.str();
}


std::string XorCipher::fromHex(const std::string& input){
    std::string output;
    for(size_t i = 0; i < input.size(); i += 2){
        std::string byte_string = input.substr(i, 2);
        char byte = static_cast<char>(strtol(byte_string.c_str(), nullptr, 16));
        output.push_back(byte);
    }
    return output;
}
