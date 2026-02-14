#include <memory>
#include <iostream>
#include <string>
#include "XorCipher.hpp"
#include "Vault.hpp"

std::string master = "top-secret-key";

void saveTest() {
    auto cipher = std::make_unique<XorCipher>();
    Vault vault(std::move(cipher));

    vault.addEntry("Github", "alex_dev", "p@ss123", master);
    vault.addEntry("Google", "alex.work", "work_only_55", master);
    vault.addEntry("Facebook", "alex.fb", "fb_pass_2024", master);

    vault.saveToFile("data.db");
}

void loadTest() {
    auto cipher = std::make_unique<XorCipher>();
    Vault vault(std::move(cipher));

    vault.loadFromFile("data.db");

    std::string query = "Google";
    const PasswordEntry* found = vault.findEntry(query);

    if (found) {
        std::cout << "Found entry for: " << query << std::endl;
        found->display(); // Покажет звездочки

        XorCipher x; 
        std::cout << "Decrypted password: " 
                  << found->getDecryptedPassword(x, master) << std::endl;
    } else {
        std::cout << "Service " << query << " not found." << std::endl;
    }
}

int main() {
    char c; std::cin >> c;
    if(c == 's') {
        saveTest();
    } else if(c == 'l') {
        loadTest();
    } else {
        std::cout << "Invalid option. Use 's' for save test or 'l' for load test." << std::endl;
    }
    
    
    return 0;
}
