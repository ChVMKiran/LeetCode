class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, ans = nums[0];
        while(l <= h) {
            int m = l + (h - l) / 2;
            ans = min(ans, nums[m]);
            if(nums[l] < nums[m]) {
                ans = min(ans, nums[l]);
                l = m + 1;
            }
            else if(nums[l] == nums[m]) l++;
            else if(nums[m] == nums[h]) h--;
            else {
                ans = min(ans, nums[m]);
                h = m - 1;
            }
        }
        return ans;
    }
};