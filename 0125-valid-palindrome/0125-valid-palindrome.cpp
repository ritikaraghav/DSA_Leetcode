class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char x) {
        return !std::isalnum(x);}), s.end());

        int left = 0;
        int right = s.size()-1;

        while(left <= right){
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};