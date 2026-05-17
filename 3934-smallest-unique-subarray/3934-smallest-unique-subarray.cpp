class Solution {
public:
    typedef unsigned long long ull;
    vector<ull> pref, power;

    void buildhash(vector<int>& nums) {
        int n = nums.size();
        ull base = 200000ULL;
        pref.resize(n + 1, 0);
        power.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * base + (nums[i] + 1);
            power[i + 1] = power[i] * base;
        }
    }
    ull getHash(int l, int r) {
        int len = r - l + 1;
        return pref[r + 1] - pref[l] * power[len];
    }
    bool helper(int x, int n) {
        unordered_map<ull, int> ump;
        for (int i = 0; i <= n - x; i++) {
            ump[getHash(i, i + x - 1)]++;
        }
        for (auto& [e, f] : ump) {
            if (f == 1)
                return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        buildhash(nums);
        int n = nums.size(), l = 1, h = n;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (helper(m, n))
                h = m;
            else
                l = m + 1;
        }
        return h;
    }
};