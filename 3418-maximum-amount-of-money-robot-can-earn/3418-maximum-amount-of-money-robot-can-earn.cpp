class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (3, INT_MIN)));
        dp[0][0][0] = coins[0][0];
        for(int i = 1; i < 3; i++) dp[0][0][i] = max(0, coins[0][0]);
        for(int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            for(int j = 1; j < 3; j++) {
                dp[i][0][j] = max(dp[i - 1][0][j - 1], dp[i - 1][0][j] + coins[i][0]);
            }
        }
        for(int i = 1; i < n; i++) {
            dp[0][i][0] = dp[0][i - 1][0] + coins[0][i];
            for(int j = 1; j < 3; j++) {
                dp[0][i][j] = max(dp[0][i - 1][j - 1], dp[0][i - 1][j] + coins[0][i]);
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                for(int k = 1; k < 3; k++) {
                    dp[i][j][k] = max(
                        max(dp[i - 1][j][k - 1], dp[i - 1][j][k] + coins[i][j]),
                        max(dp[i][j - 1][k - 1], dp[i][j - 1][k] + coins[i][j])
                    );
                }
            }
        }
        return dp[m - 1][n - 1][2];
    }
};