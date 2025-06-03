#include <string>
#include <climits>

class Solution {
public:
    /**
     * Converts string to 32-bit signed integer with overflow handling
     * Time: O(n), Space: O(1)
     * Optimized for minimal memory usage and fast execution
     */
    int myAtoi(const std::string& s) {
        if (s.empty()) return 0;
        
        const char* str = s.c_str();
        const char* end = str + s.length();
        
        // Skip leading whitespace
        while (str < end && *str == ' ') ++str;
        if (str == end) return 0;
        
        // Handle sign
        bool negative = false;
        if (*str == '-') {
            negative = true;
            ++str;
        } else if (*str == '+') {
            ++str;
        }
        
        // Convert digits with overflow protection
        long long result = 0;
        constexpr long long MAX_DIV_10 = INT_MAX / 10;
        constexpr int MAX_MOD_10 = INT_MAX % 10;
        constexpr long long MIN_DIV_10 = static_cast<long long>(INT_MIN) / 10;
        constexpr int MIN_MOD_10 = static_cast<long long>(INT_MIN) % 10;
        
        while (str < end && *str >= '0' && *str <= '9') {
            int digit = *str - '0';
            
            if (negative) {
                // Check for underflow before multiplication
                if (result < MIN_DIV_10 || (result == MIN_DIV_10 && digit > -MIN_MOD_10)) {
                    return INT_MIN;
                }
                result = result * 10 - digit;
            } else {
                // Check for overflow before multiplication
                if (result > MAX_DIV_10 || (result == MAX_DIV_10 && digit > MAX_MOD_10)) {
                    return INT_MAX;
                }
                result = result * 10 + digit;
            }
            ++str;
        }
        
        return static_cast<int>(result);
    }
};
