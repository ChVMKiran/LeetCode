class Solution {
public:
    int n;
    int helper(string &s, int ind, vector<int>& dp, vector<vector<bool>> &mat) {
        if(ind == n) return -1;
        if(dp[ind] != -1) return dp[ind];
        int mini = INT_MAX;
        for(int i = ind; i < n; i++) {
            if(mat[ind][i]) {
                mini = min(1 + helper(s, i + 1, dp, mat), mini);
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        n = s.size();
        vector<vector<bool>> mat(n, vector<bool>(n));
        for(int i = 0; i < n; i++) mat[i][i] = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(s[i] == s[j] && (i - j <= 2 || mat[j + 1][i - 1])) {
                    mat[j][i] = true;
                }
            }
        }
        vector<int> dp(n, -1);
        return helper(s, 0, dp, mat);
    }
};