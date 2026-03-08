class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> copy = grid;
        queue<pair<int, int>> qu;
        int m = grid.size(), n = grid[0].size(), fresh = 0, ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) qu.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        if(!fresh) return 0;
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        while(!qu.empty()) {
            int len = qu.size();
            while(len--) {
                auto [i, j] = qu.front();
                qu.pop();
                for(const auto &[dx, dy]: dirs) {
                    int nx = dx + i, ny = dy + j;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && copy[nx][ny] == 1) {
                        copy[nx][ny] = 2;
                        fresh--;
                        qu.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        if(fresh) return -1;
        return ans - 1;
    }
};