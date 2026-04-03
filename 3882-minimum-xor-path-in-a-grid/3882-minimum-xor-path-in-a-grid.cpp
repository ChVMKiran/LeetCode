class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> qu;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>> (n, vector<bool> (1024)));
        dp[0][0][grid[0][0]] = true;
        qu.push({0, 0, grid[0][0]});
        while(!qu.empty()) {
            auto [i, j, val] = qu.front();
            qu.pop();
            if(i < m - 1 && !dp[i + 1][j][val ^ grid[i + 1][j]]) {
                qu.push({i + 1, j, val ^ grid[i + 1][j]});
                dp[i + 1][j][val ^ grid[i + 1][j]] = true;
            }
            if(j < n - 1 && !dp[i][j + 1][val ^ grid[i][j + 1]]) {
                qu.push({i, j + 1, val ^ grid[i][j + 1]});
                dp[i][j + 1][val ^ grid[i][j + 1]] = true;
            }
        }
        for(int i = 0; i < 1024; i++) {
            if(dp[m - 1][n - 1][i]) return i;
        }
        return -1;
    }
};