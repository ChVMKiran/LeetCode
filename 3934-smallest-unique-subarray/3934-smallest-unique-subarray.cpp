struct RollingHash {
    using ull = unsigned long long;

    static const ull MOD = 1000000007ULL;
    static const ull BASE = 911382323ULL;

    vector<ull> pref, power, invPower;

    ull modexp(ull a, ull e) {
        ull r = 1;
        while (e) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    RollingHash(const vector<int>& a) {
        int n = a.size();

        pref.resize(n + 1, 0);
        power.resize(n + 1, 1);
        invPower.resize(n + 1, 1);

        ull invBase = modexp(BASE, MOD - 2);

        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
            invPower[i] = (invPower[i - 1] * invBase) % MOD;
        }

        for (int i = 0; i < n; i++) {
            pref[i + 1] =
                (pref[i] + (ull)a[i] * power[i]) % MOD;
        }
    }

    ull getHash(int l, int r) {
        ull h = (pref[r + 1] + MOD - pref[l]) % MOD;
        h = (h * invPower[l]) % MOD;
        return h;
    }
};

class Solution {
public:
    bool helper(RollingHash& rh, int x, int n) {
        unordered_map<long long, int> ump;
        for(int i = 0; i <= n - x; i++) {
            ump[rh.getHash(i, i + x - 1)]++;
        }
        for(auto& [e, f]: ump) {
            if(f == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        RollingHash rh(nums);
        int n = nums.size(), l = 1, h = n;
        while(l < h) {
            int m = l + (h - l) / 2;
            if(helper(rh, m, n)) h = m;
            else l = m + 1;
        }
        return h;
    }
};