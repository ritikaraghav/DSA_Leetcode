class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int num : nums){
            if(num > max){
                max = num;
            }
            if(num < min){
                min = num;
            }
        }
        return gcd(min,max);
    }
};