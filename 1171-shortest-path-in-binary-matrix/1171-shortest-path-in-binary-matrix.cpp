class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, -1));
        if(grid[n - 1][n - 1] || grid[0][0]) return -1;
        queue<pair<int, int>> qu;
        qu.push({0, 0});
        cost[0][0] = 1;
        while(!qu.empty()) {
            auto [row, col] = qu.front();
            qu.pop();
            for(int i = -1; i < 2; i++) {
                for(int j = -1; j < 2; j++) {
                    if(row + i < 0 || col + j < 0 || row + i == n || col + j == n || cost[row + i][col + j] != -1 || grid[row + i][col + j]) continue;
                    cost[row + i][col + j] = cost[row][col] + 1;
                    qu.push({row + i, col + j});
                }
            }
        }
        return cost[n - 1][n - 1];
    }
};