class Solution {
public:
    int helper(vector<int>& nums, int ind, int target, vector<unordered_map<int, int>>& dp) {
        if(ind == nums.size()) {
            if(target == 0) return 0;
            return -1;
        }
        if(dp[ind].count(target)) return dp[ind][target];
        int take = helper(nums, ind + 1, target ^ nums[ind], dp);
        if(take != -1) take = take + 1;
        int notTake = helper(nums, ind + 1, target, dp);
        return dp[ind][target] = max(take, notTake);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int res = helper(nums, 0, target, dp);
        if(res == -1) return -1;
        return n - res;
    }
};