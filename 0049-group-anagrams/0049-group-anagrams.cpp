class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string str : strs) {
            int counts[26] = {0};
            for(char ch : str) {
                counts[ch - 'a']++;
            }

            string key = "";
            for(int i = 0; i < 26; i++) {
                key += to_string(counts[i]) + "#";
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};