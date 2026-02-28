class Solution {
public:
    using ll = long long;
    int concatenatedBinary(int n) {
        ll ans = 0, len = 0, mod = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0) len++;
            ans = ((ans<<len) | i) % mod;
        }
        return ans;
    }
};