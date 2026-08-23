class Solution {
public:
    bool isPalindrome(int x) {
        string str_num = to_string(x);
        reverse(str_num.begin(), str_num.end());
        long long rev_num = stoll(str_num); 
        if(rev_num == x)return true;
        else return false;
    }
};