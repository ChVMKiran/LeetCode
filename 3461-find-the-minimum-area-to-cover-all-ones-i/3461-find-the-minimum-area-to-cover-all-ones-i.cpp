class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int xStart = -1, xEnd = -1, yStart = -1, yEnd = -1;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    if(xStart == -1) xStart = i;
                    xEnd = i;
                    if(yStart == -1 || yStart > j) yStart = j;
                    yEnd = max(yEnd, j);
                }
            }
        }
        return (xEnd - xStart + 1) * (yEnd - yStart + 1);
    }
};