#include "palindrome.h"
#include <algorithm>
#include <cctype>

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
