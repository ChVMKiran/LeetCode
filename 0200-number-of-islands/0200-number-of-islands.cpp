class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> qu;
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> rowdirs = {-1, 0, 1, 0}, coldirs = {0, -1, 0, 1};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    qu.push({i, j});
                    while(!qu.empty()) {
                        auto [row, col] = qu.front();
                        qu.pop();
                        grid[row][col] = '2';
                        for(int k = 0; k < 4; k++) {
                            int nrow = row + rowdirs[k], ncol = col + coldirs[k];
                            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                            && grid[nrow][ncol] == '1') {
                                qu.push({nrow, ncol});
                                grid[nrow][ncol] = '2';
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};