cmake_minimum_required(VERSION 3.10)
project(PasswordManager)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Говорим, где искать заголовочные файлы (.hpp)
include_directories(include)

# Собираем список всех исходников
set(SOURCES 
    source/Vault.cpp 
    source/PasswordEntry.cpp 
    source/XorCipher.cpp 
    source/main.cpp
)


# Создаем исполняемый файл
add_executable(pass_manager ${SOURCES})
