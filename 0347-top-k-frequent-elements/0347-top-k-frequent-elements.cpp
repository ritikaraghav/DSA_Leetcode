class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](const auto &a , const auto &b){
            return a.second > b.second; 
        });

        vector<int>ans;
        int i = 0;
        while(i < k){
            ans.push_back(vec[i].first);
            i++;
        }
        return ans;
    }
};