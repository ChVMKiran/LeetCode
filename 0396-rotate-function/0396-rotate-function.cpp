class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), curr = 0, total = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 1; i < n; i++) curr += i * nums[i];
        int ans = curr;
        for(int i = 0; i < n - 1; i++) {
            curr = curr + total - nums[n - i - 1] * n;
            ans = max(ans, curr);
        }
        return ans;
    }
};