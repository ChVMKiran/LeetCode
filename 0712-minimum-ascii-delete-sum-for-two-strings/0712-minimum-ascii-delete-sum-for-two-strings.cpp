class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + s[i];
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) ans += s[i];
        for(int i = 0; i < n; i++) ans += t[i];
        return ans - dp[m][n] * 2;
    }
};