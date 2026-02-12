#include <memory>
#include <iostream>
#include <string>
#include "XorCipher.hpp"
#include "Vault.hpp"

int main() {
    try {
        std::string master = "top-secret-key";
        
        // Создаем хранилище и отдаем ему XOR шифратор
        auto cipher = std::make_unique<XorCipher>();
        Vault myVault(std::move(cipher));

        // Добавляем записи
        myVault.addEntry("Github", "alex_dev", "p@ss123", master);
        myVault.addEntry("Google", "alex.work", "work_only_55", master);

        std::cout << "--- Password Manager Ready ---" << std::endl;
        
        // Поиск
        std::string query = "Github";
        const PasswordEntry* found = myVault.findEntry(query);

        if (found) {
            std::cout << "Found entry for: " << query << std::endl;
            found->display(); // Покажет звездочки

            // Для расшифровки нам нужен доступ к алгоритму
            XorCipher x; 
            std::cout << "Decrypted password: " 
                      << found->getDecryptedPassword(x, master) << std::endl;
        } else {
            std::cout << "Service " << query << " not found." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Critical Error: " << e.what() << std::endl;
    }

    return 0;
}
