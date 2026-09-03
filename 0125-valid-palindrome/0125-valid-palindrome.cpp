#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isalnum(c); 
        }), s.end());

        // 2. NOW initialize your pointers based on the new size
        int left = 0;
        int right = s.size() - 1;

        // 3. Compare using case-insensitive check
        while (left < right) {
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
