class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<int> rows(m), cols(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    if (rows[i] > 1 || cols[j] > 1)
                        count++;
                }
            }
        }
        return count;
    }
};