#pragma once

#include "ICipher.hpp"

class XorCipher : public ICipher{
	public:
	std::string encrypt(const std::string& data, const std::string& key) const override;
	std::string decrypt(const std::string& encrypted_data, const std::string& key) const override; 
    std::string toHex(const std::string& input);
    std::string fromHex(const std::string& input);
};
