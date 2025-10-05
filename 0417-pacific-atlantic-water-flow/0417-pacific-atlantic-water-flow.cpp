class Solution {
private:
    int m, n;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int type) {
        queue<pair<int, int>> qu;
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        if(type) {
            for(int i = 0; i < m; i++) {
                ocean[i][0] = true;
                qu.push({i, 0});
            }
            for(int i = 0; i < n; i++) {
                ocean[0][i] = true;
                qu.push({0, i});
            }
        }
        else {
            for(int i = 0; i < m; i++) {
                ocean[i][n - 1] = true;
                qu.push({i, n - 1});
            }
            for(int i = 0; i < n; i++) {
                ocean[m - 1][i] = true;
                qu.push({m - 1, i});
            }
        }
        while(!qu.empty()) {
            auto [row, col] = qu.front();
            ocean[row][col] = true;
            qu.pop();
            for(auto &dir: dirs) {
                int nrow = row + dir[0], ncol = col + dir[1];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !ocean[nrow][ncol] && heights[row][col] <= heights[nrow][ncol]) {
                    qu.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));
        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        dfs(heights, atlantic, 0);
        dfs(heights, pacific, 1);
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};