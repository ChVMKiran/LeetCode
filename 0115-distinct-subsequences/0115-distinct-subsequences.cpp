class Solution {
public:
    int dp[1001][1001];
    int helper(string& s, string& t, int i, int j) {
        if(i == s.size()) {
            return j == t.size();
        }
        if(dp[i][j] != -1) return dp[i][j];
        int cnt = helper(s, t, i + 1, j);
        if(s[i] == t[j]) cnt += helper(s, t, i + 1, j + 1);
        return dp[i][j] = cnt;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return helper(s, t, 0, 0);
    }
};