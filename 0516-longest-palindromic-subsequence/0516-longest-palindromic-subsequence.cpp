class Solution {
public:
    int lcs(string &s, string &t) {
        int m = s.size(), n = t.size();
        vector<int> dp(n + 1);
        for(int i = 0; i < m; i++) {
            vector<int> ndp(n + 1);
            for(int j = 0; j < n; j++) {
                if(s[i] == t[j]) {
                    ndp[j + 1] = dp[j] + 1;
                }
                else {
                    ndp[j + 1] = max(dp[j + 1], ndp[j]);
                }
            }
            dp = ndp;
        }
        return dp[n];
    }
    int longestPalindromeSubseq(string &s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};