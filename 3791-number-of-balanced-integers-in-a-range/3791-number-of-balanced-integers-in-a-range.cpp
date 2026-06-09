class Solution {
public:
    using ll = long long;
    ll dp[16][200][2];
    string s;
    ll helper(int ind, int diff, int tight) {
        if(diff < 0 || diff >= 200) return 0;
        if(ind == s.size()) return diff == 100;
        if(dp[ind][diff][tight] != -1) return dp[ind][diff][tight];
        int limit = (tight ? s[ind] - '0' : 9);
        ll ans = 0;
        for(int i = 0; i <= limit; i++) {
            ans += helper(ind + 1, diff + (ind % 2 ? i : -i), (tight && i == limit ? 1: 0));
        }
        return dp[ind][diff][tight] = ans;
    }
    ll solve(ll num) {
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return helper(0, 100, 1);
    }
    ll countBalanced(ll low, ll high) {
        return solve(high) - solve(low - 1);
    }
};