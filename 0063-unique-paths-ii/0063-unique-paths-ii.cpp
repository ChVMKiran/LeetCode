class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n);
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i]) flag = true;
            prev[i] = flag ? 0 : 1;
        }
        for(int i = 1; i < m; i++) {
            vector<int> curr(n);
            curr[0] = 1;
            if(obstacleGrid[i][0] || prev[0] == 0) curr[0] = 0; 
            for(int j = 1; j < n; j++) {
                if(!obstacleGrid[i][j]) curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};