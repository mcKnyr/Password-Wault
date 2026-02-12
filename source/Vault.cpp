#include "Vault.hpp"
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>

Vault::Vault(std::unique_ptr<ICipher> cipher){
    if (cipher == nullptr) 
        throw std::invalid_argument("Cipher can't be nullptr");

    this->cipher = std::move(cipher);
}


void Vault::addEntry(
    const std::string& source,
    const std::string& login,
    const std::string& password,
    const std::string& master_key
) {
    entries.emplace_back(source, login, password, master_key, *this->cipher);
}


const PasswordEntry* Vault::findEntry(const std::string& service) const {
    auto it = std::find_if(entries.begin(), entries.end(),
    [&service](const PasswordEntry& e){
        return e.getService() == service;
    });

    if(it != entries.end()){
        return &(*it);
    }

    return nullptr;
}

void Vault::saveToFile(const std::string& filename) const{
    std::ofstream file(filename);
    if (!file.is_open()) 
        throw std::runtime_error("Could not open file for writing");

    //mini costil must be changed when new cipher be added
    auto xor_ptr = dynamic_cast<XorCipher*>(cipher.get());

    for(const auto& entry : entries){
        std::string safe_pass = xor_ptr ? 
            xor_ptr->toHex(entry.getEncryptedPassword()) : 
            entry.getEncryptedPassword();

        file << entry.getService() << "|" 
             << entry.getLogin() << "|" 
             << safe_pass << "\n"; 
    }

    file.close();
}
