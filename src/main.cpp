#include <iostream>
#include <string>
#include "palindrome.h"

int main() {
    std::string input;
    std::cout << "Введите строку для проверки на палиндром (или 'exit' для выхода):" << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Выход из программы. До свидания!" << std::endl;
            break;
        }

        if (isPalindrome(input)) {
            std::cout << "\"" << input << "\" является палиндромом." << std::endl;
        } else {
            std::cout << "\"" << input << "\" не является палиндромом." << std::endl;
        }
    }

    return 0;
}
