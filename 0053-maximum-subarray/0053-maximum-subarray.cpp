class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0 , m = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            s += nums[i]; 
            if(s > m){
                m = s;
            }
            if(s < 0)
                s = 0;
        
        }
        return m;
    }
};