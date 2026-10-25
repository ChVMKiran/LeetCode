class Solution {
public:
    vector<vector<bool>> vis;
    int m, n;
    bool helper(int x, int y, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 2;
        bool flag = true;
        int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = x + dx[i];
                int c = y + dy[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    flag = false;
                } 
                else if (grid[r][c] == 0 && !vis[r][c]) {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.assign(m, vector<bool>(n));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !vis[i][j] && helper(i, j, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};