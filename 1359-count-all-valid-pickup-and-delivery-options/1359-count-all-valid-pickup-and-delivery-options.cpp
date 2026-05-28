class Solution {
public:
    int countOrders(int n) {
        int ans = 1, mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) {
            ans = ((long long)ans * (2 * i - 1) * i) % mod;
        }
        return ans;
    }
};