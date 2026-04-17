class Solution {
public:
    int lcs(string &s, string &t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string &s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};