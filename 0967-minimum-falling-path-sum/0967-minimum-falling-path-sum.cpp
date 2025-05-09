class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = matrix[0][0];
        vector<int> prev = matrix[0];
        for(int i = 1; i < n; i++) {
            vector<int> curr = matrix[i];
            curr[0] += min(prev[1], prev[0]);
            curr[n - 1] += min(prev[n - 2], prev[n - 1]);
            if(i == n - 1) ans = min(curr[0], curr[n - 1]);
            for(int j = 1; j < n - 1; j++) {
                curr[j] += min({prev[j - 1], prev[j], prev[j + 1]});
                if(i == n - 1) ans = min(ans, curr[j]);
            }
            prev = curr;
        }
        return ans;
    }
};