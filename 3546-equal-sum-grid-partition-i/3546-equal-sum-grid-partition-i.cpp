class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0, currSum = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                currSum += grid[i][j];
            }
            if(currSum * 2 == totalSum) return true;
        }
        currSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                currSum += grid[j][i];
            }
            if(currSum * 2 == totalSum) return true;
        }
        return false;
    }
};