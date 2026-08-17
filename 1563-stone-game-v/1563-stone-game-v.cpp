class Solution {
public:
    int dp[500][500];
    vector<int> pref;
    int helper(vector<int>& arr, int left, int right) {
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        int res = 0, total = pref[right] - (left > 0 ? pref[left - 1] : 0), suml = 0, sumr = 0;
        for(int i = left; i < right; i++) {
            suml += arr[i];
            sumr = total - suml;
            if(suml == sumr) res = max({res, suml + helper(arr, left, i), sumr + helper(arr, i + 1, right)});
            else if(suml > sumr) res = max(res, sumr + helper(arr, i + 1, right));
            else res = max(res, suml + helper(arr, left, i));
        }
        return dp[left][right] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        pref.resize(stoneValue.size());
        partial_sum(stoneValue.begin(), stoneValue.end(), pref.begin());
        memset(dp, -1, sizeof(dp));
        return helper(stoneValue, 0, stoneValue.size() - 1);
    }
};