#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>
#include <algorithm>
#include <cctype>

// Функция для проверки, является ли строка палиндромом
bool isPalindrome(const std::string& str) {
    std::string filtered;
    for (char ch : str) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            filtered += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    std::string reversed = filtered;
    std::reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}

// Тесты
TEST_CASE("Проверка палиндромов", "[isPalindrome]") {
    SECTION("Положительные тесты") {
        REQUIRE(isPalindrome("madam") == true);
        REQUIRE(isPalindrome("Racecar") == true);
        REQUIRE(isPalindrome("A man, a plan, a canal, Panama") == true);
        REQUIRE(isPalindrome("Able was I, I saw Elba") == true);
        REQUIRE(isPalindrome("No 'x' in Nixon") == true);
    }

    SECTION("Отрицательные тесты") {
        REQUIRE(isPalindrome("hello") == false);
        REQUIRE(isPalindrome("world") == false);
        REQUIRE(isPalindrome("This is not a palindrome") == false);
        REQUIRE(isPalindrome("12345") == false);
    }

    SECTION("Граничные случаи") {
        REQUIRE(isPalindrome("") == true); // Пустая строка считается палиндромом
        REQUIRE(isPalindrome("a") == true); // Один символ
        REQUIRE(isPalindrome("aa") == true); // Два одинаковых символа
        REQUIRE(isPalindrome("ab") == false); // Два разных символа
    }
}
