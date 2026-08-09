class Solution {
public:
    int dp[101][101][2];
    vector<int> pref;
    int fun(int ind, int m, int turn, vector<int>& piles) {
        if(ind == piles.size()) return 0;
        if(dp[ind][m][turn] != -1) return dp[ind][m][turn];
        int res = (turn == 0 ? 0: INT_MAX);
        for(int i = ind; i < min((int)piles.size(), ind + 2 * m); i++) {
            int sum = pref[i] - (ind > 0 ? pref[ind - 1] : 0);
            int val = fun(i + 1, max(i - ind + 1, m), !turn, piles);
            if(!turn) res = max(res, val + sum);
            else res = min(res, val);
        }
        return dp[ind][m][turn] = res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(piles.begin(), piles.end(), 0);
        pref.resize(piles.size());
        partial_sum(piles.begin(), piles.end(), pref.begin());
        return fun(0, 1, 0, piles);
    }
};