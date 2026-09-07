class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        int last[26]{};
        int val = 0;
        for(int i = 0; i < n; i++) {
            int cur = val;
            val = (1LL + val * 2 - last[s[i] - 'a'] + MOD) % MOD;
            last[s[i] - 'a'] = cur + 1;
        }
        return val;
    }
};