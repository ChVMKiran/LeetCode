class Solution {
public:
    using ll = long long;
    ll dp[16][100][100][2];
    string s;
    ll helper(int ind, int even, int odd, int tight) {
        if(ind == s.size()) return even == odd;
        if(dp[ind][even][odd][tight] != -1) return dp[ind][even][odd][tight];
        int limit = (tight ? s[ind] - '0' : 9);
        ll ans = 0;
        for(int i = 0; i <= limit; i++) {
            ll newEven = even, newOdd = odd;
            if(ind % 2 == 0) newEven += i;
            else newOdd += i;
            ll val = helper(ind + 1, newEven, newOdd, (tight && i == limit ? 1: 0));
            ans += val;
        }
        return dp[ind][even][odd][tight] = ans;
    }
    ll solve(ll num) {
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0, 1);
    }
    ll countBalanced(ll low, ll high) {
        return solve(high) - solve(low - 1);
    }
};