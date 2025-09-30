class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(3);
        for(int i = 0; i < n; i++) {
            int val = costs[i] + min({dp[0] + 9, dp[1] + 4, dp[2] + 1});
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = val;
        }
        return dp[2];
    }
};