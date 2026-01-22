class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            int firstUnSet = ~nums[i] & (nums[i] + 1);
            firstUnSet >>= 1;
            ans[i] = nums[i] - firstUnSet;
        }
        return ans;
    }
};