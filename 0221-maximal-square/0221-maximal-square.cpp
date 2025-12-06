class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] != '1') continue;
                dp[i + 1][j + 1] = 1 + min({dp[i][j], dp[i][j + 1], dp[i + 1][j]});
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans * ans;
    }
};