class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            int windowsum = 0;

            if (k > 0) {
                // Sum next k elements
                for (int j = 1; j <= k; j++) {
                    windowsum += code[(i + j) % n];
                }
            }
            else {
                // Sum previous |k| elements
                for (int j = 1; j <= -k; j++) {
                    windowsum += code[(i - j + n) % n];
                }
            }

            ans[i] = windowsum;
        }

        return ans;
    }
};