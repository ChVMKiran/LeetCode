class Solution {
private:
    bool helper(string &a, string &b) {
        if(a.size() != b.size()) return false;
        int n = a.size(), cnt = 0;
        while(n--) {
            if(a[n] != b[n]) cnt++;
            if(cnt > 1) return false;
        }
        return cnt == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size(), maxInd = 0;
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(helper(words[i], words[j]) && groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    if(dp[maxInd] < dp[i]) maxInd = i;
                    // cout<<dp[maxInd];
                    parent[i] = j;
                }
            }
        }
        // cout<<maxInd;
        while(maxInd != -1) {
            ans.push_back(words[maxInd]);
            maxInd = parent[maxInd];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};