class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = n - 1; i > 0; i--) {
            int row = 0, col = i, ind = 0;
            vector<int> vec(min(m - row, n - i));
            while(row < m && col < n) {
                vec[ind++] = grid[row][col];
                row++, col++;
            }
            sort(vec.begin(),vec.end());
            row = 0, col = i, ind = 0;
            while(row < m && col < n) {
                grid[row][col] = vec[ind++];
                row++, col++;
            }
        }
        for(int i = 0; i < n; i++) {
            int row = i, col = 0, ind = 0;
            vector<int> vec(min(m - row, n - i));
            while(row < m && col < n) {
                vec[ind++] = grid[row][col];
                row++, col++;
            }
            sort(vec.begin(),vec.end(), greater<int>());
            col = 0, row = i, ind = 0;
            while(row < m && col < n) {
                grid[row][col] = vec[ind++];
                row++, col++;
            }
        }
        return grid;
    }
};