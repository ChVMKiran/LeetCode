class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(ust.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};