#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "palindrome.h"

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
