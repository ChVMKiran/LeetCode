class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], currMin = nums[0], currMax = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] < 0) swap(currMin, currMax);
            currMax = max({currMax * nums[i], nums[i]});
            currMin = min({currMin * nums[i], nums[i]});
            ans = max(ans, currMax);
        }
        return ans;
    }
};