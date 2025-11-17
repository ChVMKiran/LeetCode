class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for(int i = 0; i < len; i++) {
            int ones = ranges::count(strs[i], '1'), zeroes = strs[i].size() - ones;
            for(int j = m; j >= zeroes; j--) {
                for(int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeroes][k - ones]);
                }
            }
        }
        return dp[m][n];
    }
};