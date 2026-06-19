#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //using brute force
        /*for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};*/
        
        //using substraction method 
        /*for(int i = 0; i < nums.size(); i++) {
            
            int s = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                
                if(nums[j] == s) {
                    return {i, j};
                }
            }
        }
        
        return {};*/


        //using hash map
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++){
           int s = target - nums[i];
           if(mp.find(s) != mp.end())return {mp[s],i};
           else mp[nums[i]] = i;

        }
        return {};
    }
};