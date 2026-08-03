class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        for(int i = n - 1; i >= 0; i--) {
            int sum = 0;
            for(int j = 0; j < 3 && i + j < n; j++) {
                sum += stoneValue[i + j];
                dp[i] = max(dp[i], sum - (i + j + 1 < n ? dp[i + j + 1] : 0));
            }
        }
        if(dp[0] == 0) return "Tie";
        else if(dp[0] > 0) return "Alice";
        return "Bob";
    }
};