class Solution {
public:
    int m, n;
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;
        if (grid[r][c] == 1)
            return true;
        grid[r][c] = 1;
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0 && dfs(r, c, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};