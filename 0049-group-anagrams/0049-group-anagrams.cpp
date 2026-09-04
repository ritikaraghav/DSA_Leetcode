class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str : strs){
            vector<int> count(26,0);
            for(int i : str){
                count[i - 'a']++;
            }

            string key;
            for(auto k : count){
                key += to_string(k)+"#";
            }

            mp[key].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};