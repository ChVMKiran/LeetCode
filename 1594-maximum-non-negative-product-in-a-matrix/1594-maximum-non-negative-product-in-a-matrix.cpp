class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();// = 1e9 + 7;
        vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>> (n, pair<long, long> ()));
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 1; i < m; i++) {
            dp[i][0] = {grid[i][0] * dp[i - 1][0].first, grid[i][0] * dp[i - 1][0].first};
            dp[i][0].first;
            dp[i][0].second;
        }
        for(int i = 1; i < n; i++) {
            dp[0][i] = {grid[0][i] * dp[0][i - 1].first, grid[0][i] * dp[0][i - 1].first};
            dp[0][i].first;
            dp[0][i].second;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j].first = grid[i][j] * min({dp[i - 1][j].first, dp[i - 1][j].second, dp[i][j - 1].first, dp[i][j - 1].second});
                dp[i][j].second = grid[i][j] * max({dp[i - 1][j].first, dp[i - 1][j].second, dp[i][j - 1].first, dp[i][j - 1].second});
                dp[i][j].first;
                dp[i][j].second;
            }
        }
        return max(dp[m - 1][n - 1].first, dp[m - 1][n - 1].second) < 0 ? -1 : max(dp[m - 1][n - 1].first, dp[m - 1][n - 1].second) % int(1e9 + 7);
    }
};