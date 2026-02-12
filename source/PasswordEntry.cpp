#include "PasswordEntry.hpp"
#include <XorCipher.hpp>
#include <stdexcept>
#include <iostream>

PasswordEntry::PasswordEntry(
    const std::string& service_name, 
    const std::string& login, 
    const std::string& password, 
    const std::string& master_key, 
    const ICipher& cipher
){
    if(service_name.empty())
        throw std::invalid_argument("Service name is empty");
    if(login.empty())
        throw std::invalid_argument("Login is empty");
    if(password.empty())
        throw std::invalid_argument("Password is empty");
    
    this->service_name = service_name;
    this->login = login;
    this->password = cipher.encrypt(password, master_key); 
}

PasswordEntry::PasswordEntry(
    const std::string &service_name, 
    const std::string &login, 
    const std::string &encrypted_password
) {
    if(service_name.empty())
        throw std::invalid_argument("Service name is empty");
    if(login.empty())
        throw std::invalid_argument("Login is empty");
    if(encrypted_password.empty())
        throw std::invalid_argument("Encrypted password is empty");
    
    this->service_name = service_name;
    this->login = login;
    this->password = encrypted_password;
}

void PasswordEntry::display() const{
	std::cout << "Service: "  << service_name << std::endl;
	std::cout << "Login: "    << login        << std::endl;
	std::cout << "Password: " << "********"   << std::endl;    
	std::cout << std::endl;
}

std::string PasswordEntry::getDecryptedPassword(
        const ICipher& cipher, 
        const std::string& master_key
) const{
	std::string result = cipher.decrypt(password, master_key);
	return result;
}


