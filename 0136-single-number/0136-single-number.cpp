class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int, int>mp;
        for( int i : nums){
            mp[i]++;
        }
        for(auto pair : mp){
            if(pair.second == 1){
                ans = pair.first;
                break;
             }
        }
        return ans;
    }
};