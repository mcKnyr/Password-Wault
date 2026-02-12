#pragma once

#include <string>

class ICipher{
	public:
	virtual std::string encrypt(const std::string& data, const std::string& key) const = 0;
	virtual std::string decrypt(const std::string& encrypted_data, const std::string& key) const = 0;

	virtual ~ICipher() = default;
};
