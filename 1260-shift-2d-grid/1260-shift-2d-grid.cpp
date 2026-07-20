class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (m * n);
        if(!k) return grid;
        auto reverse = [&](int i, int j) {
            while(i < j) {
                swap(grid[i / n][i % n], grid[j / n][j % n]);
                i++, j--;
            }
        };
        reverse(0, m * n - 1);
        reverse(0, k - 1);
        reverse(k, m * n - 1);
        return grid;
    }
};