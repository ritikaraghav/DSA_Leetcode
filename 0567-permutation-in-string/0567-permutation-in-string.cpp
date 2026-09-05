class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char s : s1) {
            mp1[s]++;
        }

        if (s1.size() > s2.size()) {
            return false;
        }

        // First window
        for (int i = 0; i < s1.size(); i++) {
            mp2[s2[i]]++;
        }

        if (mp1 == mp2) {
            return true;
        }

        // Sliding window
        int left = 0;

        for (int right = s1.size(); right < s2.size(); right++) {
            mp2[s2[right]]++;

            mp2[s2[left]]--;

            if (mp2[s2[left]] == 0) {
                mp2.erase(s2[left]);
            }

            left++;

            if (mp1 == mp2) {
                return true;
            }
        }

        return false;
    }
};