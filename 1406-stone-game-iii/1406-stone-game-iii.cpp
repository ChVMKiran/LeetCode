class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4] = {0, 0, 0, 0};
        for(int i = n - 1; i >= 0; i--) {
            int j = i & 3; // i % 4
            dp[j] = stoneValue[i] - dp[(i + 1) % 4];
            if(i < n - 1) dp[j] = max(dp[j], stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 4]);
            if(i < n - 2) dp[j] = max(dp[j], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 4]);
        }
        if(dp[0] == 0) return "Tie";
        else if(dp[0] > 0) return "Alice";
        return "Bob";
    }
};