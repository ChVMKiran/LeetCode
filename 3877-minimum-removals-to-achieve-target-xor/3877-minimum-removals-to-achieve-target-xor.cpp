class Solution {
public:
    int dp[41][40002];
    int helper(int ind, int tar, int n, vector<int>& nums) {
        if (ind == n) {
            if (tar == 0)
                return 0;
            return -1e6;
        }
        if (dp[ind][tar] != -1) {
            return dp[ind][tar];
        }
        int mx = -1e6;
        mx = max(mx, 1 + helper(ind + 1, tar ^ nums[ind], n, nums));
        mx = max(mx, helper(ind + 1, tar, n, nums));
        return dp[ind][tar] = mx;
    }

    int minRemovals(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int res = helper(0, target, nums.size(), nums);
        if (res < 0)
            return -1;
        return nums.size() - res;
    }
};