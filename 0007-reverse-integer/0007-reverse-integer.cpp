#include <string>
#include <algorithm>
#include <climits> 

class Solution {
public:
    int reverse(int x) {
        bool isNegative = (x < 0);
        
        std::string str_num = std::to_string(x);
        
        if (isNegative) {
            std::reverse(str_num.begin() + 1, str_num.end());
        } else {
            std::reverse(str_num.begin(), str_num.end());
        }
        
        long long rev_num = std::stoll(str_num); 
        
        if (rev_num > INT_MAX || rev_num < INT_MIN) {
            return 0;
        }
        
        return static_cast<int>(rev_num);
    }
};
