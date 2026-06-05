class Solution {
public:
    using ll = long long;
    pair<ll, ll> dp[16][11][11][2];
    string s;

    pair<ll, ll> f(int ind, int last, int secondLast, int tight) {
        if(ind == s.size()) return {0, 1};
        if (dp[ind][last][secondLast][tight].first != -1)
            return dp[ind][last][secondLast][tight];

        int lim = tight ? s[ind] - '0' : 9;
        ll waves = 0, ways = 0;
        for(int i = 0; i <= lim; i++) {
            int newTight = (tight == 1 && i == s[ind] - '0') ? 1 : 0;
            int curr = (last == 10 && secondLast == 10 && i == 0) ? 10 : i;
            auto[subWaves, subWays] = f(ind + 1, curr, last, newTight);
            bool wave = false;
            if(last != 10 && secondLast != 10) {
                wave =
                    (last > secondLast && last > i) ||
                    (last < secondLast && last < i);
            }
            waves += subWaves + (wave ? subWays : 0);
            ways += subWays;
        }
        return dp[ind][last][secondLast][tight] = {waves, ways};
    }

    ll totalWaviness(ll num1, ll num2) {
        memset(dp, -1, sizeof(dp));
        s = to_string(num1 - 1);
        ll val1 = f(0, 10, 10, 1).first;

        s = to_string(num2);
        memset(dp, -1, sizeof(dp));
        ll val2 = f(0, 10, 10, 1).first;

        return val2 - val1;
    }
};