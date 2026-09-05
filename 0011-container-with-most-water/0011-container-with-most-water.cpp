class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int cap = 0;
        int w, h;

        while(i < j){
            h = min(height[i], height[j]);
            w = j - i;
            cap = max(cap , h*w);

            if(height[i] <= height[j]){
                i++;
            }
            else j--;
        }
        return cap;
    }
};