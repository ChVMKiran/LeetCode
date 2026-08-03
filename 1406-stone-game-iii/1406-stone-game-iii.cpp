class Solution {
public:
    int dp[50001];
    int helper(vector<int>& stoneValue, int i) {
        if(i == stoneValue.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = stoneValue[i] - helper(stoneValue, i + 1);
        if(i < (int)stoneValue.size() - 1) {
            maxi = max(maxi, stoneValue[i] + stoneValue[i + 1] - helper(stoneValue, i + 2));
        }
        if(i < (int)stoneValue.size() - 2) {
            maxi = max(maxi, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - helper(stoneValue, i + 3));
        }
        return dp[i] = maxi;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int alice = helper(stoneValue, 0);
        if(alice == 0) return "Tie";
        else if(alice > 0) return "Alice";
        return "Bob";
    }
};