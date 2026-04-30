class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int limit) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (limit + 1, -1));
        dp[0][0] = 0;
        for(int i = 0; i < m; i++) {
            vector<vector<int>> ndp(n, vector<int> (limit + 1, -1));
            for(int j = 0; j < n; j++) {
                for(int k = 0; k <= limit; k++) {
                    if(dp[j][k] == -1) continue;
                    if(i + 1 < m) {
                        int cost = (grid[i + 1][j] != 0);
                        // printf("%d %d %d %d\n", i, j, k, cost);
                        if(k + cost <= limit) {
                            ndp[j][k + cost] = max(ndp[j][k + cost], dp[j][k] + grid[i + 1][j]);
                            // printf("i + 1: %d\n", ndp[j][k + cost]);
                        }
                    }
                    if(j + 1 < n) {
                        int cost = (grid[i][j + 1] != 0);
                        // printf("%d %d %d %d\n", i, j, k, cost);
                        if(k + cost <= limit) {
                            dp[j + 1][k + cost] = max(dp[j + 1][k + cost], dp[j][k] + grid[i][j + 1]);
                            // printf("j + 1: %d\n", dp[j + 1][k + cost]);
                        }
                    }
                }
            }
            if(i == m - 1) return *max_element(dp[n - 1].begin(), dp[n - 1].end());
            dp = ndp;
        }
        return -1;
    }
};