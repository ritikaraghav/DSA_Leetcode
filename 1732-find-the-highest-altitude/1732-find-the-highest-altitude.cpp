class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i<gain.size() ;i++){
            
                if(sum + gain[i] > maxi)maxi = sum+gain[i];
                    
                sum = sum+gain[i];
        }
        return maxi;
    }
};