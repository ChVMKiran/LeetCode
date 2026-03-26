class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0, currSum = 0;
        unordered_map<int, int> ump1;
        unordered_map<int, int> ump2;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                totalSum += grid[i][j];
                ump1[grid[i][j]]++;
                ump2[grid[i][j]]++;
            }
        }
        unordered_map<int, int> ump3;
        unordered_map<int, int> ump4;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                currSum += grid[i][j];
                ump1[grid[i][j]]--;
                ump3[grid[i][j]]++;
            }
            if(currSum * 2 == totalSum) return true;
            else if(currSum * 2 > totalSum) {
                long long val = currSum * 2 - totalSum;
                if(val <= 100000) {
                    if(!i) {
                        if(val == grid[0][0] || val == grid[0][n - 1]) return true;
                    }
                    else if(n == 1) {
                        if(val == grid[0][0] || val == grid[i][0]) return true;
                    }
                    else {
                        if(ump3[val] > 0) return true;
                    }
                }
            }
            else {
                long long val = totalSum - currSum * 2;

                if(val <= 100000) {
                    if(i == m - 2) {
                        if(val == grid[i + 1][0] || val == grid[i + 1][n - 1]) return true;
                    }
                    else if(n == 1) {
                        if(val == grid[i + 1][0] || val == grid[m - 1][0]) return true;
                    }
                    else {
                        if(ump1[val] > 0) return true;
                    }
                }
            }
        }
        // cout<<0;
        currSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                currSum += grid[j][i];
                ump2[grid[j][i]]--;
                ump4[grid[j][i]]++;
            }
            if(currSum * 2 == totalSum) return true;
            else if(currSum * 2 > totalSum) {
                long long val = currSum * 2 - totalSum;

                if(val <= 100000) {
                    if(!i) {
                        if(val == grid[0][0] || val == grid[m - 1][0]) return true;
                    }
                    else if(m == 1) {
                        if(val == grid[0][0] || val == grid[0][i]) return true;
                    }
                    else {
                        if(ump4[val] > 0) return true;
                    }
                }
            }
            else {
                long long val = totalSum - currSum * 2;

                if(val <= 100000) {
                    if(i == n - 2) {
                        if(val == grid[0][i + 1] || val == grid[m - 1][i + 1]) return true;
                    }
                    else if(m == 1) {
                        if(val == grid[0][i + 1] || val == grid[0][n - 1]) return true;
                    }
                    else {
                        if(ump2[val] > 0) return true;
                    }
                }
            }
        }
        return false;
    }
};