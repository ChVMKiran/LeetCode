class Solution {
public:
    long long helper(vector<int>& nums, int ind, int skip, vector<vector<long long>> & dp) {
        if(ind <= 0) return 0;
        if(dp[skip][ind] != -1) return dp[skip][ind];
        long long take = max(0, max(nums[ind - 1], nums[ind + 1]) - nums[ind] + 1);
        take += helper(nums, ind - 2, skip, dp);
        long long notTake = LLONG_MAX;
        if(skip != 1) {
            notTake = helper(nums, ind - 1, 1, dp);
        }
        return dp[skip][ind] = min(take, notTake);
    }
    long long minIncrease(vector<int>& nums) {
        long long val = 0;
        int n = nums.size();
        if(n % 2 == 1) {
            for(int i = 1; i < n - 1; i += 2) {
                if(i % 2) {
                    val += max(0, max(nums[i - 1], nums[i + 1]) - nums[i] + 1);
                }
            }
            return val;
        }
        vector<vector<long long>> dp(2, vector<long long> (n, -1));
        return helper(nums, n - 2, 0, dp);
    }
};