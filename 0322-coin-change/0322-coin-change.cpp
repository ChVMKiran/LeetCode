class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> ust(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        for(int i = 0; i < n; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                if(dp[j - coins[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};