class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int dp[201][201] = {0}, mod = 1e9 + 7, n = nums.size();
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            int ndp[201][201] = {0};
            for(int j = 0; j < 201; j++) {
                int first = __gcd(nums[i], j);
                for(int k = 0; k < 201; k++) {
                    auto& val = dp[j][k];
                    if(!val) continue;
                    int second = __gcd(nums[i], k);
                    ndp[first][k] = (0LL + ndp[first][k] + val) % mod;
                    ndp[j][second] = (0LL + ndp[j][second] + val) % mod;
                    ndp[j][k] = (0LL + ndp[j][k] + val) % mod;
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        int ans = 0;
        for(int i = 1; i < 201; i++) ans = (0LL + ans + dp[i][i]) % mod;
        return ans;
    }
};