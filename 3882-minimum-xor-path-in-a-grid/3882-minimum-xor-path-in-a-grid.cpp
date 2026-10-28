class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bitset<1024> dp[n];
        dp[0].set(grid[0][0]);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!i && !j) continue;
                bitset<1024> prev, curr;
                prev |= dp[j];
                if(j > 0) prev |= dp[j - 1];
                for(int k = prev._Find_first(); k < 1024; k = prev._Find_next(k)) {
                    curr.set(k ^ grid[i][j]);
                }
                dp[j] = curr;
            }
        }
        return dp[n - 1]._Find_first();
    }
};