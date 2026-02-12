#pragma once
#include "ICipher.hpp"
#include "PasswordEntry.hpp"
#include <string>
#include <vector>
#include <memory>

class Vault{
private:
    std::unique_ptr<ICipher> cipher;
    std::vector<PasswordEntry> entries;

public:
    Vault(std::unique_ptr<ICipher> cipher);

    void addEntry(
        const std::string& source,
        const std::string& login,
        const std::string& password,
        const std::string& master_key
    );

    const PasswordEntry* findEntry(const std::string& service) const;

    void saveToFile(const std::string& filename) const;
    
};
