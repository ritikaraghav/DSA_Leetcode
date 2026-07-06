class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        
        // Fix 1: Custom sort to put larger intervals first when start points match
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Descending by end point
            }
            return a[0] < b[0];     // Ascending by start point
        });
        
        // Fix 2: Use an index to track the current "dominant" uncovering interval
        int current = 0; 
        
        for (int i = 1; i < n; i++) {
            int a = intervals[current][0];
            int b = intervals[current][1];
            int c = intervals[i][0];
            int d = intervals[i][1];
            
            // Fix 3: Since we sorted, 'c' is always >= 'a'. 
            // If the next interval's end 'd' fits inside 'b', it is covered!
            if (c >= a && d <= b) {
                count++;
            } else {
                // If it's not covered, this new interval becomes the dominant one to check against next
                current = i; 
            }
        }
        
        return n - count;
    }
};
