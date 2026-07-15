class Solution {
public:
    int ele(int start, int end, int target, vector<int>& nums) {
        if (start > end)
            return -1;

        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[start] <= nums[mid]) {
            if (target >= nums[start] && target < nums[mid])
                return ele(start, mid - 1, target, nums);
            else
                return ele(mid + 1, end, target, nums);
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[end])
                return ele(mid + 1, end, target, nums);
            else
                return ele(start, mid - 1, target, nums);
        }
    }

    int search(vector<int>& nums, int target) {
        return ele(0, nums.size() - 1, target, nums);
    }
};