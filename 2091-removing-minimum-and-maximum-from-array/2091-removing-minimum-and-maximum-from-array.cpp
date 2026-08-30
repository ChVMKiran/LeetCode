class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mini = 0, maxi = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[mini]) mini = i;
            else if(nums[i] > nums[maxi]) maxi = i;
        }
        int l = min(mini, maxi);
        int r = max(mini, maxi);
        return min({l + 1 + n - r, r + 1, n - l});
    }
};